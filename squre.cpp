#include<iostream>
#include<vector>

using namespace std;
vector<int> printMatrix(vector<vector<int> > a)
{
	vector<int> res;
	//定义四个变量，分别是上下 左右的边界
	int top = 0, left = 0;
	int right = a[0].size() - 1;
	int bottom = a.size() - 1;
	int i = 0;
	//假如只有一个元素，left=0,right=0,top=0,bottom=0;
	while (left <= right&&top <= bottom)
	{
		//每次循环缩小区间
		//从左向右
		for (i = left; i <= right; i++)
		{
			res.push_back(a[top][i]);
		}
		top++; //上面一行就完毕
		//从上向下
		for (i = top; i <= bottom; i++)
		{
			res.push_back(a[i][right]);
		}
		right--; //右边一列就完毕
		//从右向左，
		//注意这里需要top<=bottom  如果是1*5二维vector{1,2,3,4,5},到这里，top=1,right=3,left=0,bottom=0,
		//虽然left<right,但是bottmo不大于top,所以需要加上top<=bottom
		for (i = right; i >= left&&top<=bottom; i--)
		{
			res.push_back(a[bottom][i]);
		}
		bottom--; //下边一行就完毕
		//从下向上
		//注意这里需要left<=right,如果是5*1二维vector{{1},{2},{3},{4},{5}},到这里，top=1,right=-1,left=0,bottom=4
		//虽然top<bottom,但是right不大于left,所以需要退出循环即加上left<=right
		for (i = bottom; i >= top&&left<=right; i--)
		{
			res.push_back(a[i][left]);
		}
		left++; //左边一列就完毕
	}
	return res;
}
int main()
{
	vector<vector <int> >a(5, vector<int>(1)); //5*1的二维vector
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