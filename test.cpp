#include<iostream>
using namespace std;
//////////////const成员函数
class Data1  //日期类 
{
public:
	Data1(int year=1998, int month=1, int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void show()
	{
		cout << "正常函数:" ;
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void show() const
	{
		cout << "const 修饰函数:" ;
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private: 
	int _year;
	int _month;
	int _day;
};

void test()
{
	Data1 d1(2018, 1, 1);    //调用非const成员函数
	const Data1 d2(2018, 6, 11);//调用const成员函数
	d1.show();//d1.show(&d1)->Data *
	d2.show();//d2.show(&d2)->const Data*
	system("pause");

}
/////inline(内联）

/////友元
//友元函数
class Time
{
	friend class Data2;  //类Data是类Time的友元，Data可以访问类Time任何变量
private:
	int _hour;
	int _minute;
	int _second;
};
class Data2
{
public:
	void show()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		//定义为友元类后，可以访问Time类对象的所有成员
		cout << "hour:" << _t._hour<< endl;//
		cout << "minute:" << _t._minute << endl;
		cout << "second:" << _t._second << endl;		
	}
	friend void Show(const Data2& d);//使类外函数show成为类的朋友，就可以访问私有成员变量
private:
		int _year;
		int _month;
		int _day;
		Time _t;//定义时间对象
};
void Show(const Data2& d)
{
	cout << d._year << "-" << d._month << "-" << d._day << endl;
}
int main()
{
	
	Data2 d1;
	d1.show();
	system("pause");
	return 0;

}

/////输入输出运算符重载
class Data3 
{
	friend ostream& /*void */ operator<<(ostream& os, const Data3& d);//友元函数
	friend istream& /*void*/ operator >> (istream& is, Data3& d); //友元函数
private:
	int _year;
	int _month;
	int _day;
};
ostream& /*void */ operator<<(ostream& os, const Data3& d) //将d输出到os中
//由于os，d都是对象，用引用少拷贝一次，且对象d不修改，用const修饰
//返回值可以是void 形参os是cout的别名，os改，cout也会改。
{
	os << "year:" << d._year << endl;
	os << "month:" << d._month << endl;
	os << "day:" << d._day << endl;
	return os;
}
istream& /*void*/ operator >> (istream& is, Data3& d) //输入到is中
{//由于os，d都是对象，用引用少拷贝一次，且对象d要修改，给其输入，不能用const修饰
 //返回值可以是void 形参is是cin的别名，is改，cin也会改。
	cout << "请分别输入年月日：" << endl;
	is >> d._year;
	is >> d._month;
	is >> d._day;
	return is;
}
int main()
{
	Data3 d1;
	cin >> d1;
	cout << d1;
	system("pause");
	return 0;
}
////静态成员的定义和使用
class Data
{
public:
	Data()//构造函数
	{
		++sCount;
	}
	static void PrintCount()//静态成员函数
	{
		cout << sCount << endl;
	}
private:
		int _year;
		int _month;
		int _day;
private:
	static int sCount;//静态成员变量声明，统计创建对象个数
};
int Data::sCount = 0;//定义并初始化静态成员变量
int main()
{
	Data d1;
	Data d2;
	d1.PrintCount();//2
	Data::PrintCount();//2
	//由于静态成员函数没有隐含this指针，所以可以使用类型::作用域访问符直接调用静态成员函数。
	//d2.PrintCount();//2
	system("pause");
	return 0;
}