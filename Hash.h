#pragma once

typedef int HTDatatype;
enum STATUS
{
	EXIST,//该位置有数据
	DELETE,//该位置数据被删除
	EMPTY,//该位置没有数据
};
typedef struct HashNode
{
	HTDatatype _key;//数据
	enum STATUS _status;//状态
}HashNode;
typedef struct HashTable
{
	HashNode *hash;
	size_t _size;//哈希表里有效数据个数
	size_t _capacity;//哈希表大小
}HashTable;

void HTInit(HashTable *ht, size_t capacity);//哈希表初始化
//成功：0，失败-1
int HTInsert(HashTable *ht, HTDatatype key);//插入数据
HTDatatype HTFind(HashTable *ht, HTDatatype key);//查找
void HTPrint(HashTable ht);//打印哈希表