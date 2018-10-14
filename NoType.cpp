#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<assert.h>
using namespace std;

//非类型的类模板参数

//template<class T, size_t max_size >
//template<class T, size_t max_size = 10>  //缺省非类型模板参数
template<class T, double  max_size >
class Seqlist
{
public:
	Seqlist(); //类内声明
private:
	T _array[max_size];
	size_t _size;

};
//template<class T, size_t max_size = 10>
template<class T, double max_size>
Seqlist<T, max_size>::Seqlist()  //类外定义构造函数，需要是类型
{
	_size = 0;
}

//非类型的模板函数参数
//template<class T,double value=4.1>   //错误，double和float不可作为非类型的类模板参数
template<class T, long value = 4>   //可以是long/int或其他类型
//template<class T,string value="pick">
T add(const T& a)
{
	return a + value;
}
int main()
{
	//Seqlist<int> q1;
	Seqlist<int, 5> q2;
	double a = 12.1;
	cout << add(a) << endl;
	system("pause");
	return 0;
}
