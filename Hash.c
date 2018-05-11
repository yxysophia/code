#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Hash.h"
//�ҵ�һ���ַ����е�һ�γ���һ�ε��ַ�
//˼·Ϊ�������a-z26���ַ����������ô�СΪ26�����飬��ÿ���ַ����ֵĴ������δ���������
//����������ַ����������ַ����ո��Ե�ASSCII����Ϊ�±꽫���ֵĴ��������������
char FindFirstChar( const char *str)
{
	int hashtable[256] = { 0 };//�����ַ�
	//int hashtable[26] = { 0 };//��¼ÿ���ַ����ֵĴ���,��ʼ���ó���0��
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
	HTInit(&ht, 11);//��ϣ���ʼ��
	HTInsert(&ht, 37);//��������
	HTInsert(&ht, 25);//��������
	HTInsert(&ht, 14);//��������
	HTInsert(&ht, 36);//��������
	HTInsert(&ht, 49);//��������
	HTInsert(&ht, 68);//��������
	HTInsert(&ht, 57);//��������
	HTInsert(&ht, 11);//��������
	HTInsert(&ht, 9);//��������
	HTInsert(&ht,19);//��������
	HTInsert(&ht, 29);//��������
	HTPrint(ht);//��ӡ��ϣ��
	printf("%d\n",HTFind(&ht, 36));//����
}
int main()
{
	//TestFindFirstChar();
	TestHashTable();
	system("pause");
	return 0;
}

void HTInit(HashTable *ht, size_t capacity)//��ϣ���ʼ��
{
	assert(ht);
	ht->hash = (HashNode *)malloc(sizeof(HashNode)*capacity);
	assert(ht->hash);
	ht->_size = 0;
	ht->_capacity = capacity;
	for (int i = 0; i < ht->_capacity; i++)
	{
		ht->hash[i]._status= EMPTY;//�����ʼ��״̬
	}
}
int  HashFunc(HashTable * ht, HTDatatype key)
{
	return key%(ht->_capacity);
}
int HTInsert(HashTable *ht, HTDatatype key)//��������
{
	assert(ht);
	//CheckCapacity();
	int index = HashFunc(ht, key);
	while (ht->hash[index]._status == EXIST)//��ͻ������̽��
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
void HTPrint(HashTable ht)//��ӡ��ϣ��
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
HTDatatype  HTFind(HashTable *ht, HTDatatype key)//����
{
	assert(ht);
	int index = HashFunc(ht, key);
	while (ht->hash[index]._status !=EMPTY)
	{
		if (ht->hash[index]._key == key)
		{
			if (ht->hash[index]._status == EXIST)
				return ht->hash[index]._key;
			else//״̬��ɾ����ֵ��ȣ�index�󲻻��ٴ��ڸ����ݣ�ֱ�ӷ���
				return -1;
		}	
		index++;
		if (index == ht->_capacity)
			index = 0;
	}
	return -1;
}