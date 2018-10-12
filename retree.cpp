#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stack>
#include<iostream>
using namespace std;
typedef char TDatatype;

typedef struct TreeNode
{
	struct TreeNode *_pleft;
	struct TreeNode *_pright;
	TDatatype _data;
}TreeNode;
TreeNode* CreateNode(TDatatype data)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->_pleft = NULL;
	node->_pright = NULL;
	node->_data = data;
	return node;
}
TreeNode* CreateTree(char* array,int* pindex, int size, TDatatype flag)//前序创建二叉树
{
	assert(array);
	TreeNode* root = NULL;
	if (*pindex < size)  //必须加上判断，否则到最后一个元素F时，会继续向下走
	{
		if (array[*pindex] != flag)
		{
			root = CreateNode(array[*pindex]);
			(*pindex)++; //为什么用指针，因为返回栈帧是pindex可能是之前栈帧的下标，
			//用指针，下标就一直在向后走
			root->_pleft = CreateTree(array, pindex, size, '#');
			(*pindex)++; //注意，左走完后，走右时需要++
			root->_pright = CreateTree(array, pindex, size, '#');
		}
	}
	return root;  //不满足条件，直接返回null
}
void  PrintFrontR(TreeNode* root)//前序遍历二叉树
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->_data);
	 PrintFrontR(root->_pleft);
	 PrintFrontR(root->_pright);
}
void PrintMidR(TreeNode* root)//中根遍历
{
	if (root == NULL)
	{
		return;
	}
	PrintMidR(root->_pleft);
	printf("%c ", root->_data);
	PrintMidR(root->_pright);
}
void PrintBackR(TreeNode* root)//后根遍历
{
	if (root == NULL)
		return;
	PrintBackR(root->_pleft);
	PrintBackR(root->_pright);
	printf("%c ", root->_data);
}
void PrintFront(TreeNode* root) //前根非递归
{
	if (root == NULL)
		return;
	stack<TreeNode*> s;
	while (root|| !s.empty()) //root为空且栈为空时退出循环
	{
		while (root)  //找到最左边非叶结点
		{
			printf("%c ", root->_data);
			s.push(root);
			root = root->_pleft;
		}		
		root = s.top();
		root = root->_pright; //又从该结点的右结点开始遍历
		s.pop();
	}
}
void PrintMid(TreeNode* root)  //中根遍历
{
	if (root == NULL)
		return;
	stack<TreeNode*> s;
	while (root || !s.empty())
	{
		while(root) //找到最左非叶结点
		{
			s.push(root);  //将之前结点存储起来
			root = root->_pleft;
		}
		root = s.top();  
		printf("%c ", root->_data); //这时栈顶元素是要打印元素
		root = root->_pright; //继续以该结点的右结点开始遍历
		s.pop(); //该节点遍历完毕，出栈，这时已经将右结点保存了
	}
	printf("\n");
}
//后根遍历思想是：找到最左非叶结点，
//如果该结点的右结点为空或者右结点被访问过，那么就打印该结点，否则就以该右结点为根继续遍历
//那么就需要一个变量来存储之前被访问的节点,

void PrintBack(TreeNode* root) //后根非递归遍历
{
	assert(root);
	TreeNode* cur = root;
	TreeNode* lasttop = cur;
	stack<TreeNode*> s;
	while (cur || !s.empty())
	{
		while (cur)  //找到最左非叶结点
		{
			s.push(cur);
			cur = cur->_pleft;
		}
		TreeNode* top = s.top();
		while (top->_pright == NULL || top->_pright == lasttop)  //右结点为空或者被访问
		{
			cout << top->_data << " ";
			lasttop = s.top();  //记录被访问的节点
			s.pop();
			if (!s.empty())   
				top = s.top();
			else  //如果栈为空，证明刚被访问的节点是根结点
				return;
		}
		if (top->_pright != NULL)  //右结点不为空，以右结点为根继续循环遍历
		{
			cur = top->_pright;
		}
	}
	printf("\n");
}
int main()
{
	//char array[] = { 'A','B','D','#','#','#','C','E','#','#','F' };
	char array[] = { 'a','b','#','#','#' };
	int size = sizeof(array) / sizeof(char);
	int pindex = 0;
	TreeNode* root = CreateTree(array, &pindex,size, '#');
	 PrintFrontR(root);
	printf("\n");
	PrintMidR(root);
	printf("\n");
	PrintBackR(root);
	printf("\n");
	PrintFront(root);
	printf("\n");
	PrintMid(root);
	PrintBack(root);
	system("pause");
	return 0;

}