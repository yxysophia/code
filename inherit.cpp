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
//		cout << _age << endl;  //����protected�޶���������������ڿ��Է���
//		//cout << _num << endl; //������󣬻���private�޶����������������Ҳ���ʲ���
//	}
//public:
//	int _classnum;
//};
//int main()
//{
//	Person p;
//	Student s;
//	s._name = "xiaoming";
//	//._age = 10;//�������protected��Ա��������ʲ���
//	//s._num = 1;//�������private��Ա��������ʲ���
//	s.show(); // 
//	system("pause");
//	return 0;
//}
//is-a
//class Rectangle  //����
//{
//protected:
//	int length;
//	int width;
//};
//class Squre :public Rectangle //������ �����Ǽ̳й�ϵ
//{
//
//};
////has-a
//class Eyes  //�۾���ͷ��һ����
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
//	//���������Ը�ֵ���������
	//p = s;

	//������󲻿��Ը�ֵ���������
	//s = p; //�������

	//�����ָ��/���ÿ���ָ���������
	//person *p1 = &s; //����p1ָ�������и����Աһ���֣�����ָ��ȫ����Ա
	//person& p2 = s; //����p2�������и����Ա��һ���ֵı�����������ȫ���ı���

	//�����ָ��/���ò���ָ�������
	//student *s1 = &p;  //�������
	//student& s2 = p;  //�������
	//ǿת��
	//student *s3 = (student *)&p;
	//student& s4 = (student& )p;
	//s3->_name = "hha"; //����Խ����ʣ������

	//RTTI
	/*person *ptr = &p;
	student* s5 = dynamic_cast<student*>(ptr);

	system("pause");
	return 0;

}*/


//�̳���ϵ��������

//class person
//{
//public:
//	void show()
//	{
//		cout << "���ࣺ" << _num << endl;
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
//		cout << "���ࣺ" << _num << endl;
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
//	s.show(); //���ࣺ1
//	//���������void show(int i),��Ȼ�������࣬�Ը���show���أ�ͬ����Աָ��������ͬ�Ϳ��ԣ���������
//	s.show(10);//����Ҫд����
//	s.person::_num = 2; //ʹ�û���::�����Ա����
//	s.person::show(); //���ࣺ2
//	system("pause");
//	return 0;
//}
class person
{
public:
	person(const person& p) //���࿽�����캯��
		:_name(p._name)
		,_num(p._num)
	{
		cout << "person(const peson&p)"<<endl;
	}
	person(const char *name = " ",int num=0) //���๹�캯��
		:_name(name)
		,_num(num)
	{
		cout << "person()" << endl;
	}
	person &operator=(const person& p) //��ֵ
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
//	student(const char *name=" ", int num=1, int age=1) //���๹�캯��
//		:person(name, num)  //����Ĺ���������ĳ�ʼ���б��е���
//	{
//		_age = age;
//		cout << "student()" << endl;
//	}
//	student(const student&s) //���࿽������
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
//			person::operator=(s); //���û��ำֵ
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

//���̳�&��̳�
//class Person
//{
//public:
//	string _name; //����
//	int _age;
//};
//class Student :virtual public Person
//{
//protected:
//	int _num; //ѧ��ѧ��
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _tid; //ְ�����
//};
//class Assistant :public Student, public Teacher
//{
//protected:
//	string _majorCourse; //���޿γ�
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
//�̳����̬ 
//class Person
//{
//public:
//	virtual void BuyTickets()
//	{
//		cout << "������Ʊ" << endl;
//	}
//protected:
//	string _name;
//};
//class Student: public Person
//{
//public:
//	virtual void BuyTickets()
//	{
//		cout << "ѧ����Ʊ" << endl;
//	}
////protected:
//	int _num;
//};
//// ������д���麯��ʱ�����������ǻ����ָ�������.
//// �������úͶ����йأ�ָ��˭������˭���麯������ָ������õľ��Ǹ�����麯������ָ��������õľ���������麯��
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
//	//������ָ�룺����Ҫ&
//	Buy1(&p);  // ������Ʊ  
//	Buy1(&s);  // ѧ����Ʊ
//
//	//����������
//	Buy2(p);   // ������Ʊ
//	Buy2(s);   // ѧ����Ʊ
//
//	//����Ȳ���ָ��Ҳ��������
//	Buy3(p);   //������Ʊ
//	Buy3(s);   //������Ʊ
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
//		cout << "������Ʊ" << endl;
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
//		cout << "ѧ����Ʊ" << endl;
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
//	Person *p = new Student(); // ��Student��Ŀռ䣬call���๹�캯��������ָ����οռ�
//	delete p;  //����������free
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
//	//�����̳и����fun1()����
//	virtual void fun2()  //����func2()�Ḳ�Ǹ���fun2()
//	{
//		cout << "B::fun2()" << endl;
//	}
//	virtual void fun3()
//	{
//		cout << "B::fun3()" << endl;
//	}
//	void fun4()  //fun4()�����麯��
//	{
//		cout << "B::fun3()" << endl;
//	}
//};
//typedef void(*FUNC)();   
//
//void printVtable(int *vfter)  
//{
//	cout << "����ַ��" << vfter << endl;
//	for (int i = 0; vfter[i] != 0; i++) //��Ϊ������һ��Ԫ����0
//	{
//		printf("��%d���麯����ַ��0x%x,->", i, vfter[i]);
//		FUNC f = (FUNC)vfter[i]; 
//		f(); //���ø��麯��
//	}
//	cout << endl;
//}
//
//int main()
//{
//	A a1;
//	B b1;
//	int *vfter1 = (int*)(*(int*)(&a1));  //vfter������ַ
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
//	a.func1(); //��̬��̬
//	a.display();  //�������� ����̬��̬
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
///////////////////���麯��
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
////���麯��
////�ڳ�Ա�麯�����βκ������=0�����Ա����Ϊ���麯�����������麯�������Ϊ�����ࣨ�ӿ��ࣩ�������಻��ʵ��������
////���Ǵ��麯���������������¶�������������ʵ���������󣬵��ǻ��໹�ǲ���ʵ��������
//int main()
//{
//	B b; //���������ʵ����������
//	A a;  //���಻��ʵ����������
//}
//

////////////��̳ж�̬

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
//typedef void(*FUNC)(); //����һ������ָ������FUNC
//
//void printTable(int *vfptr)
//{
//	printf("vtable address:%p\n", vfptr);
//	for (int i = 0; vfptr[i] != 0; i++)
//	{
//		printf("��%d���麯����ַ:%p->", i, vfptr[i]);
//		FUNC f = (FUNC)(vfptr[i]);
//		f();  //�����������
//	}
//	printf("\n");
//}

//int main()
//{
//	C c;
//	c.func1();
//	
//	cout<<sizeof(c)<<endl;
//	//��Ϊc������ֱ�Ӹ��ࣺA��B
//	int *vfptr1 = (int*)(*((int*)(&c)));
//	printTable(vfptr1);
//	//��Ϊ�ڶ������ָ�����ڵ�һ�������Ա�����±ߣ����Եڶ������ָ����&c����Ҫ���ϵ�һ������Ĵ�С��
//	//��������ָ��+1���ӵ�����ָ���͵Ĵ�С��������Ҫ��&aǿתΪchar*,����+sizeof(A)/4,
//	int *vfptr2 = (int*)(*(int*)(((char*)(&c)) + sizeof(A))); 
//	printTable(vfptr2);
//	system("pause");
//	return 0;
//}

/////////////���������
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
	virtual void f1()  //��д�麯��
	{
		cout << "B::f1 ()" << endl;
	}
	virtual void f3()  // B���¶�����麯��
	{
		cout << "B::f3()" << endl;
	}
	//����B�̳���A��f2����
public:
	int _b;
};
class  C : virtual public A
{
public:
	virtual void f1()  // C��д���麯��f1
	{
		cout << "C::f1()" << endl;
	}
	virtual void f3()  // C���¶������麯��f3
	{
		cout << "C::f3()" << endl;
	}
	//����C�̳���A���麯��f2
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
	cout << "����ַ��" << vfter << endl;
	for (int i = 0; vfter[i] != 0; i++) //��Ϊ������һ��Ԫ����0
	{
		printf("��%d���麯����ַ��0x%x,->", i, vfter[i]);
		FUNC f = (FUNC)vfter[i];
		f(); //���ø��麯��
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
	int *vfptr1 = (int*)(*((int*)(&d))); //B �����ָ��
	printVtable(vfptr1);
	int *vfptr2 = (int*)(*((int*)(((char*)(&d)) + 12)));//  C�����ָ��
	printVtable(vfptr2);
	int *vfptr = (int*)(*((int*)(((char*)(&d)) + 28)));  //  �������ָ��
	printVtable(vfptr);
	system("pause");
	return 0;
}