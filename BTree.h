
#pragma once
typedef int BTDatatype;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
	BTDatatype data;
}BTNode;
typedef BTNode*  QeDatatype;
typedef struct QueueNode
{
	QeDatatype data;
	struct QueueNode *next;
}QueueNode;
typedef struct Queue
{
	QueueNode *head;
	QueueNode *tail;
}Queue;

void QueueInit(Queue *q); //初始化队列
void QueuePush(Queue *q, QeDatatype x);//进队列
void QueuePop(Queue *q);//出队列
QeDatatype QueueFront(Queue *q); //队列第一个元素
QeDatatype QueueBack(Queue *q);//队列最后一个元素
int QueueSize(Queue *q);//队列个数
int IsQueueEmpty(Queue *q);//队列是否为空
BTNode *BuyBTNode(BTDatatype x);//构建树的结点
BTNode *CreateBTTree(BTDatatype *a, int sz, int *pIndex, BTDatatype invalid);
   //创建二叉树 invalid代表表示空的字符
void BTtreePrevOreder(BTNode *root);//前序遍历
void BTtreeInOreder(BTNode *root);//中根遍历
void BTtreePostOreder(BTNode *root);//后根遍
int BTtreeSize(BTNode *root);//树一共结点数
int BTtreeLeafSize(BTNode *root);//树叶子结点数
int BTreeKLevelsize(BTNode *root, int k);//求第k层结点数
BTNode *BTreeFind1(BTNode *root, BTDatatype x);//查找结点
BTNode *BTreeFind2(BTNode *root, BTDatatype x);//查找结点
int BTreeDepth(BTNode *root);//求树的深度
void LevelOrder(BTNode *root);//层序遍历
int BTreeIscomplete(BTNode *root);//判断完全二叉树
int BTreeIscompleteFlag(BTNode *root);//判断完全二叉树
void BTreePrevOrderNonR(BTNode* root);//非递归前序遍历