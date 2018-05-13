
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

void QueueInit(Queue *q); //��ʼ������
void QueuePush(Queue *q, QeDatatype x);//������
void QueuePop(Queue *q);//������
QeDatatype QueueFront(Queue *q); //���е�һ��Ԫ��
QeDatatype QueueBack(Queue *q);//�������һ��Ԫ��
int QueueSize(Queue *q);//���и���
int IsQueueEmpty(Queue *q);//�����Ƿ�Ϊ��
BTNode *BuyBTNode(BTDatatype x);//�������Ľ��
BTNode *CreateBTTree(BTDatatype *a, int sz, int *pIndex, BTDatatype invalid);
   //���������� invalid�����ʾ�յ��ַ�
void BTtreePrevOreder(BTNode *root);//ǰ�����
void BTtreeInOreder(BTNode *root);//�и�����
void BTtreePostOreder(BTNode *root);//�����
int BTtreeSize(BTNode *root);//��һ�������
int BTtreeLeafSize(BTNode *root);//��Ҷ�ӽ����
int BTreeKLevelsize(BTNode *root, int k);//���k������
BTNode *BTreeFind1(BTNode *root, BTDatatype x);//���ҽ��
BTNode *BTreeFind2(BTNode *root, BTDatatype x);//���ҽ��
int BTreeDepth(BTNode *root);//���������
void LevelOrder(BTNode *root);//�������
int BTreeIscomplete(BTNode *root);//�ж���ȫ������
int BTreeIscompleteFlag(BTNode *root);//�ж���ȫ������
void BTreePrevOrderNonR(BTNode* root);//�ǵݹ�ǰ�����