#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef size_t BSDatatype;
typedef struct BitSet
{
	BSDatatype *_bits;
	size_t _range;//数据的范围
}BitSet;

void BSInit(BitSet *bs, size_t range);//初始化
void BSSet(BitSet *bs, BSDatatype x);//插入，将该为置1
void BSReset(BitSet *bs, BSDatatype x);//删除，将该为置0
int BSTest(BitSet *bs, BSDatatype x);//判断x是否存在 存在返回1，不存在返回0

#include<assert.h>
void TestBS()
{
	BitSet bs;
	BSInit(&bs, 100);//初始化
    BSSet(&bs, 99);//插入，将该为置1
	BSSet(&bs, 100);//插入，将该为置1
	BSSet(&bs, 4);//插入，将该为置1
	printf("%d\n", BSTest(&bs, 99));
	printf("%d\n", BSTest(&bs, 4));
	BSReset(&bs, 99);
	BSSet(&bs, 7);//插入，将该为置1
	printf("%d\n",BSTest(&bs, 7));
	printf("%d\n", BSTest(&bs, 99));
	printf("%d\n", BSTest(&bs, 53));
}
int main()
{
	TestBS();
	system("pause");
	return 0;

}
void BSInit(BitSet *bs, size_t range)//初始化
{
	assert(bs);
	bs->_bits = (BSDatatype *)malloc(sizeof(BSDatatype)*(range / 32 + 1));
	bs->_range = range;
	memset(bs->_bits, 0, sizeof(BSDatatype)*(range / 32 + 1));//memset是按字节初始化的
}
void BSSet(BitSet *bs, BSDatatype x)//将插入数据的位置置1
{
	//插入数据需要将该为标记为1
	size_t index = x / 32;//找到x在数组中坐标 size_t index=x>>5;
	size_t num = x % 32;//找到x在该坐标的位置
	bs->_bits[index] |= (1 << num);
	//       00000000 00001000 00000010 01000000    位图index坐标元素 
	//       00000000 00000000 00000000 00000100    1左移num位后
	// |后   00000000 00001000 00000010 01000100    插入后置为将该置1
}
void BSReset(BitSet *bs, BSDatatype x)//删除，将该为置0
{
	size_t index = x / 32; //size_t index=x>>5;
	size_t num = x % 32;
	bs->_bits[index] &= ~(1 << num); //~是取反
	//       00000000 00000000 00000000 01000000    1左移num位后
	//       11111111 11111111 11111111 10111111    1左移num位后取反
	//       00000000 00001000 00000010 01000000    位图index坐标元素 
	// &后   00000000 00001000 00000010 00000000   插入后置为将该置0
	//  1&n=n   0|n=n
}
int BSTest(BitSet *bs, BSDatatype x)//判断x是否存在 存在返回1，不存在返回0
{
	size_t index = x / 32; //size_t index=x>>5;
	size_t num = x % 32;
	if ((bs->_bits[index] & (1 << num)) == 0)//不存在
		return 0;
	else  //&后结果非0 即存在
		return 1;
	//   00000000 00001000 00000010 01000000    位图index坐标元素
	//   00000000 00000000 00000010 00000000     1左移num位
	// & 00000000 00000000 00000010 00000000    
}
