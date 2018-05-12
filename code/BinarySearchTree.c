#include"BinarySearchTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main()
{
	BSTreeNode *tree = NULL;
	BSTreeInsert(&tree, 19);
	BSTreeInsert(&tree, 15);
	BSTreeInsert(&tree, 30);
	BSTreeInsert(&tree, 12);
	BSTreeInsert(&tree, 17);
	BSTreeInsert(&tree, 11);
	BSTreeInsert(&tree, 16);
	BSTreeInsert(&tree, 18);
	BSTreeInsert(&tree, 21);
	BSTreeInsert(&tree, 34);
	BSTreeInsert(&tree, 25);
	//BSTreeInsertR(&tree, 19);
	//BSTreeInsertR(&tree, 15);
	//BSTreeInsertR(&tree, 30);
	//BSTreeInsertR(&tree, 12);
	//BSTreeInsertR(&tree, 17);
	//BSTreeInsertR(&tree, 11);
	//BSTreeInsertR(&tree, 16);
	//BSTreeInsertR(&tree, 18);
	//BSTreeInsertR(&tree, 21);
	//BSTreeInsertR(&tree, 34);
	//BSTreeInOrder(tree);//�������
	//printf("\n");
	/*	printf("%d\n", BSTreeFindNodeR(tree, 17)->data);
	printf("%d\n", BSTreeFindNodeR(tree, 19)->data);
	printf("%d\n", BSTreeFindNodeR(tree, 11)->data);
	printf("%d\n", BSTreeFindNodeR(tree, 17)->data);
	printf("%d\n", BSTreeFindNodeR(tree, 18)->data);
	printf("%d\n", BSTreeFindNodeR(tree, 30)->data);
	printf("%d\n", BSTreeFindNodeR(tree, 34)->data)*/;
	//BSTreeRemoveR(&tree, 19 );//ɾ��
	//BSTreeRemoveR(&tree, 15);//ɾ��
	//BSTreeRemoveR(&tree, 30);//ɾ��
	//BSTreeRemoveR(&tree, 12);//ɾ��
	//BSTreeRemoveR(&tree, 17);//ɾ��
	//BSTreeRemoveR(&tree, 11);//ɾ��
	//BSTreeRemoveR(&tree, 16);//ɾ��
	//BSTreeRemoveR(&tree, 18);//ɾ��
	//BSTreeRemoveR(&tree, 21);//ɾ��
	//BSTreeRemoveR(&tree, 34);//ɾ��
	//BSTreeInOrder(tree);//�������
	//printf("\n");
	//printf("%d\n", FindBSTreeNode(tree, 17)->data);
	BSTreeNodeRemove(&tree, 19);//ɾ��
	BSTreeNodeRemove(&tree, 15);//ɾ��
	BSTreeNodeRemove(&tree, 30);//ɾ��
	BSTreeNodeRemove(&tree, 12);//ɾ��
	BSTreeNodeRemove(&tree, 17);//ɾ��
	BSTreeNodeRemove(&tree, 11);//ɾ��
	BSTreeNodeRemove(&tree, 16);//ɾ��
	BSTreeNodeRemove(&tree, 18);//ɾ��
	BSTreeNodeRemove(&tree, 21);//ɾ��
	BSTreeNodeRemove(&tree, 34);//ɾ��
	BSTreeNodeRemove(&tree, 25);//ɾ��
	BSTreeInOrder(tree);//�������
	system("pause");
	return 0;
}
BSTreeNode *BuyBSTreeNode(BSTreeDatatype x)//�������
{
	BSTreeNode *newnode = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	if (newnode == NULL)
		return NULL;
	else
	{
		newnode->data = x;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
}
int BSTreeInsert(BSTreeNode **pptree, BSTreeDatatype x)//��������
{
	BSTreeNode *node = BuyBSTreeNode(x);
	BSTreeNode *parent = NULL, *cur = *pptree;
	if (*pptree == NULL)
	{
		*pptree = node;
		return 0;
	}
	while (cur)
	{
		if (cur->data < x)
		{
			parent = cur;
			cur = cur->right;
		}
		else if (cur->data > x)
		{
			parent = cur;
			cur = cur->left;
		}
		else
			return -1;//����Ԫ���Դ��ڣ��򲻽��в���
	}
	if (parent->data > x)
		parent->left = node;
	else
		parent->right = node;
	return 0;
}
void BSTreeInOrder(BSTreeNode *ptree)//�������
{
	if (ptree == NULL)
		return;
	BSTreeInOrder(ptree->left);
	printf("%d ", ptree->data);
	BSTreeInOrder(ptree->right);
}
const BSTreeNode *FindBSTreeNode(BSTreeNode *ptree, BSTreeDatatype x)//����Ԫ��
{
	assert(ptree);
	BSTreeNode *cur = ptree;
	while (cur)
	{
		if (cur->data < x)
			cur = cur->right;
		else if (cur->data > x)
			cur = cur->left;
		else
			return cur;
	}
	return NULL;
}

int BSTreeNodeRemove(BSTreeNode **pptree, BSTreeDatatype x)//ɾ��
{
	assert(*pptree);
	BSTreeNode *cur = *pptree, *parent = *pptree;
	while (cur)//�ҵ�ɾ�����
	{
		if (cur->data < x)
		{
			parent = cur;
			cur = cur->right;
		}
		else if (cur->data > x)
		{
			parent = cur;
			cur = cur->left;
		}
		else
			break;
	}
	if (cur->left == NULL)//��Ϊ��
	{
		if (parent->data < x)
			parent->right = cur->right;
		else if (parent->data>x)
			parent->left = cur->right;
		else
		{
			BSTreeNode *subleft, *parentnode = cur;
			subleft = cur->right;
			if (subleft)
			{
				while (subleft->left)
				{
					parentnode = subleft;
					subleft = subleft->left;
				}
				cur->data = subleft->data;
				if (parentnode->right == subleft)
					parentnode->right = subleft->right;
				else
					parentnode->left = subleft->right;
				free(subleft);
				subleft = NULL;
			}
			else
			{  //˵��*pptree�Ǹ����,����ֻ����һ�������
				*pptree = NULL;
			}
		}
		return 0;
	}
	if (cur->right == NULL)//��Ϊ��
	{
		if (parent->data < x)
			parent->right = cur->left;
		else if (parent->data>x)
			parent->left = cur->left;
		else
		{
			//˵��ɾ�������
			BSTreeNode *subright, *parentnode = cur;
			subright = cur->left;
			if (subright)
			{
				while (subright->right)
				{
					parentnode = subright;
					subright = subright->right;
				}
				cur->data = subright->data;
				if (parentnode->left == subright)
					parentnode->left = subright->left;
				else
					parentnode->right = subright->left;
				free(subright);
				subright = NULL;
			}
		}
		return 0;
	}

	BSTreeNode *subleft, *parentnode = cur;
	subleft = cur->right;
	while (subleft->left)
	{
		parentnode = subleft;
		subleft = subleft->left;
	}
	cur->data = subleft->data;
	if (parentnode->left == subleft)
		parentnode->left = subleft->right;
	else
		parentnode->right = subleft->right;
	free(subleft);
	return 0;
}
int BSTreeInsertR(BSTreeNode **pptree, BSTreeDatatype x)//�ݹ����
{
	BSTreeNode *newnode = BuyBSTreeNode(x);
	if (*pptree == NULL)
	{    //����pptree�Ƕ���ָ�룬�����ú������һ��pptree->left��pptree->right
		 //������Ȼ�Ľ������뺢����������
		*pptree = newnode;
		return 0;
	}
	if ((*pptree)->data < x)
	{
		return BSTreeInsertR(&(*pptree)->right, x);
	}
	else if ((*pptree)->data > x)
	{
		return BSTreeInsertR(&(*pptree)->left, x);
	}
	else
		return -1;
}
const BSTreeNode * BSTreeFindNodeR(BSTreeNode *pptree, BSTreeDatatype x)//�ݹ����
{
	if (pptree == NULL)
		return NULL;
	if (pptree->data == x)
		return pptree;
	else if (pptree->data < x)
		return BSTreeFindNodeR(pptree->right, x);
	else
		return BSTreeFindNodeR(pptree->left, x);
}
int BSTreeRemoveR(BSTreeNode **pptree, BSTreeDatatype x)//�ݹ�ɾ��
{
	if (*pptree == NULL)//�ǿ�֤��û�иý�㣬ֱ�ӷ���
		return  -1;
	if ((*pptree)->data < x)//����������ɾ��
		return BSTreeRemoveR(&(*pptree)->right, x);//�ݹ�ɾ��
	else if ((*pptree)->data>x)//����������ɾ��
		return BSTreeRemoveR(&(*pptree)->left, x);
	else
	{
		BSTreeNode *del = *pptree;
		//Ҷ�ӽ����Ժ�������Ϊ�ջ�����Ϊ����
		if ((*pptree)->left == NULL)//��Ϊ��
		{
			*pptree = (*pptree)->right;
			free(del);
			return 0;
		}
		else if ((*pptree)->right == NULL)//��Ϊ��
		{
			*pptree = (*pptree)->left;//���ö���ָ�������
			free(del);
			return 0;
		}
		else
		{
			BSTreeNode *subleft = (*pptree)->right;
			while (subleft->left)
				subleft = subleft->left;
			(*pptree)->data = subleft->data;
			//Ȼ���subleftɾ���������ﲻ��д�ɣ�subleft,subleft->data),
			//��Ϊsubleft�Ǿֲ�����
			return BSTreeRemoveR(&(*pptree)->right, subleft->data);//�ݹ�ɾ��
		}
	}
}