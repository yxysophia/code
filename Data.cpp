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
	int GetMonthDay(int year, int month)//���ظ����µ��������
	{   //��Ϊ�����2��29��ƽ��28��
		assert(year > 0 && month > 0 && month<13);
		int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//12���µ�����
		int day = Month[month];//ֱ�ӵõ�����
		if (month == 2 &&
			(year % 4 == 0 && year % 100 != 0) || year % 400 == 0)//�ж��Ƿ�������
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
			cout << "�Ƿ�����" << endl;
	}
	//���캯����
	//��Ա������˽�еģ�Ҫ�����ǽ��г�ʼ����������һ�����к���������
	//ͬʱ����������ҽ��ڶ������ʱ�Զ�ִ��һ�Σ���ʱ���õĺ�����Ϊ���캯��
	//���캯���������Ĭ�ϳ�Ա����,�������£�
	//1.��������������ͬ
	//2.�޷���ֵ
	//3.����ʵ����ʱϵͳ�Զ����ö�Ӧ�Ĺ��캯��
	//4.���캯����������
	//5.���캯�����������ж���Ҳ���������ⶨ��
	//6.����ඨ����û�и����캯������c++�������Զ�����һ��ȱʡ(�޲ε���)�Ĺ��캯������ֻҪ���Ƕ�����һ�����캯����ϵͳ�Ͳ����Զ�����ȱʡ�Ĺ��캯��
	//7.�޲ε�ȱʡ������ȫȱʡ�Ĺ��캯������Ϊ��ȱʡ���캯������ȱʡ�Ĺ��캯��ֻ����һ��

	//Data()//�޲ι��캯��
	//{
	//	_year = 1998;
	//	_month = 1;
	//	_day = 1;
	//}
	//�޲ι��캯����ȫȱʡ���캯��ֻ����һ��
	Data(int year = 1998, int month = 1, int day = 1)//ȫȱʡ���캯��
	{
		if (year > 0 && month < 13 && month>0 &&
			GetMonthDay(year, month) >= day&&day > 0)
		{
			_year = year;
			_month = month;
			_day = day;
			cout << "���캯��" << endl;
		}
		else
			cout << "�Ƿ�����" << endl;

	}
	/*Data(int year, int month, int day)//���ι��캯��
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
	/////��������
	//��һ��������������ڽ���ʱ��C++����ϵͳ���Զ�����һ����Ա�������������ĳ�Ա��������������
	//���������������Ĭ�ϳ�Ա�������������£�
	//1.��������������������ǰ�����ַ�~
	//2.���������޲����޷���ֵ
	//3.һ�������ҽ���һ������������������δ��������������ϵͳ���Զ�����ȱʡ����������
	//4.�����������ڽ���ʱ��ϵͳ���Զ�������������
	//5.��������������ɾ�����󣬶������һЩ��������free��fclose)
	~Data()//��������  ջ�Ƚ�������ȹ���Ķ��������
	{
		cout << "��������" << endl;
	}
	////�������캯��
	//��������ʱʹ��ͬ����������г�ʼ������ʱ���õĹ���ĺ���Ϊ�������캯����
	//�������캯���������Ĭ�ϵĳ�Ա����,�������£�
	//1.�������캯����ʵ��һ�����캯��������
	//2.�������캯���Ĳ������������ô��Σ�ʹ�ô�ֵ��ʽ���ܻ���������ݹ����
	//3.������û�п������캯����ϵͳ��Ĭ��ȱʡ�Ŀ������캯����ȱʡ�Ŀ������캯�������ο������Ա���г�ʼ��
	Data(const Data& d)//����������������������const,�����޸�
	{   //����������Data *this,const Data &d)
		_year = d._year;//this->_year = d._day;
		_month = d._month;//this->_month = d._month;
		_day = d._day;//this->_day = d._day;
		cout << "ֵ����" << endl;
	}
	
	////���������
	//����:
	//1.operator+�Ϸ���������ɺ����� ���磺operator< )
	//2.������������ܸı�����������ȼ�/�����/����������
	//3.ע��5���������ص������: 1.(.*)   2.(::)  3.(sizeof)  4.(?.)   5.(.)
	// ��ֵ��������أ�Ĭ�ϳ�Ա����
	//��ֵ��������غͿ������캯������
	//�������캯���Ǵ����Ķ���ʹ��һ�����еĶ�������ʼ�����׼�������Ķ���
	//��ֵ��������أ���һ���Ѵ��ڵĶ�����п�����ֵ
	Data& operator=(const Data& d)//���ض��������������Ȼ���ڣ���������÷���
	{  //��Data& operator =(Data* this, const Data& d)
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
			cout << "��ֵ����" << endl;
		}
		return *this;
	}
	//>���������
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
    //>=���������
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
	//<���������
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
	//<=���������
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
	//==���������
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
	//+���������
	Data operator+(int day)
	{
		_day += day;
		if (GetMonthDay(_year, _month) >= _day && day>0)//�����Ϸ�
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
	//+=���������
	Data& operator+=(int day)
	{
		_day += day;
		if (GetMonthDay(_year, _month) >= _day && day>0)//�����Ϸ�
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
	//-���������
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


private://˽�У����ⲿ���ܷ���
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(1999, 1, 1);//���ô��ι��캯�� d1�ȹ���
	Data d2;//�����޲λ�ȫȱʡ���캯��  d2������
	Data d3(d1);//����Data d3 = d1; ���߶�Ϊֵ�������캯�� d1����d3
	Data d4;
	d4.operator=(d1);//��ֵ���������
	d4 = d1;//��ֵ���������

	//d1.show();
	d1.SetData(2018, 6, 4);
	//d1.SetData(2018, 2, 28);
	Data d5(2018, 6, 28);
	/*if (d5 > d1)//>���������
	{
		cout << "����" << endl;
	}
	else
		cout << "������" << endl;*/
	/*if (d5 >= d1)//>=���������
	{
		cout << "���ڵ���" << endl;
	}
	else
		cout << "С��" << endl;*/
	if (d5 == d1)//!=���������
	{
		cout << "���" << endl;
	}
	else
		cout << "�����" << endl;
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
	Array(int size)//���캯��
	{
		_ptr = (int *)malloc(sizeof(int)*size);
		cout << "���캯��" << endl;
	}
	//��������
	~Array()
	{
		free(_ptr);//�ͷŶ�̬����ռ�
		cout << "��������" << endl;
	}
	///ֵ�������캯��
	//���ܵ�����û�ж���ֵ�������캯����ϵͳ��Ĭ��ȱʡֵ����ֵ������������������������ڸ���ֵ������������

private:
	int *_ptr;

};
//int main()
//{
//	Array a1(10);
//	Array a2(a1);//��a1����a1
//	a2.~Array();
//	a1.~Array();//�ᴥ���ϵ㣬������ 
//	//��Ϊ������a1��������a2���������Ա��������a1ָ��ptr������a2ָ��ptr,����ָ����ͬ������������ʱfree�����Σ����Ա���
//	//���ܵ�����û�ж���ֵ�������캯����ϵͳ��Ĭ��ȱʡֵ����ֵ������������������������ڸ���ֵ������������
//	system("pause");
//	return 0;
//}
