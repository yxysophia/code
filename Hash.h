#pragma once

typedef int HTDatatype;
enum STATUS
{
	EXIST,//��λ��������
	DELETE,//��λ�����ݱ�ɾ��
	EMPTY,//��λ��û������
};
typedef struct HashNode
{
	HTDatatype _key;//����
	enum STATUS _status;//״̬
}HashNode;
typedef struct HashTable
{
	HashNode *hash;
	size_t _size;//��ϣ������Ч���ݸ���
	size_t _capacity;//��ϣ���С
}HashTable;

void HTInit(HashTable *ht, size_t capacity);//��ϣ���ʼ��
//�ɹ���0��ʧ��-1
int HTInsert(HashTable *ht, HTDatatype key);//��������
HTDatatype HTFind(HashTable *ht, HTDatatype key);//����
void HTPrint(HashTable ht);//��ӡ��ϣ��