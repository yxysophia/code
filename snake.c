#include<windows.h>
#include<assert.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	srand((unsigned int)time(NULL));//����ʱ�������
	struct Game *pGame = CreateGame();
	StartGame(pGame);//��ʼ��Ϸ
	DestoryGame(pGame);//������Ϸ��Դ
	system("pause");
	return 0;
}

int speed = 300;
struct UI
{
	int margintop;//ǽ���ϴ��ڵľ���
	int marginleft;//ǽ���󴰿ڵľ���

	int gamewidth;//��Ϸ��������ʾ�����
	int gameheight;//��Ϸ��߶�����ʾ�����

	int windowWidth;//�������ڵĿ��
	int windowHeight;//�������ڵĸ߶�

	char *snackblock;//�ߵ���ʾ��
	char *foodblock;//ʳ�����ʾ��
	char *wallblock;//ǽ����ʾ��

	int blockwidth;//һ����ʾ��Ŀ�ȣ��ߣ�ʳ�ǽ����ʾ��Ŀ����ͬ������Բ��룩
};
struct Position//��Ϸ��������
{
	int x;
	int y;
};
struct Node//������
{
	struct Position position; //һ������������,��ô��Ҫ�ٶ���һ������ṹ��
	struct Node *pnext;//��һ�����
};
enum Direction//�����ߵķ���
{
	UP,//��
	DOWN,//��
	LEFT,//��
	RIGHT//��
};
struct Snack//�߽ṹ��
{
	enum Directon direction;//�ߵķ���
	struct Node *pbody;//�ߵ�����  
};
struct Game//��Ϸ
{
	int width;//��Ϸ����Ŀ�ȣ�������ǽ����Ӧ��UI������ַ��ĸ���
	int height;//��Ϸ����ĸ߶ȣ�������ǽ����Ӧ��UI�߶��϶�Ӧ�ַ��ĸ���
	int socre;//��ǰ�÷�
	int scoreprefood;//ÿ��ʳ��÷�
	struct Snack snack;//��
	struct Position foodposition;//��ǰʳ������
};
enum ExitStatus
{
	KILLED_BY_WALL,
	KILLED_BY_SELF,
	QUIT    
};
struct UI* UIInitalize(int width, int height);//��ʼ������
void UIDisplayWizard(const struct UI *pUI);//��ʾ��Ϸ����
void UIDisplayGameWindow(const struct UI*pUI, int score, int scorePerfood);
//��ʾ��Ϸ���壬����ǽ���ұߵ���Ϣ���������ߺ�ʳ�����ʾ
void UIDisplyFoodAtXY(const struct UI *pUI, int x, int y);//��x y����ʾʳ�x,y�����ַ�����
void UIDisplySnackBlockAtXY(const struct UI *pUI, int x, int y);
//��x y����ʾ�ߵĽ�㣬x,y�����ַ�����
void UICleanBlockAtXY(const struct UI *pUI, int x, int y);//���x y������ʾ�飬x,y���ַ�����
void UIDisplayScore(const struct UI *pUI, int score, int scorePrefood);//��ʾ����
void UIShowMessage(const struct UI *pUI, const char *meaasge);//����Ϸ���������ʾ��Ϸ�˳���Ϣ
void UIDeinitialize(struct UI * pUI);//����UI
void InitSnake(struct Snack *psnake);//��ʼ���߽ṹ��
void GenerateFood(struct Game *pGame);//����ʳ��
void HandleDirective(struct Game *pGame);//����Ĵ���
struct Position GetNextPosition(struct Snack * psnake);//�õ���һ������
int IsWillEatFood(struct Position foodposition, struct Position nextposition);//�Ƿ�Ե�ʳ��
int IsKilledByWall(struct Snack *snake, int wideth, int height);//�Ƿ�ײ��ǽ
int IsOverlapSnake(int x, int y, struct Snack *psnake);//ʳ���Ƿ���߽���ظ�
void GrowAndDisplay(struct Snack *psnake, struct Position foodposition, struct UI *pUI); //�����ߵĽ�㲢�Ҵ�ӡ�����ߵĽ��
void MoveAndDisplay(struct Snack *psnake, struct Position nextposition, struct UI *pUI);//���ƶ�����ӡ
int IsSnakeAlive(struct Game* pGame, enum ExitStatus * exitstatus);//���Ƿ���
int IsKilledBySelf(struct Node *phead, struct Snack *snake);//���Լ�ײ��
void _Pause();//��ͣ
void DisplaySnake(struct UI* pUI, struct Snack *psnack);//��ʾ������
void ControlSpeed(struct UI *pUI, struct Game *pGame);//�����ٶ�

struct UI* UIInitalize(int width, int height)//��ʼ������ width.heightָ��Ϸ�����ַ�����
{
	const int left = 3;//���Ե���
	const int top = 4;//�ϱ�Ե���
	const int descwidth = 50;//ָǽ�ұߵĿ��
	const int descheight = 3;//ָǽ�µĸ߶�
	struct UI *pUI = (struct UI*)malloc(sizeof(struct UI));
	pUI->margintop = top;
	pUI->marginleft = left;
	pUI->gamewidth = width;//
	pUI->gameheight = height;
	pUI->snackblock = pUI->wallblock = pUI->foodblock = "��";
	pUI->blockwidth = strlen(pUI->snackblock);
	pUI->windowHeight = top + (2 + height) * 1 + descheight;//���ڸ߶�
	pUI->windowWidth = left + (2 + width) *(pUI->blockwidth) + descwidth;//���ڿ��

	system("mode con cols=100 lines=40");

	return pUI;
}
static void SetPos(int x, int y)//����Ƶ�x,y����ע�⣬���������������Ļ�ģ���������Ϸ����
{
	COORD position = { x,y };//COORD�ǽṹ��
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, position);
}
static void DisplayWall(const struct UI *pUI)//��ӡǽ
{
	int i = 0;
	int x, y;
	//��
	for (i = 0; i < pUI->gamewidth + 2; i++)
	{
		x = pUI->marginleft + pUI->blockwidth*i;//��һ�����������Ե��
		y = pUI->margintop;//ǽ���ϱ߿�߶�һ��
		SetPos(x, y);
		printf("%s", pUI->wallblock);
	}
	//��
	for (i = 0; i < pUI->gamewidth + 2; i++)
	{
		x = pUI->marginleft + pUI->blockwidth*i;//��һ�����������Ե��
		y = pUI->margintop + (1 + pUI->gameheight) * 1;//��1����Ϊ��ǽ���ϱ߿�*1���ַ��ĸ߶�
		SetPos(x, y);
		printf("%s", pUI->wallblock);
	}
	//��
	for (i = 0; i < pUI->gameheight + 2; i++)
	{
		x = pUI->marginleft;//��߿���һ��
		y = pUI->margintop + i;
		SetPos(x, y);
		printf("%s", pUI->wallblock);
	}
	//��
	for (i = 0; i < pUI->gameheight + 2; i++)
	{
		x = pUI->marginleft + (1 + pUI->gamewidth)*(pUI->blockwidth);//��1����Ϊ������Ϸ������ǽ
		y = pUI->margintop + i;
		SetPos(x, y);
		printf("%s", pUI->wallblock);
	}
	printf("\n");
}
static void DisplyDesc(const struct UI *pUI)//��ʾ�Ҳ���Ϣ
{
	int left = pUI->marginleft + (2 + pUI->gamewidth)*(pUI->blockwidth) + 2;//���ҵ��Ҳ���Ϣ���λ��
	const char *message[] = {
		"���ܴ�ǽ������ҧ���Լ���",
		"�� ��.��.��.���ֱ�����ߵ��ƶ���",
		"F1Ϊ���٣�F2Ϊ���١�",
		"ESC�˳���Ϸ��SPACE��ͣ��Ϸ��"
	};
	int i = 0;
	for (i = 0; i < sizeof(message) / sizeof(char *)/*sizeof(message[0])*/; i++)
	{
		SetPos(left, pUI->margintop + 11 + i);
		printf("%s", message[i]);
	}
	printf("\n");
}
void UIDisplayWizard(const struct UI *pUI)//��ʾ��Ϸ����
{
	int i = 0;
	const char *message[] = {
		"��ӭ����̰����С��Ϸ",
		"�� ��.��.��.���ֱ�����ߵ��ƶ���F1Ϊ���٣�F2Ϊ���١�",
		"���ٽ��ܵõ����ߵķ�����"
	};
	for (i = 0; i < sizeof(message) / sizeof(char *); i++)
	{
		SetPos((pUI->windowWidth / 2) - (strlen(message[i]) / 2), pUI->windowHeight / 2 + i);//�ù�꺯��
		printf("%s\n", message[i]);
	}
	system("pause");
	system("cls");
}
static void ResetCursorPosition(const struct UI *pUI)//���ù�굽��Ļ�·���ֻҪ��Ϊ����ʾ������
{
	SetPos(0, pUI->windowHeight - 1);
}
void UIDisplyFoodAtXY(const struct UI *pUI, int x, int y)//��x y����ʾʳ�x,y�����ַ�����
{
	CoordinatePosATXY(pUI, x, y);//������תΪ���
	printf(pUI->foodblock);
	ResetCursorPosition(pUI);
}
void UIDisplySnackBlockAtXY(const struct UI *pUI, int x, int y)
//��x y����ʾ�ߵĽ�㣬x,y�����ַ�����
{
	CoordinatePosATXY(pUI, x, y);//������תΪ���
	printf(pUI->snackblock);
	ResetCursorPosition(pUI);
}
void UICleanBlockAtXY(const struct UI *pUI, int x, int y)//���x y������ʾ�飬x,y���ַ�����
{
	CoordinatePosATXY(pUI, x, y);//������תΪ���
	int i = 0;
	for (i = 0; i < pUI->blockwidth; i++)
	{
		printf(" ");
	}
	ResetCursorPosition(pUI);
}
void UIDisplayScore(const struct UI *pUI, int score, int scorePrefood)//��ʾ����
{
	int left = pUI->marginleft + (2 + pUI->gamewidth)*(pUI->blockwidth) + 2;//���ҵ��Ҳ���Ϣ���λ��
	SetPos(left, pUI->margintop + 10);
	printf("�÷֣�%d,ÿ��ʳ��÷֣�%d", score, scorePrefood);
	ResetCursorPosition(pUI);
}
void UIDisplayGameWindow(const struct UI*pUI, int score, int scorePerfood)//��ʾ��Ϸ����
{
	DisplayWall(pUI);//��ʾǽ
	UIDisplayScore(pUI, score, scorePerfood);//��ʾ����
	DisplyDesc(pUI);//��ʾ�Ҳ���Ϣ
	ResetCursorPosition(pUI);
}

void UIShowMessage(const struct UI *pUI, const char *message)//����Ϸ���������ʾ��Ϸ�˳���Ϣ
{
	//�������+1����߽������*ÿ���ַ����+��Ϸ������/2*ÿ���ַ����-�ַ������/2
	int left = pUI->marginleft + 1 * pUI->blockwidth +
		pUI->gamewidth / 2 * pUI->blockwidth - strlen(message) / 2;
	SetPos(left, pUI->margintop + 1 + pUI->gameheight / 2);
	printf("%s\n", message);
	ResetCursorPosition(pUI);
}
void UIDeinitialize(struct UI *pUI)//����UI
{
	free(pUI);
}
static void CoordinatePosATXY(const struct UI *pUI, int x, int y)//���ַ�����ת��Ϊ����ַ����
{
	SetPos(pUI->marginleft + (1 + x)*pUI->blockwidth, pUI->margintop + 1 + y);
}

struct Game *CreateGame()//��������ʼ����Ϸ
{
	struct Game *pGame = (struct Game *)malloc(sizeof(struct Game));
	assert(pGame);
	pGame->width = 28;
	pGame->height = 27;
	pGame->socre = 0;
	pGame->scoreprefood = 10;
	InitSnake(&(pGame->snack));//��ʼ���߽ṹ��
	GenerateFood(pGame);//��ʳ��
	return pGame;
}
void InitSnake(struct Snack * psnake)//��ʼ���߽ṹ��
{
	const int length = 3;//���ʼ���������
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
		pNode->pnext = psnake->pbody;// (5,5)<-(6,5)<-(7,5) (7,5����pbody
		psnake->pbody = pNode;
	}
}
void GenerateFood(struct Game *pGame)//����ʳ��
{
	int x, y;
	do
	{
		x = rand() % pGame->width;
		y = rand() % pGame->height;
	} while (IsOverlapSnake(x, y, &pGame->snack));//�����غ�ʱ�˳�ѭ��
	pGame->foodposition.x = x;
	pGame->foodposition.y = y;
}
int IsOverlapSnake(int x, int y, struct Snack *psnake)
{
	struct Node*pNode;
	for (pNode = psnake->pbody; pNode != NULL; pNode = pNode->pnext)
	{
		if (pNode->position.x == x&&pNode->position.y == y)
			return 1;//�غ���1
	}
	return 0;//���غ���0
}
void StartGame(struct Game *pGame)//��ʼ��Ϸ
{
	struct UI *pUI = UIInitalize(pGame->width, pGame->height);//��ʼ������
	enum ExitStatus exitstatus = QUIT;
	UIDisplayWizard(pUI);//��ʾ��Ϸ����

	UIDisplayGameWindow(pUI, pGame->socre, pGame->scoreprefood);//��ʾ��Ϸ����
	DisplaySnake(pUI, &pGame->snack);
	UIDisplyFoodAtXY(pUI, pGame->foodposition.x, pGame->foodposition.y);//��x y����ʾʳ�x,y�����ַ�����
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
		if (IsWillEatFood(pGame->foodposition, nextposition))//�Ե�ʳ��
		{
			pGame->socre = pGame->socre + pGame->scoreprefood;
			UIDisplayScore(pUI, pGame->socre, pGame->scoreprefood);//��ʾ����
			GrowAndDisplay(&pGame->snack, pGame->foodposition, pUI);// �����ߵĽ�㲢�Ҵ�ӡ�����ߵĽ��
			GenerateFood(pGame);//����ʳ��
			UIDisplyFoodAtXY(pUI, pGame->foodposition.x, pGame->foodposition.y);//��x y����ʾʳ�x,y�����ַ�����
		}
		else
		{
			MoveAndDisplay(&pGame->snack, nextposition, pUI);
		}

		if (IsSnakeAlive(pGame, &exitstatus))
		{
			break;  //��ײǽ����ײ���Լ�
		}
		ControlSpeed(pUI, pGame);//�����ٶ�		
	}
	char *massage[3];
	massage[QUIT] = "��Ϸ����";
	massage[KILLED_BY_WALL] = "��Ϸ������ײ��ǽ";
	massage[KILLED_BY_SELF] = "��Ϸ������ײ���Լ�";
	UIShowMessage(pUI, massage[exitstatus]);
	UIDeinitialize(pUI);//����UI
 }
void HandleDirective(struct Game *pGame)//����Ĵ���
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
struct Position GetNextPosition(struct Snack * psnake)//�õ���һ������
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
{    //�Ƿ�Ե�ʳ��
	if (foodposition.x == nextposition.x &&foodposition.y == nextposition.y )
		return 1;
	return 0;
}
void GrowAndDisplay(struct Snack *psnake, struct Position foodposition, struct UI *pUI)
{    //�����ߵĽ�㲢�Ҵ�ӡ�����ߵĽ��
	struct Node *pNode = (struct Node *)malloc(sizeof(struct Node));
	pNode->position.x = foodposition.x;
	pNode->position.y = foodposition.y;
	pNode->pnext = psnake->pbody;
	psnake->pbody = pNode;
	UIDisplySnackBlockAtXY(pUI, foodposition.x, foodposition.y);
	//��x y����ʾ�ߵĽ�㣬x,y�����ַ�����
}
void MoveAndDisplay(struct Snack *psnake, struct Position nextposition, struct UI *pUI)//���ƶ�����ӡ
{
	struct Node *pNode = (struct Node *)malloc(sizeof(struct Node));
	pNode->position.x = nextposition.x;
	pNode->position.y = nextposition.y;
	pNode->pnext = psnake->pbody;
	psnake->pbody = pNode;
	UIDisplySnackBlockAtXY(pUI, nextposition.x, nextposition.y);
	struct Node *cur = psnake->pbody;
	//βɾ
	while (cur->pnext->pnext)
	{
		cur = cur->pnext;
	}
	struct Node *tail=cur->pnext;
	UICleanBlockAtXY(pUI, tail->position.x, tail->position.y); 
	free(tail);
	cur->pnext = NULL;
}

int IsSnakeAlive(struct Game* pGame, enum ExitStatus * exitstatus)//���Ƿ���
{
	struct Node *phead = pGame->snack.pbody;
	if (IsKilledByWall(&pGame->snack, pGame->width, pGame->height))//��ǽײ��
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
	return 1;//��ǽײ��
}
int IsKilledBySelf(struct Node *phead, struct Snack *snake)
{
	//ǰ������������������� 
	struct Node *pNode=snake->pbody ->pnext ;
	while (pNode)
	{
		if (pNode->position.x == phead->position.x&&
			pNode->position.y == phead->position.y)
			return 1;//���Լ�ײ��
		pNode = pNode->pnext;
	}
	return 0;
}
void DestoryGame(struct Game *pGame)//������Ϸ��Դ
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
		Sleep(300);//ͣס
		if (GetAsyncKeyState(VK_SPACE))//�ٰ��ո���˳�ѭ����������Ϸ
			break;
	}
}
void DisplaySnake(struct UI* pUI, struct Snack *psnack)//��ʾ������
{
	struct Node *pNode=psnack->pbody ;
	if (psnack->pbody == NULL)
		return;
	while (pNode)
	{
		UIDisplySnackBlockAtXY(pUI,pNode->position .x,pNode->position .y );
		//��x y����ʾ�ߵĽ�㣬x,y�����ַ�����
		pNode = pNode->pnext;
	}
}
void ControlSpeed(struct UI *pUI, struct Game *pGame)
{
	if (GetAsyncKeyState(VK_F1))//����
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
			UIDisplayScore(pUI, pGame->socre, pGame->scoreprefood);//��ʾ����
		}
	}
	if (GetAsyncKeyState(VK_F2))//����
	{
		if (pGame->scoreprefood > 10)//С��10�޷�����
		{
			pGame->scoreprefood -= 10;
			speed = speed + 50;
			UIDisplayScore(pUI, pGame->socre, pGame->scoreprefood);//��ʾ����
		}
	}
	Sleep(speed);
}