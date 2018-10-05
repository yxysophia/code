#include<iostream>
#include<vector>

using namespace std;
vector<int> printMatrix(vector<vector<int> > a)
{
	vector<int> res;
	//�����ĸ��������ֱ������� ���ҵı߽�
	int top = 0, left = 0;
	int right = a[0].size() - 1;
	int bottom = a.size() - 1;
	int i = 0;
	//����ֻ��һ��Ԫ�أ�left=0,right=0,top=0,bottom=0;
	while (left <= right&&top <= bottom)
	{
		//ÿ��ѭ����С����
		//��������
		for (i = left; i <= right; i++)
		{
			res.push_back(a[top][i]);
		}
		top++; //����һ�о����
		//��������
		for (i = top; i <= bottom; i++)
		{
			res.push_back(a[i][right]);
		}
		right--; //�ұ�һ�о����
		//��������
		//ע��������Ҫtop<=bottom  �����1*5��άvector{1,2,3,4,5},�����top=1,right=3,left=0,bottom=0,
		//��Ȼleft<right,����bottmo������top,������Ҫ����top<=bottom
		for (i = right; i >= left&&top<=bottom; i--)
		{
			res.push_back(a[bottom][i]);
		}
		bottom--; //�±�һ�о����
		//��������
		//ע��������Ҫleft<=right,�����5*1��άvector{{1},{2},{3},{4},{5}},�����top=1,right=-1,left=0,bottom=4
		//��Ȼtop<bottom,����right������left,������Ҫ�˳�ѭ��������left<=right
		for (i = bottom; i >= top&&left<=right; i--)
		{
			res.push_back(a[i][left]);
		}
		left++; //���һ�о����
	}
	return res;
}
int main()
{
	vector<vector <int> >a(5, vector<int>(1)); //5*1�Ķ�άvector
	int k = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			a[i][j] = k;
			k++;
		}
	}
	// a:{{1},{2},{3},{4},{5}}
	printMatrix(a);
}