#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

int main()
{
	//ofstream�ļ������
	ofstream file("test.txt");   //��ǰĿ¼�´���test.txt�ļ�
	file << "hello pick\n";//���ļ���д��
	file.close();
	file.open("test.txt",ios::app);
	file << "�������\n" ;
	file << "�е㿪��ѽ\n";
	file.close();

	system("pause");
	return 0;
}

