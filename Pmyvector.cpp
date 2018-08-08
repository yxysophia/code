#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

typedef int Datatype;
class  Vector
{
public:
	Vector()//����
		:_first(NULL)
		, _finish(NULL)
		, _endofstorage(NULL)
	{
	}

	~Vector()//����
	{
		if (_first)
		{
			delete[] _first;
			_first = NULL;
			_finish = NULL;
			_endofstorage = NULL;
		}

	}
	Vector(const Vector& v)//��������
	{
		_first = new Datatype[v.Size()];
		_finish = _first + v.Size();
		_endofstorage = _first + v.Size();
		memcpy(_first, v._first, sizeof(Datatype)*v.Size());
	}
	Vector& operator=(Vector v)
	{
		//�ִ�д��
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
	void Reverse(size_t n) //��������
	{
		if (n > Capacity())
		{
			Expand(n);
		}
	}
	void Resize(size_t n,Datatype value)//���ݲ��ҳ�ʼ�� 
	{
		if (n < Size())//����
		{
			_finish = _first + n;
		}
		else
		{
			if (n > Capacity())//������
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
	void PushBack(Datatype x)//β��
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
	void PopBack()//βɾ
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
	void Insert(Datatype *pos, Datatype x)//��posǰ����Ԫ��
	{
		int num = pos - _first;
		if (_finish == _endofstorage)//��Ҫ����
		{
			if (_finish == NULL)
				Expand(3);//һ��Ԫ�ض�û�У������ȿ�3���ռ�
			else
				Expand(Capacity() * 2);
				pos = _first + num;//ע��pos�����仯
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
	void Erase(Datatype *pos)//��posλ��ɾ��Ԫ��
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
			size_t size = Size();//��Ҫ�ȱ�������
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
//c++���Զ������캯�����Զ����������������������
//c�������
