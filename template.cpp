#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<assert.h>
using namespace std;
template<class T>
class Seqlist
{
public:
	Seqlist()  //���캯��
		:_array(NULL)
		,_capacity(0)
		,_size(0)
	{
	}
	//Seqlist(const Seqlist& s) //�������캯��
    Seqlist(const Seqlist<T>& s) //�������캯�������ͺ�����������
	{
		//���
		if (s._size != 0)
		{
			_array = new T[s._size]; //�ȿ�һ����ռ�
			memcpy(_array, s._array, sizeof(T)*s._size);
		}
		else
			_array = NULL;
		_capacity = _size = s._size;				
	}

	//Seqlist& operator=(const Seqlist& s) //��ֵ
	Seqlist<T>& operator=(const Seqlist<T>& s) //��ֵ
	{
		if (this != &s)
		{
			if (s._size != 0)
			{
				delete[] _array; //�Ѿɵ��ͷ�
				_array = new T[s._size];
				//memcpy(_array, s._array, sizeof(T)*s._size);
				for (size_t i = 0; i < s._size; i++)
				{
					_array[i] = s._array[i];  
					//�����string�࣬���Ǹ�ֵ��string�ĸ�ֵ�������ͬ�������insert���ݿ���
				}
			}
			else  //��s������û�����ݣ������this._array���ռ�,��ôthis_array���пռ䣬��s.arrayû�пռ䣬�Ͳ��Ǹ�ֵ
				_array = NULL;
			_capacity = _size = s._size;		
		}
		return *this;
	}

	//Seqlist<T>& operator=( Seqlist<T> s) //���������ͣ�Ҳ����������
	//Seqlist& operator=(Seqlist s)  //��ֵ���ִ�д��
	//{
	//	swap(_array, s._array);
	//	swap(_size, s._size);
	//	swap(_capacity, s._capacity);
	//	return *this;
	//    //����this��_array��s._array��������ô���˸�ջ֡�󣬶���s���������������ô�ɵ�_array�ᱻ�ͷ�
	//}

	void Insert(size_t pos,const T& x) //��posλ�ò���Ԫ��
	{
		assert(pos<=_size);//������_sizeλ�ò���Ԫ�أ��൱��β��
		if (_size == _capacity)  //��Ҫ����
		{
			if (_capacity == 0)
			{
				_capacity = 3;
			}
			else
			{
				_capacity = _capacity * 2;
			}
			T* newarray = new T[_capacity];
			/*memcpy(newarray, _array, sizeof(T)*_size);*/
			//�����������string�࣬��ע�͵Ŀ���������������ʱ��memcpy��ֵ������
			//��ô�µ�newarray���Ԫ�ػ�ָ����ͬ���ַ����ռ䣬
			//����delete[] _array������_array������string�࣬��Ҳ���������
			//��ô�ͻὫ����ָ����Ƕ��ַ����ռ��ͷŵ�,���ǵ�main��������ʱ��
			//��������������µ�_array���ٴ�������󣬾ͻ���ɶ�ͬһ�οռ�������ͷ�
			for (size_t i = 0; i < _size; i++)
			{
				newarray[i] = _array[i];//string��ĸ�ֵ�����
			}
			delete[] _array;
			_array = newarray;
		}
		size_t end = _size;
		while (end > pos)
		{
			_array[end] = _array[end - 1];
			end--;
		}
		_array[pos] = x;
		_size++;
	}
	void Erase(size_t pos) //ɾ��posλ��Ԫ��
	{
		assert(pos <= _size);
		size_t start = pos;
		while (start < _size - 1 )
		{
			_array[start] = _array[start + 1];
			start++;
		}
		_size--;
	}
	void PushBack(const T& x) //Ҳ�����Ԫ����string�࣬��Ҫ�����ã�����һ�ο���
	{
		Insert(_size, x);
	}
	void PushFront(const T & x)
	{
		Insert(0, x);
	}
	void PopBack()
	{
		Erase(_size);
	}
	T& operator[](size_t pos)
	{
		return _array[pos];//����������÷��أ�����ʱ��һ������const���Ե���ʱ������
		//��ô��[]�Ը�λ����д���ᱨ����Ϊ�������޸�һ�������Ե�ֵ������Ҫ�����ã����ر������Ϳ����޸�
	}
	size_t Size()
	{
		return _size;
	}
	~Seqlist() //��������
	{
		delete[] _array;
		_array = NULL;
		_capacity = _size = 0;
	}
private:
		T* _array;
		size_t _capacity;
		size_t _size;
};
void TestInt()
{
	Seqlist<int> s1;
	
	srand((unsigned)time(NULL));  //����ʱ�������
	for (int i = 0; i < 10; i++)
	{
		int num = rand() % 100;
		cout << num << " ";
		s1.PushBack(num);
	}

	cout << "\n";
	for (size_t i = 0; i < s1.Size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << "\n";
	s1.Erase(3);
	s1[0] = 10;
	s1.PopBack();
	s1.PushFront(1);
	for (size_t i = 0; i < s1.Size(); i++)
	{
		cout << s1[i] << " ";
	}
	printf("\n");
	Seqlist<int> s2(s1);
	for (size_t i = 0; i < s2.Size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << "\n";
	for (size_t i = 0; i < s2.Size(); i++)
	{
		cout << s2[i] << " ";
	}
	
	
}
void Test()
{
	Seqlist<int> s1;
	Seqlist<int> s2(s1);
	srand((unsigned)time(NULL));  //����ʱ�������
	for (int i = 0; i < 10; i++)
	{
		int num = rand() % 100;
		cout << num << " ";
		s2.PushBack(num);
	}
	printf("\n");
	for (size_t i = 0; i < s2.Size(); i++)
	{
		cout << s2[i] << " ";
	}
	printf("\n");
	Seqlist<int> s3;
	s3 = s1;
	s3.PushBack(3);
	for (size_t i = 0; i < s3.Size(); i++)
	{
		cout << s3[i] << " ";
	}

}
void TestString()
{
	Seqlist<string> s1;
	s1.PushBack("abcd");
	s1.PushBack("ab"); 
	s1.PushBack("mngg");
	s1.PushBack("loj");
	//s1.PushBack("logh");
	for (size_t i = 0; i < s1.Size(); i++)
	{
		cout << s1[i] << " ";
	}
	printf("\n");
	Seqlist<string> s2;
	s2 = s1;
	for (size_t i = 0; i < s2.Size(); i++)
	{
		cout << s2[i] << " ";
	}
}
int main()
{
	//TestInt();
	//Test();
	TestString();
	system("pause");
	return 0;
}

//˳���ģ��
//Seqlist ������
//Seqlist<T>������

//template<class T>
//class Seqlist 
//{
//public:
//	//Seqlist()  //˳���ģ��Ĺ��캯���������ﶨ�壬�õ�����
//	//	:_array(NULL)
//	//	,_capacity(0)
//	//	,_size(0)
//	//{
//	//}
//	Seqlist();//����������
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//template<class T>  //�������¶���һ����ģ������б�
//Seqlist<T>::Seqlist()//���캯�������ⶨ�壬�������<T>����������
//	:_array(NULL)
//	,_capacity(0)
//	,_size(0)
//{
//}
//
