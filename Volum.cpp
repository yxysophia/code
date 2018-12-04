#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>
using namespace std;

////1.对于类MyString, 要求重载‘ + ’运算符后可以计算表达式:a = b + c; 
////表示两个字符串连接。其中a, b, c都是类MyString的对象。
class MyString
{
public:
	MyString(char* str)  //深拷贝
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}
	MyString() 
		:_str(new char[1])//为了与delete[]保持一致
	{
		_str[0] = '\0';
	}
	MyString& operator+(const MyString& c)  //字符串连接
	{
		char* tmp = _str;
		_str = new char[strlen(tmp) + strlen(c._str) + 1];
		strcpy(_str, tmp);
		delete[] tmp;
		_str = strcat(_str, c._str);
		return *this;
	}
	MyString operator=(const MyString& s)  //赋值运算符重载
	{
		if (this!=&s)
		{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}
	~MyString()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}
	char * c_str()
	{
		return _str;
	}
private:
	char* _str;
};
int main()
{
	MyString a;
	MyString b("pick");
	MyString c("sophia");
	a = b + c;
	cout << a.c_str() << endl;
	system("pause");
	return 0;
}


//使用虚函数编写程序求球体和圆柱体的体积及表面积。
//由于球体和圆柱体都可以看作由圆继承而来，所以可以定义圆类Circle作为基类。
//在Circle类中定义一个数据成员radius和两个虚函数area()和volume()。
//由Circle类派生Sphere类和Column类。
//在派生类中对虚函数area()和volume()重新定义，分别求球体和圆柱体的体积及表面积

//圆类
const double PI = 3.1415926;

class Circle
{
public :
	Circle(double ridus)		
	{
		_ridus = ridus;
	}
	
	//虚函数area()
	virtual double area()
	{
		return 0.0;
	}
	virtual double volume()
	{
		return 0.0;
	}

protected:
	double _ridus;
};

class Sphere :public Circle
{
public :
	Sphere(double ridus)
		:Circle(ridus)
	{
	}
	//球类表面积 4PI*r^2
	double area()
	{
		return 4.0 * PI*_ridus*_ridus;
	}
	//球类体积 4/3*PI*r^3
	double volume()
	{
		return 4.0 * PI*_ridus*_ridus*_ridus / 3;
	}
};

class Column : public Circle
{
public:
	Column(double ridus,double height)
		:Circle(ridus)
	{
		_height = height;
	}
	//圆柱体表面积:2*底面积+侧面积(底面周长*高)
	double area()
	{
		return 2 * PI*_ridus*_ridus + 2 * PI*_ridus*_height;
	}
	//圆柱体体积 底面积*高
	double volume()
	{
		return PI*_ridus*_ridus*_height;
	}
private:
	double _height; //圆柱体的高
};
int main()
{
	//Circle *c1 = new Sphere(2.2);  //用父类指针或引用
	//cout <<"球类表面积"<< c1->area()<< endl;
	//cout << "球类体积" << c1->volume() << endl;

	//Circle*c2 = new Column(3.3, 4);
	//cout << "圆柱体表面积"<<c2->area() << endl;
	//cout << "圆柱体体积" << c2->volume() << endl;
	Circle *c;
	Sphere s(2.2);
	c = &s;  //切片处理
	cout << "球类表面积" << c->area() << endl;
	cout << "球类体积" << c->volume() << endl;

	Column co(3.3, 4);
	c = &co;
	cout << "圆柱体表面积"<<c->area() << endl;
	cout << "圆柱体体积" << c->volume() << endl;
	system("pause");
	return 0;
}