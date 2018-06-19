#include<iostream>
using namespace std;

class Array
{
public:
	Array(int size = 10)
		:_size(size)
		, _a(0)
	{
		cout << "构造" << endl;
		if (_size > 0)
		{  
			_a = new int[_size];
		}
	}
	~Array()
	{
		cout << "析构" << endl;
		if (_a) 
		{
			delete[] _a;
			_a = 0;//置空
			_size = 0;
		}
   }
	
private:
	int* _a;
	int _size;
};
//int main()
//{
//	// malloc/free + 定位操作符new()/显示调用析构函数，模拟 new和delete 的行为 
//	Array* p1 = (Array*)malloc(sizeof(Array));     
//	new(p1) Array(100);
//
//	p1->~Array();  
//	free(p1);
//
//	// malloc/free + 多次调用定位操作符new()/显示调用析构函数，模拟 new[]和delete[] 的行为 
//	Array* p2 = (Array*)malloc(sizeof(Array) * 10);//10个对象
//	for (int i = 0; i < 10; i++)
//	{
//		new(p2 + i)Array;//需要将10个对象都构造初始化
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		(p2+i)->~Array;//先调用析构清理10个对象
//	}
//	free(p2);//再整体释放空间
//}
int main()
{
	Array* p1 = (Array *)malloc(sizeof(Array));
	//申请了对象p1的空间，并没有申请_a的空间
	Array* p2 = new Array; //申请_a的空间，并将_size初始化为10
	Array* p3 = new Array(20);//申请将__a的空间，size初始化为20
	cout << "new:p4" << endl;
	Array* p4 = new Array[3];//调三次构造函数
	//p4相当于数组，数组里存3个Array对象，每个对象的_a都申请了空间，_size都为10
	cout << "*******" << endl;
	free(p1);
	delete p2;
	delete p3;
	cout << "delete: p4" << endl;
	delete[] p4;//调了三次析构函数
	int *p6 = new int[3];//数组里3个int类型数据
	delete p6;
	system("pause");
	return 0;
   
}
void test()
{
Array *p3 = new Array;
delete[]p3; //有问题，会朝前清理4个字节

Array *p4 = new Array[10];
delete p4;//有问题，没有将多开四个字节空间释放
}