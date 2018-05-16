#include<windows.h>
#include<assert.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	srand((unsigned int)time(NULL));//设置时间戳种子
	struct Game *pGame = CreateGame();
	StartGame(pGame);//开始游戏
	DestoryGame(pGame);//销毁游戏资源
	system("pause");
	return 0;
}

int speed = 300;
struct UI
{
	int margintop;//墙离上窗口的距离
	int marginleft;//墙离左窗口的距离

	int gamewidth;//游戏里宽度上显示块个数
	int gameheight;//游戏里高度上显示块个数

	int windowWidth;//整个窗口的宽度
	int windowHeight;//整个窗口的高度

	char *snackblock;//蛇的显示块
	char *foodblock;//食物的显示块
	char *wallblock;//墙的显示块

	int blockwidth;//一个显示块的宽度（蛇，食物，墙的显示块的宽度相同，否则对不齐）
};
struct Position//游戏区域坐标
{
	int x;
	int y;
};
struct Node//链表结点
{
	struct Position position; //一个结点用坐标存,那么就要再定义一个坐标结构体
	struct Node *pnext;//下一个结点
};
enum Direction//定义蛇的方向
{
	UP,//上
	DOWN,//下
	LEFT,//左
	RIGHT//右
};
struct Snack//蛇结构体
{
	enum Directon direction;//蛇的方向
	struct Node *pbody;//蛇的身体  
};
struct Game//游戏
{
	int width;//游戏区域的宽度，不包括墙，对应到UI宽度上字符的个数
	int height;//游戏区域的高度，不包括墙，对应到UI高度上对应字符的个数
	int socre;//当前得分
	int scoreprefood;//每个食物得分
	struct Snack snack;//蛇
	struct Position foodposition;//当前食物坐标
};
enum ExitStatus
{
	KILLED_BY_WALL,
	KILLED_BY_SELF,
	QUIT    
};
struct UI* UIInitalize(int width, int height);//初始化界面
void UIDisplayWizard(const struct UI *pUI);//显示游戏导向
void UIDisplayGameWindow(const struct UI*pUI, int score, int scorePerfood);
//显示游戏整体，包括墙、右边的信息，不包括蛇和食物的显示
void UIDisplyFoodAtXY(const struct UI *pUI, int x, int y);//在x y处显示食物，x,y都是字符个数
void UIDisplySnackBlockAtXY(const struct UI *pUI, int x, int y);
//在x y处显示蛇的结点，x,y都是字符个数
void UICleanBlockAtXY(const struct UI *pUI, int x, int y);//清空x y处的显示块，x,y是字符个数
void UIDisplayScore(const struct UI *pUI, int score, int scorePrefood);//显示分数
void UIShowMessage(const struct UI *pUI, const char *meaasge);//在游戏区域居中显示游戏退出消息
void UIDeinitialize(struct UI * pUI);//销毁UI
void InitSnake(struct Snack *psnake);//初始化蛇结构体
void GenerateFood(struct Game *pGame);//设置食物
void HandleDirective(struct Game *pGame);//方向的处理
struct Position GetNextPosition(struct Snack * psnake);//得到下一个坐标
int IsWillEatFood(struct Position foodposition, struct Position nextposition);//是否吃到食物
int IsKilledByWall(struct Snack *snake, int wideth, int height);//是否撞到墙
int IsOverlapSnake(int x, int y, struct Snack *psnake);//食物是否和蛇结点重复
void GrowAndDisplay(struct Snack *psnake, struct Position foodposition, struct UI *pUI); //增加蛇的结点并且打印增加蛇的结点
void MoveAndDisplay(struct Snack *psnake, struct Position nextposition, struct UI *pUI);//蛇移动并打印
int IsSnakeAlive(struct Game* pGame, enum ExitStatus * exitstatus);//蛇是否存活
int IsKilledBySelf(struct Node *phead, struct Snack *snake);//被自己撞死
void _Pause();//暂停
void DisplaySnake(struct UI* pUI, struct Snack *psnack);//显示整个蛇
void ControlSpeed(struct UI *pUI, struct Game *pGame);//控制速度

struct UI* UIInitalize(int width, int height)//初始化界面 width.height指游戏区域字符个数
{
	const int left = 3;//左边缘宽度
	const int top = 4;//上边缘宽度
	const int descwidth = 50;//指墙右边的宽度
	const int descheight = 3;//指墙下的高度
	struct UI *pUI = (struct UI*)malloc(sizeof(struct UI));
	pUI->margintop = top;
	pUI->marginleft = left;
	pUI->gamewidth = width;//
	pUI->gameheight = height;
	pUI->snackblock = pUI->wallblock = pUI->foodblock = "█";
	pUI->blockwidth = strlen(pUI->snackblock);
	pUI->windowHeight = top + (2 + height) * 1 + descheight;//窗口高度
	pUI->windowWidth = left + (2 + width) *(pUI->blockwidth) + descwidth;//窗口宽度

	system("mode con cols=100 lines=40");

	return pUI;
}
static void SetPos(int x, int y)//光标移到x,y处，注意，这里是相对整个屏幕的，而不是游戏区域
{
	COORD position = { x,y };//COORD是结构体
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, position);
}
static void DisplayWall(const struct UI *pUI)//打印墙
{
	int i = 0;
	int x, y;
	//上
	for (i = 0; i < pUI->gamewidth + 2; i++)
	{
		x = pUI->marginleft + pUI->blockwidth*i;//第一个光标就是左边缘后
		y = pUI->margintop;//墙的上边框高度一样
		SetPos(x, y);
		printf("%s", pUI->wallblock);
	}
	//下
	for (i = 0; i < pUI->gamewidth + 2; i++)
	{
		x = pUI->marginleft + pUI->blockwidth*i;//第一个光标就是左边缘后
		y = pUI->margintop + (1 + pUI->gameheight) * 1;//加1是因为有墙的上边框，*1是字符的高度
		SetPos(x, y);
		printf("%s", pUI->wallblock);
	}
	//左
	for (i = 0; i < pUI->gameheight + 2; i++)
	{
		x = pUI->marginleft;//左边框宽度一样
		y = pUI->margintop + i;
		SetPos(x, y);
		printf("%s", pUI->wallblock);
	}
	//右
	for (i = 0; i < pUI->gameheight + 2; i++)
	{
		x = pUI->marginleft + (1 + pUI->gamewidth)*(pUI->blockwidth);//加1是因为除了游戏区域还有墙
		y = pUI->margintop + i;
		SetPos(x, y);
		printf("%s", pUI->wallblock);
	}
	printf("\n");
}
static void DisplyDesc(const struct UI *pUI)//显示右侧信息
{
	int left = pUI->marginleft + (2 + pUI->gamewidth)*(pUI->blockwidth) + 2;//先找到右侧信息输出位置
	const char *message[] = {
		"不能穿墙，不能咬到自己。",
		"用 ↑.↓.←.→分别控制蛇的移动。",
		"F1为加速，F2为减速。",
		"ESC退出游戏，SPACE暂停游戏。"
	};
	int i = 0;
	for (i = 0; i < sizeof(message) / sizeof(char *)/*sizeof(message[0])*/; i++)
	{
		SetPos(left, pUI->margintop + 11 + i);
		printf("%s", message[i]);
	}
	printf("\n");
}
void UIDisplayWizard(const struct UI *pUI)//显示游戏导向
{
	int i = 0;
	const char *message[] = {
		"欢迎来到贪吃蛇小游戏",
		"用 ↑.↓.←.→分别控制蛇的移动，F1为加速，F2为减速。",
		"加速将能得到更高的分数。"
	};
	for (i = 0; i < sizeof(message) / sizeof(char *); i++)
	{
		SetPos((pUI->windowWidth / 2) - (strlen(message[i]) / 2), pUI->windowHeight / 2 + i);//置光标函数
		printf("%s\n", message[i]);
	}
	system("pause");
	system("cls");
}
static void ResetCursorPosition(const struct UI *pUI)//重置光标到屏幕下方，只要是为了显示的美观
{
	SetPos(0, pUI->windowHeight - 1);
}
void UIDisplyFoodAtXY(const struct UI *pUI, int x, int y)//在x y处显示食物，x,y都是字符个数
{
	CoordinatePosATXY(pUI, x, y);//将个数转为宽度
	printf(pUI->foodblock);
	ResetCursorPosition(pUI);
}
void UIDisplySnackBlockAtXY(const struct UI *pUI, int x, int y)
//在x y处显示蛇的结点，x,y都是字符个数
{
	CoordinatePosATXY(pUI, x, y);//将个数转为宽度
	printf(pUI->snackblock);
	ResetCursorPosition(pUI);
}
void UICleanBlockAtXY(const struct UI *pUI, int x, int y)//清空x y处的显示块，x,y是字符个数
{
	CoordinatePosATXY(pUI, x, y);//将个数转为宽度
	int i = 0;
	for (i = 0; i < pUI->blockwidth; i++)
	{
		printf(" ");
	}
	ResetCursorPosition(pUI);
}
void UIDisplayScore(const struct UI *pUI, int score, int scorePrefood)//显示分数
{
	int left = pUI->marginleft + (2 + pUI->gamewidth)*(pUI->blockwidth) + 2;//先找到右侧信息输出位置
	SetPos(left, pUI->margintop + 10);
	printf("得分：%d,每个食物得分：%d", score, scorePrefood);
	ResetCursorPosition(pUI);
}
void UIDisplayGameWindow(const struct UI*pUI, int score, int scorePerfood)//显示游戏整体
{
	DisplayWall(pUI);//显示墙
	UIDisplayScore(pUI, score, scorePerfood);//显示分数
	DisplyDesc(pUI);//显示右侧信息
	ResetCursorPosition(pUI);
}

void UIShowMessage(const struct UI *pUI, const char *message)//在游戏区域居中显示游戏退出消息
{
	//左填充宽度+1（左边界个数）*每个字符宽度+游戏区域宽度/2*每个字符宽度-字符串宽度/2
	int left = pUI->marginleft + 1 * pUI->blockwidth +
		pUI->gamewidth / 2 * pUI->blockwidth - strlen(message) / 2;
	SetPos(left, pUI->margintop + 1 + pUI->gameheight / 2);
	printf("%s\n", message);
	ResetCursorPosition(pUI);
}
void UIDeinitialize(struct UI *pUI)//销毁UI
{
	free(pUI);
}
static void CoordinatePosATXY(const struct UI *pUI, int x, int y)//将字符个数转化为最后字符宽度
{
	SetPos(pUI->marginleft + (1 + x)*pUI->blockwidth, pUI->margintop + 1 + y);
}

struct Game *CreateGame()//创建并初始化游戏
{
	struct Game *pGame = (struct Game *)malloc(sizeof(struct Game));
	assert(pGame);
	pGame->width = 28;
	pGame->height = 27;
	pGame->socre = 0;
	pGame->scoreprefood = 10;
	InitSnake(&(pGame->snack));//初始化蛇结构体
	GenerateFood(pGame);//放食物
	return pGame;
}
void InitSnake(struct Snack * psnake)//初始化蛇结构体
{
	const int length = 3;//蛇最开始有三个结点
	const int x = 5;
	const int y = 5;
	int i = 0;
	struct Node*pNode;
	psnake->direction = RIGHT;
	psnake->pbody = NULL;
	for (i = 0; i < length; i++)
	{
		pNode = (struct Node*)malloc(sizeof(struct Node));
		pNode->position.x = x + i;
		pNode->position.y = y;
		pNode->pnext = psnake->pbody;// (5,5)<-(6,5)<-(7,5) (7,5）是pbody
		psnake->pbody = pNode;
	}
}
void GenerateFood(struct Game *pGame)//放置食物
{
	int x, y;
	do
	{
		x = rand() % pGame->width;
		y = rand() % pGame->height;
	} while (IsOverlapSnake(x, y, &pGame->snack));//当不重合时退出循环
	pGame->foodposition.x = x;
	pGame->foodposition.y = y;
}
int IsOverlapSnake(int x, int y, struct Snack *psnake)
{
	struct Node*pNode;
	for (pNode = psnake->pbody; pNode != NULL; pNode = pNode->pnext)
	{
		if (pNode->position.x == x&&pNode->position.y == y)
			return 1;//重合是1
	}
	return 0;//不重合是0
}
void StartGame(struct Game *pGame)//开始游戏
{
	struct UI *pUI = UIInitalize(pGame->width, pGame->height);//初始化界面
	enum ExitStatus exitstatus = QUIT;
	UIDisplayWizard(pUI);//显示游戏导向

	UIDisplayGameWindow(pUI, pGame->socre, pGame->scoreprefood);//显示游戏整体
	DisplaySnake(pUI, &pGame->snack);
	UIDisplyFoodAtXY(pUI, pGame->foodposition.x, pGame->foodposition.y);//在x y处显示食物，x,y都是字符个数
	while (1)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			break;
		}
		else if (GetAsyncKeyState(VK_SPACE))
			_Pause();
		HandleDirective(pGame);
		struct Position nextposition = GetNextPosition(&pGame->snack);
		if (IsWillEatFood(pGame->foodposition, nextposition))//吃到食物
		{
			pGame->socre = pGame->socre + pGame->scoreprefood;
			UIDisplayScore(pUI, pGame->socre, pGame->scoreprefood);//显示分数
			GrowAndDisplay(&pGame->snack, pGame->foodposition, pUI);// 增加蛇的结点并且打印增加蛇的结点
			GenerateFood(pGame);//设置食物
			UIDisplyFoodAtXY(pUI, pGame->foodposition.x, pGame->foodposition.y);//在x y处显示食物，x,y都是字符个数
		}
		else
		{
			MoveAndDisplay(&pGame->snack, nextposition, pUI);
		}

		if (IsSnakeAlive(pGame, &exitstatus))
		{
			break;  //蛇撞墙或者撞到自己
		}
		ControlSpeed(pUI, pGame);//控制速度		
	}
	char *massage[3];
	massage[QUIT] = "游戏结束";
	massage[KILLED_BY_WALL] = "游戏结束，撞到墙";
	massage[KILLED_BY_SELF] = "游戏结束，撞到自己";
	UIShowMessage(pUI, massage[exitstatus]);
	UIDeinitialize(pUI);//销毁UI
 }
void HandleDirective(struct Game *pGame)//方向的处理
{
	if (GetAsyncKeyState(VK_UP) && (pGame->snack.direction != DOWN))
		pGame->snack.direction = UP;
	else if (GetAsyncKeyState(VK_DOWN) && pGame->snack.direction != UP)
		pGame->snack.direction = DOWN;
	else if (GetAsyncKeyState(VK_LEFT) && pGame->snack.direction != RIGHT)
		pGame->snack.direction = LEFT;
	else if (GetAsyncKeyState(VK_RIGHT) && pGame->snack.direction != LEFT)
		pGame->snack.direction = RIGHT;		
}
struct Position GetNextPosition(struct Snack * psnake)//得到下一个坐标
{
	int nextX=psnake->pbody ->position .x ;
	int nextY = psnake->pbody->position.y;
	switch (psnake->direction)
	{
	case UP:
		nextX = nextX;
		nextY -= 1;
		break;
	case DOWN:
		nextX = nextX;
		nextY += 1;
		break;
	case RIGHT:
		nextX += 1;
		nextY = nextY;
		break;
	case LEFT:
		nextX -= 1;
		nextY = nextY;
		break;
	}
	struct Position nextposition = { nextX,nextY };
	return nextposition;	
}
int IsWillEatFood(struct Position foodposition, struct Position nextposition)
{    //是否吃到食物
	if (foodposition.x == nextposition.x &&foodposition.y == nextposition.y )
		return 1;
	return 0;
}
void GrowAndDisplay(struct Snack *psnake, struct Position foodposition, struct UI *pUI)
{    //增加蛇的结点并且打印增加蛇的结点
	struct Node *pNode = (struct Node *)malloc(sizeof(struct Node));
	pNode->position.x = foodposition.x;
	pNode->position.y = foodposition.y;
	pNode->pnext = psnake->pbody;
	psnake->pbody = pNode;
	UIDisplySnackBlockAtXY(pUI, foodposition.x, foodposition.y);
	//在x y处显示蛇的结点，x,y都是字符个数
}
void MoveAndDisplay(struct Snack *psnake, struct Position nextposition, struct UI *pUI)//蛇移动并打印
{
	struct Node *pNode = (struct Node *)malloc(sizeof(struct Node));
	pNode->position.x = nextposition.x;
	pNode->position.y = nextposition.y;
	pNode->pnext = psnake->pbody;
	psnake->pbody = pNode;
	UIDisplySnackBlockAtXY(pUI, nextposition.x, nextposition.y);
	struct Node *cur = psnake->pbody;
	//尾删
	while (cur->pnext->pnext)
	{
		cur = cur->pnext;
	}
	struct Node *tail=cur->pnext;
	UICleanBlockAtXY(pUI, tail->position.x, tail->position.y); 
	free(tail);
	cur->pnext = NULL;
}

int IsSnakeAlive(struct Game* pGame, enum ExitStatus * exitstatus)//蛇是否存活
{
	struct Node *phead = pGame->snack.pbody;
	if (IsKilledByWall(&pGame->snack, pGame->width, pGame->height))//被墙撞到
	{
		*exitstatus = KILLED_BY_WALL;
		return 1;
	}
	if (IsKilledBySelf(phead, &pGame->snack ))
	{
		*exitstatus = KILLED_BY_SELF;
		return 1;
	}
	return 0;
}

int IsKilledByWall(struct Snack *snake,int wideth,int height)
{
	if (snake->pbody->position.x >= 0 && snake->pbody->position.x < wideth
		&&snake->pbody->position.y >= 0 && snake->pbody->position.y < height)
		return 0;
	return 1;//被墙撞到
}
int IsKilledBySelf(struct Node *phead, struct Snack *snake)
{
	//前提是蛇至少有两个结点 
	struct Node *pNode=snake->pbody ->pnext ;
	while (pNode)
	{
		if (pNode->position.x == phead->position.x&&
			pNode->position.y == phead->position.y)
			return 1;//被自己撞到
		pNode = pNode->pnext;
	}
	return 0;
}
void DestoryGame(struct Game *pGame)//销毁游戏资源
{
	struct Node *pnode=pGame->snack .pbody , *pnext;
	while (pnode)
	{
		pnext = pnode->pnext;
		free(pnode);
		pnode = pnext;
	}
	free(pGame);
}
void _Pause()
{
	while (1)
	{
		Sleep(300);//停住
		if (GetAsyncKeyState(VK_SPACE))//再按空格就退出循环，继续游戏
			break;
	}
}
void DisplaySnake(struct UI* pUI, struct Snack *psnack)//显示整个蛇
{
	struct Node *pNode=psnack->pbody ;
	if (psnack->pbody == NULL)
		return;
	while (pNode)
	{
		UIDisplySnackBlockAtXY(pUI,pNode->position .x,pNode->position .y );
		//在x y处显示蛇的结点，x,y都是字符个数
		pNode = pNode->pnext;
	}
}
void ControlSpeed(struct UI *pUI, struct Game *pGame)
{
	if (GetAsyncKeyState(VK_F1))//加速
	{
		if (pGame->scoreprefood < 40)
		{
			if (pGame->scoreprefood < 20)
			{
				pGame->scoreprefood += 5;
			}
			if (pGame->scoreprefood >= 20)
			{
				pGame->scoreprefood += 10;
			}
			speed = speed - 50;
			UIDisplayScore(pUI, pGame->socre, pGame->scoreprefood);//显示分数
		}
	}
	if (GetAsyncKeyState(VK_F2))//减速
	{
		if (pGame->scoreprefood > 10)//小于10无法减速
		{
			pGame->scoreprefood -= 10;
			speed = speed + 50;
			UIDisplayScore(pUI, pGame->socre, pGame->scoreprefood);//显示分数
		}
	}
	Sleep(speed);
}