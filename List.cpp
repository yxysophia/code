#pragma once
#include<stdio.h>
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
//双向带头循环链表模板
template<class T>
//每个结点元素的类
struct ListNode
{
	T _data;
	ListNode<T> *_next;
	ListNode<T> *_prev;
	ListNode(T data = T()) //构造函数
	{
		_data = data;
		_next = NULL;
		_prev = NULL;
	}
};
template<class T>
class List
{

	typedef  ListNode<T>  Node;
public:
	List()  //构造函数
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;

	}

	// L2(L1)  //将链表L1拷贝构造给L2,即L2中要有L1中的节点元素
	List(const List<T>& L) //拷贝构造
	{
		//L2首先要有一个头结点，并且头结点指向自己
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;


		//L2有了头结点后，可以把L1的节点依次尾插在L2后,当然也可以申请空间，依次插入
		Node* cur = L._head->_next;
		while (cur != L._head)
		{
			//尾插
			Node* newnode = new Node(cur->_data);
			Node* tail =_head->_prev;
			// head   tail   newnode
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
			cur = cur->_next;
		}
	}
	List<T>operator=(List<T> L) //现代赋值
	{
		swap(_head, L._head);
		return *this;
	}
	void Insert(Node* pos, const T& data) //在pos前插入元素
	{
		assert(pos);
		Node* newnode = new Node(data);
		Node* prev = pos->_prev;
		//prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
	void PushFront(const T& data)
	{
		Insert(_head->_next, data);
	}
	void PushBack(const T& data)
	{
		Insert(_head, data);
	}
	void Erase(Node* pos)  //删除pos位置结点
	{
		assert(pos != _head); //不能删除头结点
		Node* prev = pos->_prev;
		Node* next = pos->_next;
		// prev  pos  next 
		prev->_next = next;
		next->_prev = prev;
		delete pos;

	}
	void PopBack()  //尾删
	{
		Erase(_head->_prev);
	}
	void PopFront() //头删
	{
		Erase(_head->_next);
	}
	void print()  //打印链表
	{

		Node* cur = _head->_next;
		while (cur != _head)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		printf("\n");
	}
	Node* find(const T& data)
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			if (cur->_data == data)
				return cur;
			cur = cur->_next;
		}
		return NULL;
	}
private:
	Node* _head;
};
int main()
{
	/*List<int> l1;
	
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	List<int> l2(l1);
	l1.print();
	l2.print();
	List<int> l3;
	l3 = l2;
	l3.print();*/
	List<string> l1;
	l1.PushFront("abs");
	l1.PushFront("mkf");
	l1.PushFront("km");
	l1.PushBack("kn");
	l1.print();
	l1.Erase(l1.find("kn"));
	l1.print();
	List<string>l2(l1);
	l2.print();
	system("pause");
	return 0;

}