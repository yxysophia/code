#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef size_t BSDatatype;
typedef struct BitSet
{
	BSDatatype *_bits;
	size_t _range;//���ݵķ�Χ
}BitSet;

void BSInit(BitSet *bs, size_t range);//��ʼ��
void BSSet(BitSet *bs, BSDatatype x);//���룬����Ϊ��1
void BSReset(BitSet *bs, BSDatatype x);//ɾ��������Ϊ��0
int BSTest(BitSet *bs, BSDatatype x);//�ж�x�Ƿ���� ���ڷ���1�������ڷ���0

#include<assert.h>
void TestBS()
{
	BitSet bs;
	BSInit(&bs, 100);//��ʼ��
    BSSet(&bs, 99);//���룬����Ϊ��1
	BSSet(&bs, 100);//���룬����Ϊ��1
	BSSet(&bs, 4);//���룬����Ϊ��1
	printf("%d\n", BSTest(&bs, 99));
	printf("%d\n", BSTest(&bs, 4));
	BSReset(&bs, 99);
	BSSet(&bs, 7);//���룬����Ϊ��1
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
void BSInit(BitSet *bs, size_t range)//��ʼ��
{
	assert(bs);
	bs->_bits = (BSDatatype *)malloc(sizeof(BSDatatype)*(range / 32 + 1));
	bs->_range = range;
	memset(bs->_bits, 0, sizeof(BSDatatype)*(range / 32 + 1));//memset�ǰ��ֽڳ�ʼ����
}
void BSSet(BitSet *bs, BSDatatype x)//���������ݵ�λ����1
{
	//����������Ҫ����Ϊ���Ϊ1
	size_t index = x / 32;//�ҵ�x������������ size_t index=x>>5;
	size_t num = x % 32;//�ҵ�x�ڸ������λ��
	bs->_bits[index] |= (1 << num);
	//       00000000 00001000 00000010 01000000    λͼindex����Ԫ�� 
	//       00000000 00000000 00000000 00000100    1����numλ��
	// |��   00000000 00001000 00000010 01000100    �������Ϊ������1
}
void BSReset(BitSet *bs, BSDatatype x)//ɾ��������Ϊ��0
{
	size_t index = x / 32; //size_t index=x>>5;
	size_t num = x % 32;
	bs->_bits[index] &= ~(1 << num); //~��ȡ��
	//       00000000 00000000 00000000 01000000    1����numλ��
	//       11111111 11111111 11111111 10111111    1����numλ��ȡ��
	//       00000000 00001000 00000010 01000000    λͼindex����Ԫ�� 
	// &��   00000000 00001000 00000010 00000000   �������Ϊ������0
	//  1&n=n   0|n=n
}
int BSTest(BitSet *bs, BSDatatype x)//�ж�x�Ƿ���� ���ڷ���1�������ڷ���0
{
	size_t index = x / 32; //size_t index=x>>5;
	size_t num = x % 32;
	if ((bs->_bits[index] & (1 << num)) == 0)//������
		return 0;
	else  //&������0 ������
		return 1;
	//   00000000 00001000 00000010 01000000    λͼindex����Ԫ��
	//   00000000 00000000 00000010 00000000     1����numλ
	// & 00000000 00000000 00000010 00000000    
}
