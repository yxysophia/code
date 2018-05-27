#include<stdio.h>
#include<stdlib.h>
#include<string.h> // memset
#include<assert.h>
typedef size_t BFDatatype;
typedef char* keyvaule;
typedef struct BloomFliter
{
	BFDatatype *_bloom;
	size_t _range;
}BloomFliter;

void BFInit(BloomFliter *bf, size_t range);//初始化
void BFSet(BloomFliter *bf, keyvaule x);//插入
void BSSet(BloomFliter *bf, size_t hash);//位图插入
int BFTest(BloomFliter *bf, keyvaule x);//判断x在三个位置是否存在 存在返回1，不存在返回0
int BSTest(BloomFliter *bf, size_t hash);//位图判断是否存在  存在返回1，不存在返回0
int main()
{
	BloomFliter bf;
	BFInit(&bf, 4);
	BFSet(&bf, "哈哈哈");
	BFSet(&bf, "sleep");
	BFSet(&bf, "位图");
	BFSet(&bf, "布隆过滤器");
	printf("%d\n",BFTest(&bf, "位图"));
	printf("%d\n", BFTest(&bf, "哈哈哈"));
	printf("%d\n", BFTest(&bf, "哈哈"));
	system("pause");
	return 0;
}
void BFInit(BloomFliter *bf, size_t range)//初始化
{
	assert(bf);
	bf->_range = range * 5;
	bf->_bloom = (BFDatatype *)malloc(sizeof(BFDatatype)*(bf->_range / 32 + 1));
	memset(bf->_bloom, 0, sizeof(BFDatatype)*(bf->_range / 32 + 1));
}
size_t APHash3(const char * str)
{
	register size_t hash = 0;
	size_t ch; 
	for (long i = 0; ch = (size_t)*str++; i++)
	{
		if ((i & 1) == 0)
		{
			hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
		}
		else
		{
			hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
		}
	}
	return hash;
}
size_t SNDMHash2(const char *str)
{
	register size_t hash = 0;
	size_t ch;
	while (ch = (size_t)*str++)
	{
		hash = 65599 * hash + ch;
	}
	return hash;
}
size_t BKDRHash1(char *str)//将字符串转成整数
{
	size_t hash = 0;
	while (*str)
	{
		hash = hash * 131 + *str;//*131冲突概率减少,其他值也可以 
		str++;
	}
	return hash;
}
void BFSet(BloomFliter *bf, keyvaule x)//插入
{   //由于布隆过滤器存在误判，即一个字符串不存在但是和其他字符串在同一个位置，
	//则无法判断该字符串是否存在,所以讲字符串放在三个位置，冲突概率低，
	//如果三个位置都存在，则该字符串存在
	assert(bf);
	size_t hash1 = BKDRHash1(x) % bf->_range;//先将字符串转为整数
	BSSet(bf, hash1);//将hash1位置标记为1
	size_t hash2 = SNDMHash2(x) % bf->_range;
	BSSet(bf, hash2);//将hash2位置标记为1
	size_t hash3 = APHash3(x) % bf->_range;
	BSSet(bf, hash3);//将hash3位置标记为1
}
void BSSet(BloomFliter *bf, size_t hash)//位图插入
{
	//插入数据需要将该为标记为1
	size_t index = hash / 32;//找到x在数组中坐标 size_t index=x>>5;
	size_t num = hash % 32;//找到x在该坐标的位置
	bf->_bloom[index] |= (1 << num);
}
int BFTest(BloomFliter *bf, keyvaule x)//判断x是否存在
{
	assert(bf);
	size_t hash1 = BKDRHash1(x) % bf->_range;//先将字符串转为整数
	if (BSTest(bf, hash1) == 0)
		return 0;//第一个位置不存在即可返回不存在
	//说明第一个位置存在
	size_t hash2 = SNDMHash2(x) % bf->_range;
	if (BSTest(bf, hash2) == 0)
		return 0;//第二个位置不存在即可返回不存在
    //前两个位置都存在
	size_t hash3 = APHash3(x) % bf->_range;
	if (BSTest(bf, hash3) == 0)
		return 0;//第一个位置不存在即可返回不存在
	//三个位置都存在
	return 1;	
}
int BSTest(BloomFliter *bf, size_t hash)//判断x是否存在 存在返回1，不存在返回0
{
	size_t index = hash / 32; //size_t index=x>>5;
    size_t num = hash % 32;
	if ((bf->_bloom[index] & (1 << num)) == 0)//不存在
		return 0;
	else  //&后结果非0 即存在
		return 1;
}