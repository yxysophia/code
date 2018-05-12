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
	//BSTreeInOrder(tree);//中序遍历
	//printf("\n");
	/*	printf("%d\n", BSTreeFindNodeR(tree, 17)->data);
	printf("%d\n", BSTreeFindNodeR(tree, 19)->data);
	printf("%d\n", BSTreeFindNodeR(tree, 11)->data);
	printf("%d\n", BSTreeFindNodeR(tree, 17)->data);
	printf("%d\n", BSTreeFindNodeR(tree, 18)->data);
	printf("%d\n", BSTreeFindNodeR(tree, 30)->data);
	printf("%d\n", BSTreeFindNodeR(tree, 34)->data)*/;
	//BSTreeRemoveR(&tree, 19 );//删除
	//BSTreeRemoveR(&tree, 15);//删除
	//BSTreeRemoveR(&tree, 30);//删除
	//BSTreeRemoveR(&tree, 12);//删除
	//BSTreeRemoveR(&tree, 17);//删除
	//BSTreeRemoveR(&tree, 11);//删除
	//BSTreeRemoveR(&tree, 16);//删除
	//BSTreeRemoveR(&tree, 18);//删除
	//BSTreeRemoveR(&tree, 21);//删除
	//BSTreeRemoveR(&tree, 34);//删除
	//BSTreeInOrder(tree);//中序遍历
	//printf("\n");
	//printf("%d\n", FindBSTreeNode(tree, 17)->data);
	BSTreeNodeRemove(&tree, 19);//删除
	BSTreeNodeRemove(&tree, 15);//删除
	BSTreeNodeRemove(&tree, 30);//删除
	BSTreeNodeRemove(&tree, 12);//删除
	BSTreeNodeRemove(&tree, 17);//删除
	BSTreeNodeRemove(&tree, 11);//删除
	BSTreeNodeRemove(&tree, 16);//删除
	BSTreeNodeRemove(&tree, 18);//删除
	BSTreeNodeRemove(&tree, 21);//删除
	BSTreeNodeRemove(&tree, 34);//删除
	BSTreeNodeRemove(&tree, 25);//删除
	BSTreeInOrder(tree);//中序遍历
	system("pause");
	return 0;
}
BSTreeNode *BuyBSTreeNode(BSTreeDatatype x)//创建结点
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
int BSTreeInsert(BSTreeNode **pptree, BSTreeDatatype x)//插入数据
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
			return -1;//插入元素以存在，则不进行插入
	}
	if (parent->data > x)
		parent->left = node;
	else
		parent->right = node;
	return 0;
}
void BSTreeInOrder(BSTreeNode *ptree)//中序遍历
{
	if (ptree == NULL)
		return;
	BSTreeInOrder(ptree->left);
	printf("%d ", ptree->data);
	BSTreeInOrder(ptree->right);
}
const BSTreeNode *FindBSTreeNode(BSTreeNode *ptree, BSTreeDatatype x)//查找元素
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

int BSTreeNodeRemove(BSTreeNode **pptree, BSTreeDatatype x)//删除
{
	assert(*pptree);
	BSTreeNode *cur = *pptree, *parent = *pptree;
	while (cur)//找到删除结点
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
	if (cur->left == NULL)//左为空
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
			{  //说明*pptree是根结点,而且只有这一个根结点
				*pptree = NULL;
			}
		}
		return 0;
	}
	if (cur->right == NULL)//右为空
	{
		if (parent->data < x)
			parent->right = cur->left;
		else if (parent->data>x)
			parent->left = cur->left;
		else
		{
			//说明删除根结点
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
int BSTreeInsertR(BSTreeNode **pptree, BSTreeDatatype x)//递归插入
{
	BSTreeNode *newnode = BuyBSTreeNode(x);
	if (*pptree == NULL)
	{    //由于pptree是二级指针，解引用后就是上一个pptree->left或pptree->right
		 //具有天然的将父亲与孩子链接起来
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
const BSTreeNode * BSTreeFindNodeR(BSTreeNode *pptree, BSTreeDatatype x)//递归查找
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
int BSTreeRemoveR(BSTreeNode **pptree, BSTreeDatatype x)//递归删除
{
	if (*pptree == NULL)//是空证明没有该结点，直接返回
		return  -1;
	if ((*pptree)->data < x)//在右子树里删除
		return BSTreeRemoveR(&(*pptree)->right, x);//递归删除
	else if ((*pptree)->data>x)//在左子树里删除
		return BSTreeRemoveR(&(*pptree)->left, x);
	else
	{
		BSTreeNode *del = *pptree;
		//叶子结点可以涵盖在左为空或者右为空中
		if ((*pptree)->left == NULL)//左为空
		{
			*pptree = (*pptree)->right;
			free(del);
			return 0;
		}
		else if ((*pptree)->right == NULL)//右为空
		{
			*pptree = (*pptree)->left;//利用二级指针解引用
			free(del);
			return 0;
		}
		else
		{
			BSTreeNode *subleft = (*pptree)->right;
			while (subleft->left)
				subleft = subleft->left;
			(*pptree)->data = subleft->data;
			//然后把subleft删除，参数里不能写成（subleft,subleft->data),
			//因为subleft是局部变量
			return BSTreeRemoveR(&(*pptree)->right, subleft->data);//递归删除
		}
	}
}