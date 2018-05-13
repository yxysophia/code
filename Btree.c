#include"Btree.h"
#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include"stack.h"
void BTreePostOrderNonR(BTNode* root)//非递归后序遍历
{
	if (root == NULL)
		return;
	BTNode *cur = root;
	Stack st;
	BTNode *last=NULL;
	StackInit(&st);
	while (cur || StackEmpty(&st))
	{
		while (cur)
		{
			StackPush(&st, cur);//入栈
			cur = cur->left;
		}
		BTNode *top= StackTop(&st);
		if (top->right == NULL||top->right == last)
			//root->right为空或者被访问过
		{
			printf("%d ", top->data);
			last = top;//需要将当前top记录下来
			StackPop(&st);
		}
		else  //右结点
			cur = top->right;
	}
}
void BTreeInOrderNonR(BTNode* root)//非递归中序遍历
{
    if (root == NULL)
		return;
	BTNode *cur = root;
	Stack st;
	
	StackInit(&st);
	while (cur || StackEmpty(&st))
	{
		while (cur)
		{
			StackPush(&st, cur);//入栈
			cur = cur->left;
		}
		BTNode *top = StackTop(&st);
		printf("%d ", top->data);
		StackPop(&st);
		cur = top->right;
	}
}
void BTreePrevOrderNonR(BTNode* root)//非递归前序遍历
{
	if (root == NULL)
		return;
	BTNode *cur = root;
	Stack st;
	StackInit(&st);
	while (cur || StackEmpty(&st)!=0)
	{
		while (cur)
		{
			printf("%d ", cur->data);
			StackPush(&st, cur);//入栈
			cur = cur->left;
		}
		BTNode *top = StackTop(&st);
		StackPop(&st);
		//访问右子树
		cur = top->right;
		
	}
}
int BTreeIscompleteFlag(BTNode *root)//判断完全二叉树
{
	if (root == NULL)
		return 1;
	Queue q;
	int flag = 0;
	QueueInit(&q); //初始化队列
	QueuePush(&q, root);
	while (IsQueueEmpty(&q))
	{
		BTNode *front = QueueFront(&q);
		if (front == NULL)
			break;
		if ((front->left || front->right) && flag == 1)
			return 0;
		if (front->left == NULL|| front->right == NULL)
			flag = 1;
		QueuePop(&q);
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	return 1;
}
int BTreeIscomplete(BTNode *root)//判断完全二叉树
{
	if (root == NULL)
		return 1;
	Queue q;
	QueueInit(&q); //初始化队列
	QueuePush(&q, root);
	while (IsQueueEmpty(&q))
	{
		BTNode *front = QueueFront(&q);
		if (front == NULL)
			break;
		QueuePop(&q);
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	while (IsQueueEmpty(&q))
	{
		if (QueueFront(&q) != NULL)
			return 0;
		QueuePop(&q);
	}
	return 1;
}
void LevelOrder(BTNode *root) //层序遍历
{
	if (root==NULL)
		return;
	Queue q;
	QueueInit(&q); //初始化队列
	if (root)
		QueuePush(&q, root);
	while (IsQueueEmpty(&q))//如果队列不为空
	{
		BTNode *front= QueueFront(&q);
		printf("%d ", front->data);
		QueuePop(&q); //可以pop，因为从队列里pop的是结点的指针
		if(front->left )
			QueuePush(&q, front->left );
		if(front->right )
			QueuePush(&q, front->right);
	}
	printf("\n");
}

int BTreeDepth(BTNode *root)//求树的深度
{
	if (root == NULL)
		return 0;
	//将问题化为子问题，求树的高度也就是求左子树高度和右子树高度最大值
	if (BTreeDepth(root->left) > BTreeDepth(root->right))
		return  BTreeDepth(root->left)+1;
	else   //如果相等，也可以返回右子树高度
		return  BTreeDepth(root->right)+1;
}
BTNode *BTreeFind2(BTNode *root, BTDatatype x)//查找结点
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode *ret = NULL;
	ret = BTreeFind2(root->left, x);
	if (ret)//在左边找到，就不用在右结点找，直接返回
		return ret;
	//在左边没有找到
	ret= BTreeFind2(root->right, x);
	if (ret)//在右边找到
		return ret;
	else   //如果在一颗树的右边没有找到，那这棵树就没有该节点，就可以返回
		return NULL;
}
BTNode *ret = NULL;
BTNode *BTreeFind1(BTNode *root, BTDatatype x)//查找结点
{
	if ((root) == NULL)
		return NULL ;
	if (root->data == x)
		 ret=root;
	//查找左子树和右字树
	else {
		BTreeFind1(root->left,x);
		BTreeFind1(root->right, x);
	}
	return ret;
}
int BTreeKLevelsize(BTNode *root, int k)//求第k层结点数
{
	//求解二叉树第K层节点数目，使用递归解法，
	//第k层的节点数 = 第k - 1层左孩子节点数 + 第k - 1层右孩子节点数目，
	//直到k == 1时，说明已经到了第K层。
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return  BTreeKLevelsize(root->left, k -1) + BTreeKLevelsize(root->right, k - 1);
}
int BTtreeLeafSize(BTNode *root)//树叶子结点数
{
	if (root == NULL)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;
	return BTtreeLeafSize(root->left) + BTtreeLeafSize(root->right);
}

int  BTtreeSize(BTNode *root)//树一共结点数
{//将问题化为子问题，结点数等于1+左子树结点数+右子树结点数
	if (root == NULL)
		return 0;
	return 1 + BTtreeSize(root->left) + BTtreeSize(root->right);
}
void BTtreePostOreder(BTNode *root)//后根遍历
{
	if (root)
	{
		BTtreePostOreder(root->left);
		BTtreePostOreder(root->right);
		printf("%d ", root->data);
	}
	return;
}
void BTtreeInOreder(BTNode *root)//中根遍历
{
	if (root)
	{
		BTtreeInOreder(root->left);
		printf("%d ", root->data);
		BTtreeInOreder(root->right);
	}
	return;
}
void BTtreePrevOreder(BTNode *root)//前序遍历
{
	if (root)
	{
		printf("%d ", root->data);
		BTtreePrevOreder(root->left);
		BTtreePrevOreder(root->right);
	}
	return;
}
BTNode *BuyBTNode(BTDatatype x)//构建树的结点
{
	BTNode *tree = (BTNode *)malloc(sizeof(BTNode));
	tree->data = x;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}
BTNode *CreateBTTree(BTDatatype *a, int sz, int *pIndex, BTDatatype invalid)
{//invalid代表表示空的字符
	assert(a);
	BTNode *root = NULL;
	assert(a && (*pIndex < sz) && pIndex);
		if (a[*pIndex] != invalid)
		{
			root = BuyBTNode(a[*pIndex]);
			(*pIndex)++;
			root->left = CreateBTTree(a, sz, pIndex, invalid);
			(*pIndex)++;
			root->right = CreateBTTree(a, sz, pIndex, invalid);
		}
	
	return root;
}
void TestBinaryTree()
{
	BTNode *root = NULL;
	BTDatatype a[] = { 1, 2, 3, '#', '#',4,'#', '#', 5, 6,9 ,'#','#','#', '#' };
	int pIndex = 0;
	int sz = sizeof(a) / sizeof(a[0]);
	root = CreateBTTree(a, sz, &pIndex, '#');
	//printf("前序遍历：");
	//BTtreePrevOreder(root);//前序
	//printf("\n");
	BTreePrevOrderNonR(root);//非递归前序遍历
	printf("\n");
	//BTtreeInOreder(root);//中序
	//printf("\n");
	BTreeInOrderNonR(root);//非递归中序遍历
	printf("\n");
	//BTtreePostOreder(root);//后序
	//printf("\n");
	BTreePostOrderNonR(root);//非递归中后序遍历
	printf("\n");
	//printf("树的结点数：%d\n", BTtreeSize(root));//树的结点数
	//printf("树的叶子结点数：%d\n", BTtreeLeafSize(root));//树叶子结点数
	//int k = 4;
	//printf("第%d层结点数：%d\n", k,BTreeKLevelsize(root, k));//求第k层结点数
	//printf("%d\n", BTreeFind1(root, 3)->data);//查找结点
	//printf("%d\n", BTreeFind2(root, 1)->data);//查找结点
	//printf("%d\n", BTreeFind2(root, 2)->data);//查找结点
	//printf("树的高度：%d\n",BTreeDepth(root));
	//printf("层序遍历：");
	//LevelOrder(root);  //层序遍历
	//printf("%d\n", BTreeIscomplete(root)); //判断完全二叉树
	//printf("%d\n",BTreeIscompleteFlag(root)); //判断完全二叉树
	//
}
int IsQueueEmpty(Queue *q)//队列是否为空
{
	if (q->head == NULL)
		return 0;
	return 1;
}
int QueueSize(Queue *q)//队列个数
{
    int count = 0;
	if (q->head == NULL)
		return 0;
	QueueNode *cur = q->head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
QeDatatype QueueBack(Queue *q)//队列最后一个元素
{
	assert(q&&q->tail);
	return  q->tail->data;
}
QeDatatype QueueFront(Queue *q)//队列第一个元素
{
	assert(q&&q->head);
	return q->head->data;
}
void QueuePop(Queue *q)//出队列
{
	assert(q);
	if (q->head == NULL)
	{
		printf("没有元素\n");
		return;
	}
	if (q->head == q->tail)//说明只有一个元素
	{
		free(q->head);
		q->head = NULL;
		q->tail = NULL;
	}
	else
	{
		QueueNode *cur = q->head->next;
		free(q->head);
		q->head = cur;
	}
}

void QueuePush(Queue *q, QeDatatype x)//进队列
{
	QueueNode *new = (QueueNode *)malloc(sizeof(QueueNode));
	new->data = x;
	new->next = NULL;
	if (q->head == NULL)
	{
		q->head = q->tail = new;
	}
	else
	{
		q->tail->next = new;
		q->tail = new;
	}
}
void QueueInit(Queue *q)//初始化队列
{
	q->head = NULL;
	q->tail = NULL;
}

int main()
{
	TestBinaryTree();
	system("pause");
	return 0;
}

