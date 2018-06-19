#include<iostream>
using namespace std;

class Array
{
public:
	Array(int size = 10)
		:_size(size)
		, _a(0)
	{
		cout << "����" << endl;
		if (_size > 0)
		{  
			_a = new int[_size];
		}
	}
	~Array()
	{
		cout << "����" << endl;
		if (_a) 
		{
			delete[] _a;
			_a = 0;//�ÿ�
			_size = 0;
		}
   }
	
private:
	int* _a;
	int _size;
};
//int main()
//{
//	// malloc/free + ��λ������new()/��ʾ��������������ģ�� new��delete ����Ϊ 
//	Array* p1 = (Array*)malloc(sizeof(Array));     
//	new(p1) Array(100);
//
//	p1->~Array();  
//	free(p1);
//
//	// malloc/free + ��ε��ö�λ������new()/��ʾ��������������ģ�� new[]��delete[] ����Ϊ 
//	Array* p2 = (Array*)malloc(sizeof(Array) * 10);//10������
//	for (int i = 0; i < 10; i++)
//	{
//		new(p2 + i)Array;//��Ҫ��10�����󶼹����ʼ��
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		(p2+i)->~Array;//�ȵ�����������10������
//	}
//	free(p2);//�������ͷſռ�
//}
int main()
{
	Array* p1 = (Array *)malloc(sizeof(Array));
	//�����˶���p1�Ŀռ䣬��û������_a�Ŀռ�
	Array* p2 = new Array; //����_a�Ŀռ䣬����_size��ʼ��Ϊ10
	Array* p3 = new Array(20);//���뽫__a�Ŀռ䣬size��ʼ��Ϊ20
	cout << "new:p4" << endl;
	Array* p4 = new Array[3];//�����ι��캯��
	//p4�൱�����飬�������3��Array����ÿ�������_a�������˿ռ䣬_size��Ϊ10
	cout << "*******" << endl;
	free(p1);
	delete p2;
	delete p3;
	cout << "delete: p4" << endl;
	delete[] p4;//����������������
	int *p6 = new int[3];//������3��int��������
	delete p6;
	system("pause");
	return 0;
   
}
void test()
{
Array *p3 = new Array;
delete[]p3; //�����⣬�ᳯǰ����4���ֽ�

Array *p4 = new Array[10];
delete p4;//�����⣬û�н��࿪�ĸ��ֽڿռ��ͷ�
}