#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

typedef int Datatype;
class  Vector
{
public:
	Vector()//构造
		:_first(NULL)
		, _finish(NULL)
		, _endofstorage(NULL)
	{
	}

	~Vector()//析构
	{
		if (_first)
		{
			delete[] _first;
			_first = NULL;
			_finish = NULL;
			_endofstorage = NULL;
		}

	}
	Vector(const Vector& v)//拷贝构造
	{
		_first = new Datatype[v.Size()];
		_finish = _first + v.Size();
		_endofstorage = _first + v.Size();
		memcpy(_first, v._first, sizeof(Datatype)*v.Size());
	}
	Vector& operator=(Vector v)
	{
		//现代写法
		swap(_first, v._first);
		swap(_finish, v._finish);
		swap(_endofstorage, v._endofstorage);
		return *this;
	}
	size_t Size() const
	{
		return _finish - _first;
	}
	size_t Capacity() const
	{
		return _endofstorage - _first;
	}
	void Reverse(size_t n) //单纯扩容
	{
		if (n > Capacity())
		{
			Expand(n);
		}
	}
	void Resize(size_t n,Datatype value)//扩容并且初始化 
	{
		if (n < Size())//缩容
		{
			_finish = _first + n;
		}
		else
		{
			if (n > Capacity())//先扩容
			{
				Expand(n);
			}
			Datatype* end = _first + n;
			while (_finish < end)
			{
				*_finish = value;
				++_finish;
			}
		}
	}
	void PushBack(Datatype x)//尾插
	{
		/*if (_finish == _endofstorage)
		{
			if (Capacity() == 0)
				Expand(3);
			else
				Expand(Capacity() * 2);
		}
		*_finish = x;
		++_finish;*/
		Insert(_finish, x);
	}    
	void PopBack()//尾删
	{
		/*if (_finish != _first)
		{
			_finish--;
		}*/
		Erase(_finish - 1);
	}
	Datatype *Find(Datatype x)   
	{
		Datatype *cur = _first;
		while (cur != _finish)
		{
			if (*cur == x)
				return cur;
			else
				cur++;
		}
		return NULL;
	}
	void Insert(Datatype *pos, Datatype x)//在pos前插入元素
	{
		int num = pos - _first;
		if (_finish == _endofstorage)//需要扩容
		{
			if (_finish == NULL)
				Expand(3);//一个元素都没有，可以先开3个空间
			else
				Expand(Capacity() * 2);
				pos = _first + num;//注意pos发生变化
		}
		Datatype *tmp = _finish;
		while (tmp > pos)
		{
			*tmp = *(tmp - 1);
			tmp--;
		}
		*pos = x;
		_finish++;
	}
	void Erase(Datatype *pos)//在pos位置删除元素
	{
		assert(_first <= pos&&pos < _finish);
		while (pos < (_finish - 1))
		{
			*pos = *(pos + 1);
			pos++;
		 }
		_finish--;
	}
	Datatype& operator[](size_t n)
	{
		return _first[n];
	}
	void Print()
	{
		Datatype *cur = _first;
		while (cur!=_finish)
		{
			printf("%d ", *cur);
			cur++;
		}
		printf("\n");
	}
private:
	void Expand(size_t n)
	{
		if (n > Capacity())
		{
			size_t size = Size();//需要先保存起来
			Datatype *tmp = new Datatype[n];
			memcpy(tmp, _first, sizeof(Datatype)*size);
			delete[] _first;
			_first = tmp;
			_finish = _first + size;
			_endofstorage = _first + n;
		}
	}
private:
	Datatype *_first;
	Datatype *_finish;
	Datatype *_endofstorage;
};


//int main()
//{
//	Vector v1;
//	v1.PushBack(4);
//	v1.PushBack(5);
//	v1.PopBack();
//	v1.Print();
//	v1.Insert(v1.Find(4), 1);
//	v1.Insert(v1.Find(1), 10);
//	v1.Print();
//	v1.Erase(v1.Find(4));
//	v1.Print();
//	Vector v2(v1);
//	v2.Print();
//	system("pause");
//	return 0;
//}
//c++是自动调构造函数，自动调析构进行清理，面向对象
//c面向过程
