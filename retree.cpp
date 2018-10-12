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
TreeNode* CreateTree(char* array,int* pindex, int size, TDatatype flag)//ǰ�򴴽�������
{
	assert(array);
	TreeNode* root = NULL;
	if (*pindex < size)  //��������жϣ��������һ��Ԫ��Fʱ�������������
	{
		if (array[*pindex] != flag)
		{
			root = CreateNode(array[*pindex]);
			(*pindex)++; //Ϊʲô��ָ�룬��Ϊ����ջ֡��pindex������֮ǰջ֡���±꣬
			//��ָ�룬�±��һֱ�������
			root->_pleft = CreateTree(array, pindex, size, '#');
			(*pindex)++; //ע�⣬�����������ʱ��Ҫ++
			root->_pright = CreateTree(array, pindex, size, '#');
		}
	}
	return root;  //������������ֱ�ӷ���null
}
void  PrintFrontR(TreeNode* root)//ǰ�����������
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->_data);
	 PrintFrontR(root->_pleft);
	 PrintFrontR(root->_pright);
}
void PrintMidR(TreeNode* root)//�и�����
{
	if (root == NULL)
	{
		return;
	}
	PrintMidR(root->_pleft);
	printf("%c ", root->_data);
	PrintMidR(root->_pright);
}
void PrintBackR(TreeNode* root)//�������
{
	if (root == NULL)
		return;
	PrintBackR(root->_pleft);
	PrintBackR(root->_pright);
	printf("%c ", root->_data);
}
void PrintFront(TreeNode* root) //ǰ���ǵݹ�
{
	if (root == NULL)
		return;
	stack<TreeNode*> s;
	while (root|| !s.empty()) //rootΪ����ջΪ��ʱ�˳�ѭ��
	{
		while (root)  //�ҵ�����߷�Ҷ���
		{
			printf("%c ", root->_data);
			s.push(root);
			root = root->_pleft;
		}		
		root = s.top();
		root = root->_pright; //�ִӸý����ҽ�㿪ʼ����
		s.pop();
	}
}
void PrintMid(TreeNode* root)  //�и�����
{
	if (root == NULL)
		return;
	stack<TreeNode*> s;
	while (root || !s.empty())
	{
		while(root) //�ҵ������Ҷ���
		{
			s.push(root);  //��֮ǰ���洢����
			root = root->_pleft;
		}
		root = s.top();  
		printf("%c ", root->_data); //��ʱջ��Ԫ����Ҫ��ӡԪ��
		root = root->_pright; //�����Ըý����ҽ�㿪ʼ����
		s.pop(); //�ýڵ������ϣ���ջ����ʱ�Ѿ����ҽ�㱣����
	}
	printf("\n");
}
//�������˼���ǣ��ҵ������Ҷ��㣬
//����ý����ҽ��Ϊ�ջ����ҽ�㱻���ʹ�����ô�ʹ�ӡ�ý�㣬������Ը��ҽ��Ϊ����������
//��ô����Ҫһ���������洢֮ǰ�����ʵĽڵ�,

void PrintBack(TreeNode* root) //����ǵݹ����
{
	assert(root);
	TreeNode* cur = root;
	TreeNode* lasttop = cur;
	stack<TreeNode*> s;
	while (cur || !s.empty())
	{
		while (cur)  //�ҵ������Ҷ���
		{
			s.push(cur);
			cur = cur->_pleft;
		}
		TreeNode* top = s.top();
		while (top->_pright == NULL || top->_pright == lasttop)  //�ҽ��Ϊ�ջ��߱�����
		{
			cout << top->_data << " ";
			lasttop = s.top();  //��¼�����ʵĽڵ�
			s.pop();
			if (!s.empty())   
				top = s.top();
			else  //���ջΪ�գ�֤���ձ����ʵĽڵ��Ǹ����
				return;
		}
		if (top->_pright != NULL)  //�ҽ�㲻Ϊ�գ����ҽ��Ϊ������ѭ������
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