#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<assert.h>
using namespace std;

//�����͵���ģ�����

//template<class T, size_t max_size >
//template<class T, size_t max_size = 10>  //ȱʡ������ģ�����
template<class T, double  max_size >
class Seqlist
{
public:
	Seqlist(); //��������
private:
	T _array[max_size];
	size_t _size;

};
//template<class T, size_t max_size = 10>
template<class T, double max_size>
Seqlist<T, max_size>::Seqlist()  //���ⶨ�幹�캯������Ҫ������
{
	_size = 0;
}

//�����͵�ģ�庯������
//template<class T,double value=4.1>   //����double��float������Ϊ�����͵���ģ�����
template<class T, long value = 4>   //������long/int����������
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
