#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

//1. 一圆型游泳池如图1所示，现在需在其周围建一圆型过道，并在其四周围上栅栏。
//栅栏价格为35元 / 米，过道造价为20元 / 平方米。过道宽度为3米，游泳池半径由键盘输入。
//要求编程计算并输出过道和栅栏的造价。

int main()
{
	double r;
	cout << "请输入泳池半径:";
	scanf("%lf", &r);
	double c = 2 * 3.14*r;
	double LanMoney = c * 35; //栅栏价钱
	double s1 = 3.14*pow((r + 3), 2);
	double s2 = 3.14*pow(r, 2);
	double PassMoney = (s1 - s2) * 20;
	cout << "栅栏造价：" << LanMoney << endl;
	cout << "过道造价:" << PassMoney << endl;
	system("pause");
	return 0;
}


//2. 有三个学生组队参加某比赛，每个学生信息包含准考证号，姓名，个人成绩，另团队有一总成绩。
//1)	请写一学生类完成其定义实现。注意其中准考证号的不可变性，团队成绩的共享性；
//2)	编写主程序模拟生成三个学生给其赋值、完成相关信息的输出。
//基本要求
//能定义适当的类并定义对象完成设计并提交程序清单。

class Student
{
public:
	Student(string id="20160606001",string name="张三",float grade=80)
		:_id(id)
		,_name(name)
		,_grade(grade)
	{
		_total += _grade;
	}
	void print()
	{
		cout << "队员信息：" << _id << "-" << _name << "-" << _grade << endl;
		cout << "全队成绩:" << _total << endl;
	}	
private:
	string  _id;
	string _name;
	float _grade;
	static float _total;
};
float Student::_total = 0; //静态成员需要在类外初始化
int main()
{
	Student s1("201606060101", "小米", 70);
	Student s2("201606060124", "米尔头", 95);
	Student s3("201606060111", "米小豆", 90);
	s1.print();
	s2.print();
	s3.print();
	system("pause");
	return 0;
}