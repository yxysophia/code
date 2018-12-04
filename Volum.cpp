#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>
using namespace std;

////1.������MyString, Ҫ�����ء� + �����������Լ�����ʽ:a = b + c; 
////��ʾ�����ַ������ӡ�����a, b, c������MyString�Ķ���
class MyString
{
public:
	MyString(char* str)  //���
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}
	MyString() 
		:_str(new char[1])//Ϊ����delete[]����һ��
	{
		_str[0] = '\0';
	}
	MyString& operator+(const MyString& c)  //�ַ�������
	{
		char* tmp = _str;
		_str = new char[strlen(tmp) + strlen(c._str) + 1];
		strcpy(_str, tmp);
		delete[] tmp;
		_str = strcat(_str, c._str);
		return *this;
	}
	MyString operator=(const MyString& s)  //��ֵ���������
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


//ʹ���麯����д�����������Բ�����������������
//���������Բ���嶼���Կ�����Բ�̳ж��������Կ��Զ���Բ��Circle��Ϊ���ࡣ
//��Circle���ж���һ�����ݳ�Աradius�������麯��area()��volume()��
//��Circle������Sphere���Column�ࡣ
//���������ж��麯��area()��volume()���¶��壬�ֱ��������Բ���������������

//Բ��
const double PI = 3.1415926;

class Circle
{
public :
	Circle(double ridus)		
	{
		_ridus = ridus;
	}
	
	//�麯��area()
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
	//�������� 4PI*r^2
	double area()
	{
		return 4.0 * PI*_ridus*_ridus;
	}
	//������� 4/3*PI*r^3
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
	//Բ��������:2*�����+�����(�����ܳ�*��)
	double area()
	{
		return 2 * PI*_ridus*_ridus + 2 * PI*_ridus*_height;
	}
	//Բ������� �����*��
	double volume()
	{
		return PI*_ridus*_ridus*_height;
	}
private:
	double _height; //Բ����ĸ�
};
int main()
{
	//Circle *c1 = new Sphere(2.2);  //�ø���ָ�������
	//cout <<"��������"<< c1->area()<< endl;
	//cout << "�������" << c1->volume() << endl;

	//Circle*c2 = new Column(3.3, 4);
	//cout << "Բ��������"<<c2->area() << endl;
	//cout << "Բ�������" << c2->volume() << endl;
	Circle *c;
	Sphere s(2.2);
	c = &s;  //��Ƭ����
	cout << "��������" << c->area() << endl;
	cout << "�������" << c->volume() << endl;

	Column co(3.3, 4);
	c = &co;
	cout << "Բ��������"<<c->area() << endl;
	cout << "Բ�������" << c->volume() << endl;
	system("pause");
	return 0;
}