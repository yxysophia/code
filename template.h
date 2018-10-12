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
	Seqlist()  //构造函数
		:_array(NULL)
		,_capacity(0)
		,_size(0)
	{
	}
	//Seqlist(const Seqlist& s) //拷贝构造函数
    Seqlist(const Seqlist<T>& s) //拷贝构造函数用类型和类名都可以
	{
		//深拷贝
		if (s._size != 0)
		{
			_array = new T[s._size]; //先开一样大空间
			memcpy(_array, s._array, sizeof(T)*s._size);
		}
		else
			_array = NULL;
		_capacity = _size = s._size;				
	}

	//Seqlist& operator=(const Seqlist& s) //赋值
	Seqlist<T>& operator=(const Seqlist<T>& s) //赋值
	{
		if (this != &s)
		{
			if (s._size != 0)
			{
				delete[] _array; //把旧的释放
				_array = new T[s._size];
				//memcpy(_array, s._array, sizeof(T)*s._size);
				for (size_t i = 0; i < s._size; i++)
				{
					_array[i] = s._array[i];  
					//如果是string类，就是赋值，string的赋值是深拷贝，同理下面的insert扩容拷贝
				}
			}
			else  //即s对象里没有数据，如果给this._array开空间,那么this_array就有空间，而s.array没有空间，就不是赋值
				_array = NULL;
			_capacity = _size = s._size;		
		}
		return *this;
	}

	//Seqlist<T>& operator=( Seqlist<T> s) //可以用类型，也可以用类名
	//Seqlist& operator=(Seqlist s)  //赋值的现代写法
	//{
	//	swap(_array, s._array);
	//	swap(_size, s._size);
	//	swap(_capacity, s._capacity);
	//	return *this;
	//    //由于this的_array和s._array交换，那么出了该栈帧后，对象s会调析构函数，那么旧的_array会被释放
	//}

	void Insert(size_t pos,const T& x) //在pos位置插入元素
	{
		assert(pos<=_size);//可以在_size位置插入元素，相当于尾插
		if (_size == _capacity)  //需要扩容
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
			//如果数组里是string类，用注释的拷贝方法，当扩容时，memcpy是值拷贝，
			//那么新的newarray里的元素会指向相同的字符串空间，
			//但是delete[] _array后，由于_array里存的是string类，类也会完成清理，
			//那么就会将对象指向的那段字符串空间释放掉,但是当main函数结束时，
			//会调析构函数，新的_array会再次清理对象，就会造成对同一段空间的两次释放
			for (size_t i = 0; i < _size; i++)
			{
				newarray[i] = _array[i];//string类的赋值是深拷贝
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
	void Erase(size_t pos) //删除pos位置元素
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
	void PushBack(const T& x) //也许插入元素是string类，需要用引用，减少一次拷贝
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
		return _array[pos];//如果不用引用返回，返回时是一个具有const属性的临时变量，
		//那么用[]对该位置重写，会报错，因为不允许修改一个常属性的值，所以要用引用，返回别名，就可以修改
	}
	size_t Size()
	{
		return _size;
	}
	~Seqlist() //析构函数
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
	
	srand((unsigned)time(NULL));  //设置时间戳种子
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
	srand((unsigned)time(NULL));  //设置时间戳种子
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

//顺序表模板
//Seqlist 是类名
//Seqlist<T>是类型

//template<class T>
//class Seqlist 
//{
//public:
//	//Seqlist()  //顺序表模板的构造函数，在类里定义，用的类名
//	//	:_array(NULL)
//	//	,_capacity(0)
//	//	,_size(0)
//	//{
//	//}
//	Seqlist();//在类里声明
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//template<class T>  //必须重新定义一个类模板参数列表
//Seqlist<T>::Seqlist()//构造函数在类外定义，必须加上<T>，即用类型
//	:_array(NULL)
//	,_capacity(0)
//	,_size(0)
//{
//}
//
