#pragma once

#include"List.h"
#include"Seqlist.h"

template<class T,class Container=Seqlist<T>>  //ȱʡ����  ����ջ��˵��������Ĭ����˳���
//Container����������,container��һ��ģ���βΣ�ģ��ʵ�δ�����ʲô���ͣ�Container����ʲô����
class Stack
{
public:
	void Push(const T& data) //��ջ
	{
		_con.PushBack(data);
	}
	void Pop() //��ջ
	{
		_con.PopBack();
	}
	size_t Size()
	{
		return _con.Size();
	}
	bool Empty()
	{
		return _con.Empty();
	}
	T& Top() //����ջ��Ԫ��
	{
		return _con.Top();
	}
private:
	Container _con; 
};

void TestStackCon()
{
	Stack<int, Seqlist<int> >s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	cout << s1.Top() << endl;
	s1.Pop();
	cout << s1.Top() << endl;
	cout << s1.Size() << endl;

	Stack<string, Seqlist<string>>s2;
	s2.Push("pick");
	s2.Push("mh");
	cout << s2.Top() << endl;
	s2.Pop();
	cout << s2.Top() << endl;
    
	//Stack<int, Seqlist<char>>s4;
	//s4.Push(4);
	//cout << s4.Top() << endl; //����

	Stack<int, List<int>>s5;
	s5.Push(10);
	s5.Push(11);
	s5.Push(13);
	s5.Push(14);
	cout << s5.Top() << endl;
	cout << s5.Size() << endl;
}