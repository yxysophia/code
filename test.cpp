#include<iostream>
using namespace std;
//////////////const��Ա����
class Data1  //������ 
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
		cout << "��������:" ;
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void show() const
	{
		cout << "const ���κ���:" ;
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private: 
	int _year;
	int _month;
	int _day;
};

void test()
{
	Data1 d1(2018, 1, 1);    //���÷�const��Ա����
	const Data1 d2(2018, 6, 11);//����const��Ա����
	d1.show();//d1.show(&d1)->Data *
	d2.show();//d2.show(&d2)->const Data*
	system("pause");

}
/////inline(������

/////��Ԫ
//��Ԫ����
class Time
{
	friend class Data2;  //��Data����Time����Ԫ��Data���Է�����Time�κα���
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
		//����Ϊ��Ԫ��󣬿��Է���Time���������г�Ա
		cout << "hour:" << _t._hour<< endl;//
		cout << "minute:" << _t._minute << endl;
		cout << "second:" << _t._second << endl;		
	}
	friend void Show(const Data2& d);//ʹ���⺯��show��Ϊ������ѣ��Ϳ��Է���˽�г�Ա����
private:
		int _year;
		int _month;
		int _day;
		Time _t;//����ʱ�����
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

/////����������������
class Data3 
{
	friend ostream& /*void */ operator<<(ostream& os, const Data3& d);//��Ԫ����
	friend istream& /*void*/ operator >> (istream& is, Data3& d); //��Ԫ����
private:
	int _year;
	int _month;
	int _day;
};
ostream& /*void */ operator<<(ostream& os, const Data3& d) //��d�����os��
//����os��d���Ƕ����������ٿ���һ�Σ��Ҷ���d���޸ģ���const����
//����ֵ������void �β�os��cout�ı�����os�ģ�coutҲ��ġ�
{
	os << "year:" << d._year << endl;
	os << "month:" << d._month << endl;
	os << "day:" << d._day << endl;
	return os;
}
istream& /*void*/ operator >> (istream& is, Data3& d) //���뵽is��
{//����os��d���Ƕ����������ٿ���һ�Σ��Ҷ���dҪ�޸ģ��������룬������const����
 //����ֵ������void �β�is��cin�ı�����is�ģ�cinҲ��ġ�
	cout << "��ֱ����������գ�" << endl;
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
////��̬��Ա�Ķ����ʹ��
class Data
{
public:
	Data()//���캯��
	{
		++sCount;
	}
	static void PrintCount()//��̬��Ա����
	{
		cout << sCount << endl;
	}
private:
		int _year;
		int _month;
		int _day;
private:
	static int sCount;//��̬��Ա����������ͳ�ƴ����������
};
int Data::sCount = 0;//���岢��ʼ����̬��Ա����
int main()
{
	Data d1;
	Data d2;
	d1.PrintCount();//2
	Data::PrintCount();//2
	//���ھ�̬��Ա����û������thisָ�룬���Կ���ʹ������::��������ʷ�ֱ�ӵ��þ�̬��Ա������
	//d2.PrintCount();//2
	system("pause");
	return 0;
}