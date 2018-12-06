#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

int main()
{
	//ofstream文件输出流
	ofstream file("test.txt");   //当前目录下创建test.txt文件
	file << "hello pick\n";//对文件的写入
	file.close();
	file.open("test.txt",ios::app);
	file << "天气真好\n" ;
	file << "有点开心呀\n";
	file.close();

	system("pause");
	return 0;
}

