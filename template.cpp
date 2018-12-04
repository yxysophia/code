
//º¯ÊýÄ£°å

#include<iostream>

using namespace std;

template<class T>
void sort(T* a, int num)
{
	int flag = 1;
	for (int i = 1; i < num; i++)
	{
		for (int j = 0; j < num - i; j++)
		{
			if(a[j]>a[j+1])
			{
				flag = 0;
				T tmp = a[j];
			    a[j] = a[j + 1];
			    a[j + 1] = tmp;
			}
		}
		if (flag == 1)
			break;;
	}
}
int main()
{
	int a[] = { 10,9,8,7,6,5,4,3,2,1 };
	sort<int>(a, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	double d[] = { 2.2,3.4,5.6,1,1.4 };
	sort(d, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	char str[] = "HYANVC";
	sort<char>(str, strlen(str));
	for (int i = 0; i < strlen(str); i++)
	{
		cout << str[i] << " ";
	}
	system("pause");
	return 0;
}