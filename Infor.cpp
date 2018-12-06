#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


template <class T>
void Swap(T& a, T&b)
{
	T t = a;
	a = b;
	b = t;
}
int main()
{
	int a = 10;
	int b = 2;
	Swap(a, b);
	cout << "a=" << a << "b="<<b;
	double c = 1.2;
	double d = 3.4;
	Swap(c, d);
	cout << "c=" << c << "d=" << d;
	system("pause");
	return 0;
}
//const int N = 3;//学生数
//const int M = 4;//课程数
//void Input(char (*name)[20], int (*score)[M], int n)
//{
//	int i, j;
//	cout << "Input 3 stu" << " name:\n";
//	for (i = 0; i<N; i++)
//		cin.getline(name[i], 20);
//	for (i = 0; i<N; i++)
//	{
//		cout << "Input stu" << i + 1 << " 4 scores\n";
//		for (j = 0; j<M; j++)
//			cin >> score[i][j];
//	}
//
//}
//void main()
//{
//	//1
//	char name[N][20] = { "\0" };
//	int i, j, score[N][M] = { 0 };
//	int t[N] = { 0 };
//	float aver[M] = { 0 };
//	//2
//	Input(name, score, N);
//	//3-1
//	for (i = 0; i<N; i++)
//	{
//		for (j = 0; j<M; j++)
//			t[i] = t[i] + score[i][j];
//	}
//	//3-2
//	for (j = 0; j<M; j++)
//	{
//		for (i = 0; i<N; i++)
//			aver[j] = aver[j] + score[i][j];
//		aver[j] /= N;
//
//	}
//
//
//	//4
//	cout << setw(10) << "name";
//	cout << setw(6) << "sc1";
//	cout << setw(6) << "sc2" << setw(6) << "sc3" << setw(6) << "sc4" << setw(6) << "Total" << endl;
//	for (i = 0; i<N; i++)
//	{
//		cout << setw(10) << name[i];
//		for (j = 0; j<M; j++)
//			cout << setw(6) << score[i][j];
//		cout << setw(6) << t[i];
//		cout << endl;
//	}
//	cout << setw(10) << "aver";
//	for (j = 0; j<M; j++)
//		cout << setw(6) << aver[j];
//	cout << endl;
//}
