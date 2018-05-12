#pragma once

typedef int BSTreeDatatype;
typedef struct BSTreeNode
{
	struct BSTreeNode *left;
	struct BSTreeNode *right;
	BSTreeDatatype data;
}BSTreeNode;

int BSTreeInsert(BSTreeNode **pptree, BSTreeDatatype x);//插入数据
BSTreeNode *BuyBSTreeNode(BSTreeDatatype x);//创建结点
void BSTreeInOrder(BSTreeNode *ptree);//中序遍历
const BSTreeNode *FindBSTreeNode(BSTreeNode *ptree, BSTreeDatatype x);//查找元素
int BSTreeNodeRemove(BSTreeNode **pptree, BSTreeDatatype x);//删除

int BSTreeInsertR(BSTreeNode **pptree, BSTreeDatatype x);//递归插入
const BSTreeNode * BSTreeFindNodeR(BSTreeNode *pptree, BSTreeDatatype x);//递归查找
int BSTreeRemoveR(BSTreeNode **pptree, BSTreeDatatype x);//递归删除