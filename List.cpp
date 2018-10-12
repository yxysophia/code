#pragma once
#include<stdio.h>
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
//˫���ͷѭ������ģ��
template<class T>
//ÿ�����Ԫ�ص���
struct ListNode
{
	T _data;
	ListNode<T> *_next;
	ListNode<T> *_prev;
	ListNode(T data = T()) //���캯��
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
	List()  //���캯��
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;

	}

	// L2(L1)  //������L1���������L2,��L2��Ҫ��L1�еĽڵ�Ԫ��
	List(const List<T>& L) //��������
	{
		//L2����Ҫ��һ��ͷ��㣬����ͷ���ָ���Լ�
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;


		//L2����ͷ���󣬿��԰�L1�Ľڵ�����β����L2��,��ȻҲ��������ռ䣬���β���
		Node* cur = L._head->_next;
		while (cur != L._head)
		{
			//β��
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
	List<T>operator=(List<T> L) //�ִ���ֵ
	{
		swap(_head, L._head);
		return *this;
	}
	void Insert(Node* pos, const T& data) //��posǰ����Ԫ��
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
	void Erase(Node* pos)  //ɾ��posλ�ý��
	{
		assert(pos != _head); //����ɾ��ͷ���
		Node* prev = pos->_prev;
		Node* next = pos->_next;
		// prev  pos  next 
		prev->_next = next;
		next->_prev = prev;
		delete pos;

	}
	void PopBack()  //βɾ
	{
		Erase(_head->_prev);
	}
	void PopFront() //ͷɾ
	{
		Erase(_head->_next);
	}
	void print()  //��ӡ����
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