#include"Btree.h"
#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include"stack.h"
void BTreePostOrderNonR(BTNode* root)//�ǵݹ�������
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
			StackPush(&st, cur);//��ջ
			cur = cur->left;
		}
		BTNode *top= StackTop(&st);
		if (top->right == NULL||top->right == last)
			//root->rightΪ�ջ��߱����ʹ�
		{
			printf("%d ", top->data);
			last = top;//��Ҫ����ǰtop��¼����
			StackPop(&st);
		}
		else  //�ҽ��
			cur = top->right;
	}
}
void BTreeInOrderNonR(BTNode* root)//�ǵݹ��������
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
			StackPush(&st, cur);//��ջ
			cur = cur->left;
		}
		BTNode *top = StackTop(&st);
		printf("%d ", top->data);
		StackPop(&st);
		cur = top->right;
	}
}
void BTreePrevOrderNonR(BTNode* root)//�ǵݹ�ǰ�����
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
			StackPush(&st, cur);//��ջ
			cur = cur->left;
		}
		BTNode *top = StackTop(&st);
		StackPop(&st);
		//����������
		cur = top->right;
		
	}
}
int BTreeIscompleteFlag(BTNode *root)//�ж���ȫ������
{
	if (root == NULL)
		return 1;
	Queue q;
	int flag = 0;
	QueueInit(&q); //��ʼ������
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
int BTreeIscomplete(BTNode *root)//�ж���ȫ������
{
	if (root == NULL)
		return 1;
	Queue q;
	QueueInit(&q); //��ʼ������
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
void LevelOrder(BTNode *root) //�������
{
	if (root==NULL)
		return;
	Queue q;
	QueueInit(&q); //��ʼ������
	if (root)
		QueuePush(&q, root);
	while (IsQueueEmpty(&q))//������в�Ϊ��
	{
		BTNode *front= QueueFront(&q);
		printf("%d ", front->data);
		QueuePop(&q); //����pop����Ϊ�Ӷ�����pop���ǽ���ָ��
		if(front->left )
			QueuePush(&q, front->left );
		if(front->right )
			QueuePush(&q, front->right);
	}
	printf("\n");
}

int BTreeDepth(BTNode *root)//���������
{
	if (root == NULL)
		return 0;
	//�����⻯Ϊ�����⣬�����ĸ߶�Ҳ�������������߶Ⱥ��������߶����ֵ
	if (BTreeDepth(root->left) > BTreeDepth(root->right))
		return  BTreeDepth(root->left)+1;
	else   //�����ȣ�Ҳ���Է����������߶�
		return  BTreeDepth(root->right)+1;
}
BTNode *BTreeFind2(BTNode *root, BTDatatype x)//���ҽ��
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode *ret = NULL;
	ret = BTreeFind2(root->left, x);
	if (ret)//������ҵ����Ͳ������ҽ���ң�ֱ�ӷ���
		return ret;
	//�����û���ҵ�
	ret= BTreeFind2(root->right, x);
	if (ret)//���ұ��ҵ�
		return ret;
	else   //�����һ�������ұ�û���ҵ������������û�иýڵ㣬�Ϳ��Է���
		return NULL;
}
BTNode *ret = NULL;
BTNode *BTreeFind1(BTNode *root, BTDatatype x)//���ҽ��
{
	if ((root) == NULL)
		return NULL ;
	if (root->data == x)
		 ret=root;
	//������������������
	else {
		BTreeFind1(root->left,x);
		BTreeFind1(root->right, x);
	}
	return ret;
}
int BTreeKLevelsize(BTNode *root, int k)//���k������
{
	//����������K��ڵ���Ŀ��ʹ�õݹ�ⷨ��
	//��k��Ľڵ��� = ��k - 1�����ӽڵ��� + ��k - 1���Һ��ӽڵ���Ŀ��
	//ֱ��k == 1ʱ��˵���Ѿ����˵�K�㡣
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return  BTreeKLevelsize(root->left, k -1) + BTreeKLevelsize(root->right, k - 1);
}
int BTtreeLeafSize(BTNode *root)//��Ҷ�ӽ����
{
	if (root == NULL)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;
	return BTtreeLeafSize(root->left) + BTtreeLeafSize(root->right);
}

int  BTtreeSize(BTNode *root)//��һ�������
{//�����⻯Ϊ�����⣬���������1+�����������+�����������
	if (root == NULL)
		return 0;
	return 1 + BTtreeSize(root->left) + BTtreeSize(root->right);
}
void BTtreePostOreder(BTNode *root)//�������
{
	if (root)
	{
		BTtreePostOreder(root->left);
		BTtreePostOreder(root->right);
		printf("%d ", root->data);
	}
	return;
}
void BTtreeInOreder(BTNode *root)//�и�����
{
	if (root)
	{
		BTtreeInOreder(root->left);
		printf("%d ", root->data);
		BTtreeInOreder(root->right);
	}
	return;
}
void BTtreePrevOreder(BTNode *root)//ǰ�����
{
	if (root)
	{
		printf("%d ", root->data);
		BTtreePrevOreder(root->left);
		BTtreePrevOreder(root->right);
	}
	return;
}
BTNode *BuyBTNode(BTDatatype x)//�������Ľ��
{
	BTNode *tree = (BTNode *)malloc(sizeof(BTNode));
	tree->data = x;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}
BTNode *CreateBTTree(BTDatatype *a, int sz, int *pIndex, BTDatatype invalid)
{//invalid�����ʾ�յ��ַ�
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
	//printf("ǰ�������");
	//BTtreePrevOreder(root);//ǰ��
	//printf("\n");
	BTreePrevOrderNonR(root);//�ǵݹ�ǰ�����
	printf("\n");
	//BTtreeInOreder(root);//����
	//printf("\n");
	BTreeInOrderNonR(root);//�ǵݹ��������
	printf("\n");
	//BTtreePostOreder(root);//����
	//printf("\n");
	BTreePostOrderNonR(root);//�ǵݹ��к������
	printf("\n");
	//printf("���Ľ������%d\n", BTtreeSize(root));//���Ľ����
	//printf("����Ҷ�ӽ������%d\n", BTtreeLeafSize(root));//��Ҷ�ӽ����
	//int k = 4;
	//printf("��%d��������%d\n", k,BTreeKLevelsize(root, k));//���k������
	//printf("%d\n", BTreeFind1(root, 3)->data);//���ҽ��
	//printf("%d\n", BTreeFind2(root, 1)->data);//���ҽ��
	//printf("%d\n", BTreeFind2(root, 2)->data);//���ҽ��
	//printf("���ĸ߶ȣ�%d\n",BTreeDepth(root));
	//printf("���������");
	//LevelOrder(root);  //�������
	//printf("%d\n", BTreeIscomplete(root)); //�ж���ȫ������
	//printf("%d\n",BTreeIscompleteFlag(root)); //�ж���ȫ������
	//
}
int IsQueueEmpty(Queue *q)//�����Ƿ�Ϊ��
{
	if (q->head == NULL)
		return 0;
	return 1;
}
int QueueSize(Queue *q)//���и���
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
QeDatatype QueueBack(Queue *q)//�������һ��Ԫ��
{
	assert(q&&q->tail);
	return  q->tail->data;
}
QeDatatype QueueFront(Queue *q)//���е�һ��Ԫ��
{
	assert(q&&q->head);
	return q->head->data;
}
void QueuePop(Queue *q)//������
{
	assert(q);
	if (q->head == NULL)
	{
		printf("û��Ԫ��\n");
		return;
	}
	if (q->head == q->tail)//˵��ֻ��һ��Ԫ��
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

void QueuePush(Queue *q, QeDatatype x)//������
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
void QueueInit(Queue *q)//��ʼ������
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

