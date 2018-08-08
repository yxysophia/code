#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
//将字符串转为整数
//int main()
//{
//	string str("     12345");
//	int index = 0;
//	//先处理空格
//	while (index < str.size())
//	{
//		if (str[index] == ' ')
//			index++;
//		else
//			break;
//	}
//	int flag = 1;
//	if (str[index] == '+')
//	{
//		index++;
//		flag = 1;
//	}
//	if (str[index] == '-')
//	{
//		index++;
//		flag = -1;
//	}
//	int value = 0;
//	while (index<str.size())
//	{
//		if (str[index] >= '0'&&str[index] <= '9')
//		{
//			value = value * 10 + (str[index] - '0');
//			index++;
//		}
//		//不合法数值表达式直接返回
//		else
//			return 0;
//	}
//	printf("%d\n", value*flag);
//	system("pause");
//	return 0;
//}
typedef int Datatype;
class Myvector
{
public:
	Myvector(int n)//构造函数
	{
		_a = new Datatype[n];
		_size = 0;
		_capacity = n;
	}
	Myvector(const Myvector& v)//拷贝构造
	{
		_a = new Datatype[v._size];
		memcpy(_a, v._a, sizeof(Datatype)*v._size);
		_size = v._size;
		_capacity = v._capacity;
	}
	Myvector& operator=( Myvector v)//赋值
	{
		//用现代写法
		if (this != &v)
		{
			swap(_a, v._a);
			swap(_size, v._size);
			swap(_capacity, v._capacity);
		}
		return *this;
	}
	void PushBack(const Datatype& x)//尾插,用引用是因为Datatype可能是字符串
	{
		if (_size == _capacity)//扩容
		{
			_capacity *= 2;
			_a = (Datatype*)realloc(_a,sizeof(Datatype)*_capacity);
		  
		}
		_a[_size] = x;
		_size++;
	}
	void PopBack()//尾删
	{
		if (_size > 0)
		{
			_size--;
		}
	}
	void Insert(size_t pos,  const Datatype& x)
	{
		assert(pos >= 0 && pos <= _size);
		if (_size == _capacity)
		{
			_capacity *= 2;
			Datatype* a = new Datatype(_capacity);
			memcpy(a, _a, sizeof(Datatype)*_size);
			_a = a;
			//_a = (Datatype*)realloc(_a, sizeof(Datatype)*_capacity);
		}
		size_t index = _size;
		while (index > pos)
		{
			_a[index] = _a[index - 1];
			index--;
		 }
		_a[pos] = x;
		_size++;
	}
	void Erase(size_t pos)
	{
		assert(pos >= 0 && pos < _size);
		int index = pos;
		while (index < _size-1)
		{
			_a[index] = _a[index + 1];
			index++;
		}
		_size--;
	}
	Datatype& operator[](size_t pos)
	{
		return _a[pos];
	}
	~Myvector()
	{
		if (_a)
		{
			delete[]_a;
			_a = NULL;
			_size = 0;
			_capacity = 0;
		}
	}
	void print()
	{
		for (int index = 0; index < _size; index++)
			printf("%d ", _a[index]);
		printf("\n");
	}
private:
	Datatype* _a;
	size_t _size;
	size_t _capacity;
};
//int main()
//{
//	Myvector v1(4);
//	v1.PushBack(2);
//	v1.PushBack(3);
//	v1.PushBack(4);
//	v1.Insert(3, 5);
//	v1.Insert(2, 8);
//	v1.print();
//	v1.PopBack();
//	v1.print();
//	v1.Erase(1);
//	v1.print();
//	Myvector v2(v1);
//	v2.print();
//	printf("%d\n", v1.operator[](2));
//	system("pause");
//	return 0;
//}