#pragma once
#include"List.h"
#include"Seqlist.h"

//队列容器适配器
//队列先进先出

template<class T, class Container>
class Queue
{
public:
	void Push(const T& data)  //进队
	{
		_con.PushBack(data);
	}
	void Pop()  //出队
	{
		_con.PopFront();
	}
	size_t Size()
	{
		return _con.Size();
	}
	bool Empty()
	{
		return _con.Empty();
	}
	T& Front() //队头元素
	{
		return _con.Front();
	}
private:
	Container _con;
};
void TestQueueCon()
{
	Queue<int, Seqlist<int>> q1;
	q1.Push(10);
	q1.Push(11);
	q1.Push(12);
	q1.Push(13);
	cout << q1.Front() << endl;
	q1.Pop();
	cout << q1.Front() << endl;
	cout << q1.Size() << endl;
}