#pragma once

typedef int BSTreeDatatype;
typedef struct BSTreeNode
{
	struct BSTreeNode *left;
	struct BSTreeNode *right;
	BSTreeDatatype data;
}BSTreeNode;

int BSTreeInsert(BSTreeNode **pptree, BSTreeDatatype x);//��������
BSTreeNode *BuyBSTreeNode(BSTreeDatatype x);//�������
void BSTreeInOrder(BSTreeNode *ptree);//�������
const BSTreeNode *FindBSTreeNode(BSTreeNode *ptree, BSTreeDatatype x);//����Ԫ��
int BSTreeNodeRemove(BSTreeNode **pptree, BSTreeDatatype x);//ɾ��

int BSTreeInsertR(BSTreeNode **pptree, BSTreeDatatype x);//�ݹ����
const BSTreeNode * BSTreeFindNodeR(BSTreeNode *pptree, BSTreeDatatype x);//�ݹ����
int BSTreeRemoveR(BSTreeNode **pptree, BSTreeDatatype x);//�ݹ�ɾ��