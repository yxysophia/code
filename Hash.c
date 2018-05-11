#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Hash.h"
//找到一个字符串中第一次出现一次的字符
//思路为：如果是a-z26个字符，可以设置大小为26的数组，将每个字符出现的次数依次存放在数组里。
//如果是所有字符，将所有字符按照各自的ASSCII码作为下标将出现的次数存放在数组里
char FindFirstChar( const char *str)
{
	int hashtable[256] = { 0 };//所有字符
	//int hashtable[26] = { 0 };//记录每次字符出现的次数,初始设置出现0次
	//char *s1 = ( char*)str;
	char *s1 = (unsigned char*)str;
	while (*s1)
	{
		hashtable[*s1 ]++;
		//hashtable[*s1 - 'a']++;
		s1++;
	}
	//s1 = (char *)str;
	s1 = (unsigned char *)str;
	while (*s1)
	{
		if (hashtable[*s1] == 1)
			return *s1;
		/*if (hashtable[*s1 - 'a'] == 1)
			return *s1;*/
		s1++;
	}
	return -1;
}
void TestFindFirstChar()
{
	const char *str = "abcd#ceasbd";
	printf("%c\n",FindFirstChar(str));
}
void TestHashTable()
{
	HashTable ht;
	HTInit(&ht, 11);//哈希表初始化
	HTInsert(&ht, 37);//插入数据
	HTInsert(&ht, 25);//插入数据
	HTInsert(&ht, 14);//插入数据
	HTInsert(&ht, 36);//插入数据
	HTInsert(&ht, 49);//插入数据
	HTInsert(&ht, 68);//插入数据
	HTInsert(&ht, 57);//插入数据
	HTInsert(&ht, 11);//插入数据
	HTInsert(&ht, 9);//插入数据
	HTInsert(&ht,19);//插入数据
	HTInsert(&ht, 29);//插入数据
	HTPrint(ht);//打印哈希表
	printf("%d\n",HTFind(&ht, 36));//查找
}
int main()
{
	//TestFindFirstChar();
	TestHashTable();
	system("pause");
	return 0;
}

void HTInit(HashTable *ht, size_t capacity)//哈希表初始化
{
	assert(ht);
	ht->hash = (HashNode *)malloc(sizeof(HashNode)*capacity);
	assert(ht->hash);
	ht->_size = 0;
	ht->_capacity = capacity;
	for (int i = 0; i < ht->_capacity; i++)
	{
		ht->hash[i]._status= EMPTY;//必须初始化状态
	}
}
int  HashFunc(HashTable * ht, HTDatatype key)
{
	return key%(ht->_capacity);
}
int HTInsert(HashTable *ht, HTDatatype key)//插入数据
{
	assert(ht);
	//CheckCapacity();
	int index = HashFunc(ht, key);
	while (ht->hash[index]._status == EXIST)//冲突，线性探测
	{
		if (ht->hash[index]._key == key)
			return -1;
		index++;
		if (index == ht->_capacity)
			index = 0;
	}
	ht->hash[index]._key = key;
	ht->_size++;
	ht->hash[index]._status = EXIST;
	return 0;
}
void HTPrint(HashTable ht)//打印哈希表
{
	for (int i = 0; i < ht._capacity; i++)
	{
		if (ht.hash[i]._status == EXIST)
			printf("EXIST:%d\n", ht.hash[i]._key);
		else if (ht.hash[i]._status == DELETE)
			printf("DELETE:%d\n", ht.hash[i]._key);
		else
			printf("EMPTY:NULL\n");		 
	}
	printf("\n");
}
HTDatatype  HTFind(HashTable *ht, HTDatatype key)//查找
{
	assert(ht);
	int index = HashFunc(ht, key);
	while (ht->hash[index]._status !=EMPTY)
	{
		if (ht->hash[index]._key == key)
		{
			if (ht->hash[index]._status == EXIST)
				return ht->hash[index]._key;
			else//状态是删除且值相等，index后不会再存在该数据，直接返回
				return -1;
		}	
		index++;
		if (index == ht->_capacity)
			index = 0;
	}
	return -1;
}