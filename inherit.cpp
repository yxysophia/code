#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
//
//class Person
//{
//public:
//	void show(){
//		cout << "Person:" << _name<< endl;
//	}
//private:    
//	int _num;
//protected:
//	int _age;
//public:
//	string  _name;
//};
//class Student :public Person
//{
//public:
//	void show()
//	{
//		cout << _name << endl;
//		cout << _age << endl;  //基类protected限定符，在子类的类内可以访问
//		//cout << _num << endl; //编译错误，基类private限定符，在子类的类内也访问不了
//	}
//public:
//	int _classnum;
//};
//int main()
//{
//	Person p;
//	Student s;
//	s._name = "xiaoming";
//	//._age = 10;//编译错误，protected成员在类外访问不了
//	//s._num = 1;//编译错误，private成员在类外访问不了
//	s.show(); // 
//	system("pause");
//	return 0;
//}
//is-a
//class Rectangle  //矩形
//{
//protected:
//	int length;
//	int width;
//};
//class Squre :public Rectangle //正方形 两者是继承关系
//{
//
//};
////has-a
//class Eyes  //眼睛是头的一部分
//{
//protected:
//	char *clour;
//};
//class Head
//{
//	Eyes _eye;
//};


//class  person
//{
//public:
//	void show()
//	{
//		cout << _num << endl;
//	}
//public:
//	int _num;
//};
//class student :public person
//{
//public:
//	string _name;
//};
////int main()
//{
//	person p;
//	p._num = 1;
//	student s;
//	s._name = "wu";
//	s._num = 2;
//	//子类对象可以赋值给父类对象
	//p = s;

	//父类对象不可以赋值给子类对象
	//s = p; //编译错误

	//父类的指针/引用可以指向子类对象
	//person *p1 = &s; //父类p1指向子类中父类成员一部分，并不指向全部成员
	//person& p2 = s; //父类p2是子类中父类成员那一部分的别名，并不是全部的别名

	//子类的指针/引用不能指向父类对象
	//student *s1 = &p;  //编译错误
	//student& s2 = p;  //编译错误
	//强转后
	//student *s3 = (student *)&p;
	//student& s4 = (student& )p;
	//s3->_name = "hha"; //属于越界访问，会崩溃

	//RTTI
	/*person *ptr = &p;
	student* s5 = dynamic_cast<student*>(ptr);

	system("pause");
	return 0;

}*/


//继承体系的作用域

//class person
//{
//public:
//	void show()
//	{
//		cout << "父类：" << _num << endl;
//	}
//public:
//	string _name;
//	int _num;
//};
//class student :public person
//{
//public:
//	void show(int i)
//	{
//		cout << "子类：" << _num << endl;
//	}
//public:
//	int _num;
//};
//
//int main()
//{
//	person p;
//	student s;
//	s._num = 1;
//	s.show(); //子类：1
//	//如果子类是void show(int i),依然调用子类，对父类show隐藏，同名成员指函数名相同就可以，不看参数
//	s.show(10);//必须要写参数
//	s.person::_num = 2; //使用基类::基类成员访问
//	s.person::show(); //父类：2
//	system("pause");
//	return 0;
//}
class person
{
public:
	person(const person& p) //父类拷贝构造函数
		:_name(p._name)
		,_num(p._num)
	{
		cout << "person(const peson&p)"<<endl;
	}
	person(const char *name = " ",int num=0) //父类构造函数
		:_name(name)
		,_num(num)
	{
		cout << "person()" << endl;
	}
	person &operator=(const person& p) //赋值
	{
		cout << "person& operator=" << endl;
		if (this != &p)
		{
			_name = p._name;
			_num = p._num;
		}
		return *this;
	}
	~person()
	{
		cout << "~person()" << endl;
	}
protected:
	string _name;
	int _num;
	
	
};
//class student :public person
//{
//public:
//	student(const char *name=" ", int num=1, int age=1) //子类构造函数
//		:person(name, num)  //父类的构造在子类的初始化列表中调用
//	{
//		_age = age;
//		cout << "student()" << endl;
//	}
//	student(const student&s) //子类拷贝构造
//		:person(s)
//		,_age(s._age)
//	{
//		cout << "student(const student&s)" << endl;
//	}
//	
//	~student()
//	{
//		cout << "~student()" << endl;
//	}
//	student& operator=(const student&s)
//	{
//		cout << "student& operator=" << endl;
//		if (this != &s)
//		{
//			person::operator=(s); //调用基类赋值
//			_age = s._age;
//		}
//		return *this;
//	}
//public:
//	int _age;
//};
//int main()
//{
//	student s1("mao", 1, 10);
//	//student s2(s1);
//	//s1.~student();
//	//student s3;
//	//s3 = s1; 
//	s1.~student();
//	system("pause");
//	return 0;
//}

//单继承&多继承
//class Person
//{
//public:
//	string _name; //姓名
//	int _age;
//};
//class Student :virtual public Person
//{
//protected:
//	int _num; //学生学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _tid; //职工编号
//};
//class Assistant :public Student, public Teacher
//{
//protected:
//	string _majorCourse; //主修课程
//};
//class A
//{
//public:
//	int _a;
//};
//class B :  virtual  public A
//{
//public:
//	int _b;
//};
//class C : virtual public  A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	
//}
//继承与多态 
//class Person
//{
//public:
//	virtual void BuyTickets()
//	{
//		cout << "成人买票" << endl;
//	}
//protected:
//	string _name;
//};
//class Student: public Person
//{
//public:
//	virtual void BuyTickets()
//	{
//		cout << "学生买票" << endl;
//	}
////protected:
//	int _num;
//};
//// 调用重写的虚函数时，参数必须是基类的指针或引用.
//// 函数调用和对象有关，指向谁，调用谁的虚函数。当指向父类调用的就是父类的虚函数，当指向子类调用的就是子类的虚函数
//void  Buy1(Person* p)  
//{
//	p->BuyTickets();
//}
//void Buy2(Person &p)  
//{
//	p.BuyTickets();
//}
//void Buy3(Person p)
//{
//	p.BuyTickets();
//}
//int main()
//{
//	Person p;
//	Student s;
//	p.BuyTickets();
//	s.BuyTickets();
//	//基类是指针：必须要&
//	Buy1(&p);  // 成人买票  
//	Buy1(&s);  // 学生买票
//
//	//基类是引用
//	Buy2(p);   // 成人买票
//	Buy2(s);   // 学生买票
//
//	//基类既不是指针也不是引用
//	Buy3(p);   //成人买票
//	Buy3(s);   //成人买票
//	system("pause");
//	return 0;
//}
//
///////////////////////////////////////
////class Person
////{
////public:
//	 void BuyTickets()
//	{
//		cout << "成人买票" << endl;
//	}
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name;
//};
//class Student: public Person
//{
//public:
//	void BuyTickets()
//	{
//		cout << "学生买票" << endl;
//	}
//	 ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num;
//};
//
//void  Buy(Person& p)  
//{
//	p.BuyTickets();
//}
//
//int main()
//{
//	/*Person p;
//	Student s;
//	p.BuyTickets();
//	s.BuyTickets();
//	Buy(p);
//	Buy(s);*/
//	Person *p = new Student(); // 开Student类的空间，call子类构造函数，基类指向这段空间
//	delete p;  //先析构，再free
//	system("pause");
//	return 0;
//}
//

//class A
//{
//public:
//	virtual void fun1()
//	{
//		cout << "A::fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "A::fun2()" << endl;
//	}
//public:
//	int _a;
//};
//class B : public A
//{
//	//子类会继承父类的fun1()函数
//	virtual void fun2()  //子类func2()会覆盖父类fun2()
//	{
//		cout << "B::fun2()" << endl;
//	}
//	virtual void fun3()
//	{
//		cout << "B::fun3()" << endl;
//	}
//	void fun4()  //fun4()不是虚函数
//	{
//		cout << "B::fun3()" << endl;
//	}
//};
//typedef void(*FUNC)();   
//
//void printVtable(int *vfter)  
//{
//	cout << "虚表地址：" << vfter << endl;
//	for (int i = 0; vfter[i] != 0; i++) //因为虚表最后一个元素是0
//	{
//		printf("第%d个虚函数地址：0x%x,->", i, vfter[i]);
//		FUNC f = (FUNC)vfter[i]; 
//		f(); //调用该虚函数
//	}
//	cout << endl;
//}
//
//int main()
//{
//	A a1;
//	B b1;
//	int *vfter1 = (int*)(*(int*)(&a1));  //vfter是虚表地址
//	int *vfter2 = (int*)(*(int*)(&b1));
//	printVtable(vfter1);
//	printVtable(vfter2);
//	system("pause");
//	return 0;
//}
//class Person
//{
//public:
//	virtual Person& print()
//	{
//		cout << "Person" << endl;
//		return *this;
//	}
//protected:
//	string _str;
//
//};
//class Student :public Person
//{
//public:
//	Student& print()
//	{
//		cout << "Student" << endl;
//		return *this;
//	}
//protected:
//	string _num;
//};
//void func(Person& p)
//{
//	p.print();
//}
//int main()
//{
//	Person p;
//	Student s;
//	func(p);
//	func(s);
//	system("pause");
//	return 0;
//}

//class A
//{
//public:
//	virtual void func1()
//	{
//		cout << "A::func1()" << endl;
//	}
//	void display()
//	{
//		cout << "A::display()" << endl;
//	}
//	void display(int i)
//	{
//		cout << "A::display(int i)" << endl;
//	}
//protected:
//	int _a;
//};
//
//class B : public A
//{
//public:
//	virtual void func1()
//	{
//		cout << "B::func1()" << endl;
//	}
//protected:
//	int _b;
//};
//
//void func(A& a)
//{
//	a.func1(); //动态多态
//	a.display();  //函数重载 即静态多态
//	a.display(10);
//}
//
//
//int main()
//{
//	A a;
//	B b;
//	func(a);
//	func(b);
//	system("pause");
//	return 0;
//}
///////////////////纯虚函数
//class A
//{
//public:
//	virtual void print() = 0;
//private:	
//	string _str;
//
//};
//class B : public A
//{
//public:
//	virtual void print() {
//		cout << "print" << endl;
//	}
//};
////纯虚函数
////在成员虚函数的形参后面加上=0，则成员函数为纯虚函数。包含纯虚函数的类称为抽象类（接口类），抽象类不能实例化对象。
////但是纯虚函数在派生类中重新定义后，派生类可以实例化出对象，但是基类还是不能实例化对象。
//int main()
//{
//	B b; //派生类可以实例化出对象
//	A a;  //基类不能实例化出对象
//}
//

////////////多继承多态

//class A
//{
//public:
//	virtual void func1()
//	{
//		cout << "A::func1()" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "A::func2()" << endl;
//	}
//protected:
//	int _a;
//};
//class B
//{
//public:
//	virtual void func1()
//	{
//		cout << "B::func1()" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "B::func2()" << endl;
//	}
//protected :
//	int _b;
//};
//class C : public A, public B
//{
//public:
//	virtual void func1()
//	{
//		cout << "C::func1()" << endl;
//	}
//	virtual void func3()
//	{
//		cout << "C::func3()" << endl;
//	}
//protected :
//	int _c;
//
//};
//typedef void(*FUNC)(); //声明一个函数指针类型FUNC
//
//void printTable(int *vfptr)
//{
//	printf("vtable address:%p\n", vfptr);
//	for (int i = 0; vfptr[i] != 0; i++)
//	{
//		printf("第%d个虚函数地址:%p->", i, vfptr[i]);
//		FUNC f = (FUNC)(vfptr[i]);
//		f();  //调用这个函数
//	}
//	printf("\n");
//}

//int main()
//{
//	C c;
//	c.func1();
//	
//	cout<<sizeof(c)<<endl;
//	//因为c有两个直接父类：A和B
//	int *vfptr1 = (int*)(*((int*)(&c)));
//	printTable(vfptr1);
//	//因为第二个虚表指针存放在第一个父类成员变量下边，所以第二个虚表指针在&c后需要加上第一个父类的大小，
//	//但是由于指针+1，加的是所指类型的大小，所以需要把&a强转为char*,或者+sizeof(A)/4,
//	int *vfptr2 = (int*)(*(int*)(((char*)(&c)) + sizeof(A))); 
//	printTable(vfptr2);
//	system("pause");
//	return 0;
//}

/////////////虚基表和虚表
class A
{
public:
	virtual void f1()
	{
		cout << "A::f1()" << endl;
	}
	virtual void f2()
	{
		cout << "A::f2()" << endl;
	}
public:
	int _a;
};
class B :virtual public A
{
public:
	virtual void f1()  //重写虚函数
	{
		cout << "B::f1 ()" << endl;
	}
	virtual void f3()  // B重新定义的虚函数
	{
		cout << "B::f3()" << endl;
	}
	//另外B继承了A的f2函数
public:
	int _b;
};
class  C : virtual public A
{
public:
	virtual void f1()  // C重写了虚函数f1
	{
		cout << "C::f1()" << endl;
	}
	virtual void f3()  // C重新定义了虚函数f3
	{
		cout << "C::f3()" << endl;
	}
	//另外C继承了A的虚函数f2
public:
	int _c;
};
class D : public B, public C
{
public:
	virtual void f1()
	{
		cout << "D::f1()" << endl;
	}
	virtual void f4()
	{
		cout << "D::f4()" << endl;
	}
public:
	int _d;
};
typedef void(*FUNC)();

void printVtable(int *vfter)
{
	cout << "虚表地址：" << vfter << endl;
	for (int i = 0; vfter[i] != 0; i++) //因为虚表最后一个元素是0
	{
		printf("第%d个虚函数地址：0x%x,->", i, vfter[i]);
		FUNC f = (FUNC)vfter[i];
		f(); //调用该虚函数
	}
	cout << endl;
}
int main()
{
	D d;
	d._a = 1;
	d._b = 2;
	d._c = 3;
	d._d = 4;
	cout << sizeof(d) << endl;
	int *vfptr1 = (int*)(*((int*)(&d))); //B 的虚表指针
	printVtable(vfptr1);
	int *vfptr2 = (int*)(*((int*)(((char*)(&d)) + 12)));//  C的虚表指针
	printVtable(vfptr2);
	int *vfptr = (int*)(*((int*)(((char*)(&d)) + 28)));  //  公共虚表指针
	printVtable(vfptr);
	system("pause");
	return 0;
}