#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

//带头双向链表
typedef int DataListtype;
typedef struct ListNode
{
	DataListtype _data;
	struct ListNode  *_next;
	struct ListNode *_prev;
	struct ListNode (const DataListtype& x)
		:_data(x)
		,_next(NULL)
		,_prev(NULL)
	{
	}
}Node;
class Mylist
{
public:
	Mylist()//构造函数
	{
		_head = new Node(DataListtype());//为Node类型，且初始化
		//_head = (Node*)malloc(sizeof(Node));
		_head->_next = _head;
		_head->_prev = _head;
	}
	Mylist(const Mylist& l)//拷贝构造
	{
		_head = new Node(DataListtype());//初始化DataListtype()，可能是string类型，匿名对象
		_head->_next = _head;
		_head->_prev = _head;
		Node *cur = l._head->_next;
		while (cur != l._head)
		{
			/*Node*tail = _head->_prev;
			Node* Newnode = new Node(cur->_data);
			tail->_next = Newnode;
			Newnode->_prev = tail;
			Newnode->_next = _head;
			_head->_prev = Newnode;
			cur = cur->_next;*/
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	Mylist& operator=( Mylist l)//赋值
	{
		//现代写法
		swap(_head, l._head);
		return *this;
	}
	void PushBack(const DataListtype&x)//尾插
	{
		/*Node* tail = _head->_prev;
		Node* newnode = new Node(x);
		tail->_next = newnode;
		newnode->_prev = tail;
		newnode->_next = _head;
		_head->_prev = newnode;*/
		Insert(_head, x);
	}
	void PushFront(const DataListtype&x)//前插
	{
		/*Node* newnode = new Node(x);
		Node* next = _head->_next;
		newnode->_next = next;
		next->_prev = newnode;
		_head->_next = newnode;
		newnode->_prev = _head;*/
		Insert(_head->_next, x);
	}
	Node* Find(const DataListtype&x)//查找
	{
		Node* cur = _head->_next;
		while (cur != _head && cur->_data != x)
		{
			cur = cur->_next;
		}
		if (cur == _head)
			return NULL;
		return cur;
	}
	void Insert(Node *pos, const DataListtype&x)//插入
	{ 
		//prev newnode pos
		Node* prev = pos->_prev;
		Node* newnode = new Node(x);
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
	void PopFront()//前删
	{
		//assert(_head->_next != _head);
		////_head  next  next->_next
		//Node* next = _head->_next;
		//_head->_next = next->_next;
		//next->_next->_prev = _head;
		//delete next;
		//next = NULL;
		Erase(_head->_next);
	}
	void PopBack()//尾删
	{
		/*assert(_head->_next != _head);
		Node* tail = _head->_prev;
		_head->_prev = tail->_prev;
		tail->_prev->_next = _head;
		delete tail;
		tail = NULL;*/
		Erase(_head->_prev);
	}
	void Erase(Node* pos)
	{
		//prev   pos  next
		assert(pos!= _head);
		Node* prev = pos->_prev;
		Node* next = pos->_next;
		prev->_next = next;
		next->_prev = prev;
		delete pos;
		pos = NULL;
	}
	void print()
	{
		Node*cur = _head->_next;
		while (cur != _head)
		{
			cout << cur->_data << "->";
			cur = cur->_next;
		}
		printf("NULL\n");
	}
	size_t Size()//大小
	{
		size_t size = 0;
		Node* cur = _head->_next;
		while (cur != _head)
		{
			size++;
			cur = cur->_next;
		}
		return size;
	}
	bool empty()//判空
	{
		return _head->_next == _head;
	}
	~Mylist()
	{
		Node *cur = _head->_next;
		while (cur != _head)
		{
			Node *next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;//现在把头释放
		_head = NULL;
	}
private :
	Node* _head;
};
//int main()
//{
//	Mylist l1;
//	l1.PushBack(1);
//	l1.PushFront(2);
//	l1.print();
//	Mylist l2(l1);
//	Mylist l3;
//	l3 = l2;
//	l3.print();
//	l2.print();
//	l1.Insert(l1.Find(2), 3);
//	l1.Insert(l1.Find(3)->_prev, 7);
//	l1.print();
//	l1.PopFront();
//	l1.print();
//	l1.PopBack();
//	l1.print();
//	l1.Erase(l1.Find(1));
//	l1.PushBack(10);
//	l1.PushFront(11);
//	l1.print();
//	printf("%d\n", l1.Size());
//	l1.PopBack();
//	l1.PopFront();
//	l1.print();
//	system("pause");
//	return 0;
//}