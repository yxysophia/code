#include<iostream>
#include<assert.h>
using namespace std;

class Data
{
public:
	void show()
	{
		cout << _year << '-' << _month << '-' << _day << endl;
	}
	int GetMonthDay(int year, int month)//返回该年月的最大天数
	{   //因为闰年的2月29，平年28天
		assert(year > 0 && month > 0 && month<13);
		int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//12个月的天数
		int day = Month[month];//直接得到天数
		if (month == 2 &&
			(year % 4 == 0 && year % 100 != 0) || year % 400 == 0)//判断是否是闰年
			day++;
		return day;
	}
	void SetData(int year, int month, int day)
	{
		if (year > 0 && month < 13 && month>0 &&
			GetMonthDay(year, month) >= day&&day > 0)
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
			cout << "非法日期" << endl;
	}
	//构造函数：
	//成员变量是私有的，要对他们进行初始化，必须用一个公有函数来进行
	//同时这个函数有且仅在定义对象时自动执行一次，这时调用的函数称为构造函数
	//构造函数是特殊的默认成员函数,特征如下：
	//1.函数名与类名相同
	//2.无返回值
	//3.对象实例化时系统自动调用对应的构造函数
	//4.构造函数可以重载
	//5.构造函数可以在类中定义也可以在类外定义
	//6.如果类定义中没有给构造函数，则c++编译器自动产生一个缺省(无参调用)的构造函数，但只要我们定义了一个构造函数，系统就不会自动生成缺省的构造函数
	//7.无参的缺省函数和全缺省的构造函数都认为是缺省构造函数，但缺省的构造函数只能有一个

	//Data()//无参构造函数
	//{
	//	_year = 1998;
	//	_month = 1;
	//	_day = 1;
	//}
	//无参构造函数和全缺省构造函数只能有一个
	Data(int year = 1998, int month = 1, int day = 1)//全缺省构造函数
	{
		if (year > 0 && month < 13 && month>0 &&
			GetMonthDay(year, month) >= day&&day > 0)
		{
			_year = year;
			_month = month;
			_day = day;
			cout << "构造函数" << endl;
		}
		else
			cout << "非法日期" << endl;

	}
	/*Data(int year, int month, int day)//带参构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
	/////析构函数
	//当一个对象的生命周期结束时，C++编译系统会自动调用一个成员函数，这个特殊的成员函数即析构函数
	//析构函数是特殊的默认成员函数，特征如下：
	//1.析构函数函数名在类名前加上字符~
	//2.析构函数无参数无返回值
	//3.一个类有且仅有一个析构函数。若类内未定义析构函数，系统会自动生成缺省的析构函数
	//4.对象生命周期结束时，系统会自动调用析构函数
	//5.析构函数并不是删除对象，而是完成一些清理工作（free、fclose)
	~Data()//析构函数  栈先进后出，先构造的对象后析构
	{
		cout << "析构函数" << endl;
	}
	////拷贝构造函数
	//创建对象时使用同类对象来进行初始化，这时所用的构造的函数为拷贝构造函数，
	//拷贝构造函数是特殊的默认的成员函数,特征如下：
	//1.拷贝构造函数其实是一个构造函数的重载
	//2.拷贝构造函数的参数必须用引用传参，使用传值方式可能会引发无穷递归调用
	//3.若类内没有拷贝构造函数，系统会默认缺省的拷贝构造函数。缺省的拷贝构造函数会依次拷贝类成员进行初始化
	Data(const Data& d)//必须引用做参数，尽量用const,不可修改
	{   //两个参数（Data *this,const Data &d)
		_year = d._year;//this->_year = d._day;
		_month = d._month;//this->_month = d._month;
		_day = d._day;//this->_day = d._day;
		cout << "值拷贝" << endl;
	}
	
	////运算符重载
	//特征:
	//1.operator+合法运算符构成函数名 （如：operator< )
	//2.重载运算符后不能改变运算符的优先级/结合性/操作符个数
	//3.注：5个不能重载的运算符: 1.(.*)   2.(::)  3.(sizeof)  4.(?.)   5.(.)
	// 赋值运算符重载：默认成员函数
	//赋值运算符重载和拷贝构造函数区别：
	//拷贝构造函数是创建的对象，使用一个已有的对象来初始化这个准备创建的对象
	//赋值运算符重载：对一个已存在的对象进行拷贝赋值
	Data& operator=(const Data& d)//返回对象出来作用域依然存在，最好用引用返回
	{  //即Data& operator =(Data* this, const Data& d)
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
			cout << "赋值拷贝" << endl;
		}
		return *this;
	}
	//>运算符重载
	bool operator>(const Data& d)
	{
		if (_year > d._year)
			return true;
		if (_year==d._year && _month > d._month)
			return true;
		if (_year == d._year&&_month == d._month&&_day > d._day)
			return true;
		else
			return false;
	}
    //>=运算符重载
	bool operator>=(const Data& d)
	{
		if (_year > d._year)
			return true;
		if (_year == d._year && _month > d._month)
			return true;
		if (_year == d._year&&_month == d._month&&_day >= d._day)
			return true;
		else
			return false;
	}
	//<运算符重载
	bool operator<(const Data& d)
	{
		if (_year < d._year)
			return true;
		if (_year == d._year && _month < d._month)
			return true;
		if (_year == d._year&&_month == d._month&&_day < d._day)
			return true;
		else
			return false;
	}
	//<=运算符重载
	bool operator<=(const Data& d)
	{
		if (_year < d._year)
			return true;
		if (_year == d._year && _month < d._month)
			return true;
		if (_year == d._year&&_month == d._month&&_day <= d._day)
			return true;
		else
			return false;
	}
	//==运算符重载
	bool operator==(const Data& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
			return true;
		else
			return false;
	}
	bool operator!=(const Data& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
			return false;
		else
			return true;
	}
	//+运算操作符
	Data operator+(int day)
	{
		_day += day;
		if (GetMonthDay(_year, _month) >= _day && day>0)//天数合法
			return *this;
		else
		{
			int maxday = GetMonthDay(_year, _month);
			while (maxday < _day)
			{
				_day = _day - maxday;
				_month += 1;
				if (_month == 13)
				{
					_month -= 12;
					_year += 1;
				}
				maxday = GetMonthDay(_year, _month);
			}
		}
		return *this;
	}
	//+=运算操作符
	Data& operator+=(int day)
	{
		_day += day;
		if (GetMonthDay(_year, _month) >= _day && day>0)//天数合法
			return *this;
		else
		{
			int maxday = GetMonthDay(_year, _month);
			while (maxday < _day)
			{
				_day = _day - maxday;
				_month += 1;
				if (_month == 13)
				{
					_month -= 12;
					_year += 1;
				}
				maxday = GetMonthDay(_year, _month);
			}
		}
		return *this;
	}
	//-运算操作符
	Data operator-(int day)
	{
		_day -= day;
		if ( day>0 )
			return *this;
		else
		{
			while (_day <= 0)
			{

			}
		}

	}


private://私有，类外部不能访问
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(1999, 1, 1);//调用带参构造函数 d1先构造
	Data d2;//调用无参或全缺省构造函数  d2后析构
	Data d3(d1);//或者Data d3 = d1; 两者都为值拷贝构造函数 d1拷给d3
	Data d4;
	d4.operator=(d1);//赋值运算符重载
	d4 = d1;//赋值运算符重载

	//d1.show();
	d1.SetData(2018, 6, 4);
	//d1.SetData(2018, 2, 28);
	Data d5(2018, 6, 28);
	/*if (d5 > d1)//>运算符重载
	{
		cout << "大于" << endl;
	}
	else
		cout << "不大于" << endl;*/
	/*if (d5 >= d1)//>=运算符重载
	{
		cout << "大于等于" << endl;
	}
	else
		cout << "小于" << endl;*/
	if (d5 == d1)//!=运算符重载
	{
		cout << "相等" << endl;
	}
	else
		cout << "不相等" << endl;
	d5 += (2);
	d5.show();

	/*Data d6=d5 + (10000);
	d6.show();*/
	/*d1.show();
	d3.show();
	d4.show();*/
	system("pause");
	return 0;
}

class Array
{
public:
	Array(int size)//构造函数
	{
		_ptr = (int *)malloc(sizeof(int)*size);
		cout << "构造函数" << endl;
	}
	//析构函数
	~Array()
	{
		free(_ptr);//释放动态申请空间
		cout << "析构函数" << endl;
	}
	///值拷贝构造函数
	//尽管当类内没有定义值拷贝构造函数，系统有默认缺省值拷贝值拷贝函数，但我们最好在类内给出值拷贝函数定义

private:
	int *_ptr;

};
//int main()
//{
//	Array a1(10);
//	Array a2(a1);//将a1拷给a1
//	a2.~Array();
//	a1.~Array();//会触发断点，即崩溃 
//	//因为将对象a1拷给对象a2，拷贝类成员即将对象a1指针ptr拷给了a2指针ptr,两个指针相同，但析构函数时free了两次，所以崩溃
//	//尽管当类内没有定义值拷贝构造函数，系统有默认缺省值拷贝值拷贝函数，但我们最好在类内给出值拷贝函数定义
//	system("pause");
//	return 0;
//}
