#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

//1. һԲ����Ӿ����ͼ1��ʾ��������������Χ��һԲ�͹���������������Χ��դ����
//դ���۸�Ϊ35Ԫ / �ף��������Ϊ20Ԫ / ƽ���ס��������Ϊ3�ף���Ӿ�ذ뾶�ɼ������롣
//Ҫ���̼��㲢���������դ������ۡ�

int main()
{
	double r;
	cout << "������Ӿ�ذ뾶:";
	scanf("%lf", &r);
	double c = 2 * 3.14*r;
	double LanMoney = c * 35; //դ����Ǯ
	double s1 = 3.14*pow((r + 3), 2);
	double s2 = 3.14*pow(r, 2);
	double PassMoney = (s1 - s2) * 20;
	cout << "դ����ۣ�" << LanMoney << endl;
	cout << "�������:" << PassMoney << endl;
	system("pause");
	return 0;
}


//2. ������ѧ����Ӳμ�ĳ������ÿ��ѧ����Ϣ����׼��֤�ţ����������˳ɼ������Ŷ���һ�ܳɼ���
//1)	��дһѧ��������䶨��ʵ�֡�ע������׼��֤�ŵĲ��ɱ��ԣ��Ŷӳɼ��Ĺ����ԣ�
//2)	��д������ģ����������ѧ�����丳ֵ����������Ϣ�������
//����Ҫ��
//�ܶ����ʵ����ಢ������������Ʋ��ύ�����嵥��

class Student
{
public:
	Student(string id="20160606001",string name="����",float grade=80)
		:_id(id)
		,_name(name)
		,_grade(grade)
	{
		_total += _grade;
	}
	void print()
	{
		cout << "��Ա��Ϣ��" << _id << "-" << _name << "-" << _grade << endl;
		cout << "ȫ�ӳɼ�:" << _total << endl;
	}	
private:
	string  _id;
	string _name;
	float _grade;
	static float _total;
};
float Student::_total = 0; //��̬��Ա��Ҫ�������ʼ��
int main()
{
	Student s1("201606060101", "С��", 70);
	Student s2("201606060124", "�׶�ͷ", 95);
	Student s3("201606060111", "��С��", 90);
	s1.print();
	s2.print();
	s3.print();
	system("pause");
	return 0;
}