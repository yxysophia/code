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

void BFInit(BloomFliter *bf, size_t range);//��ʼ��
void BFSet(BloomFliter *bf, keyvaule x);//����
void BSSet(BloomFliter *bf, size_t hash);//λͼ����
int BFTest(BloomFliter *bf, keyvaule x);//�ж�x������λ���Ƿ���� ���ڷ���1�������ڷ���0
int BSTest(BloomFliter *bf, size_t hash);//λͼ�ж��Ƿ����  ���ڷ���1�������ڷ���0
int main()
{
	BloomFliter bf;
	BFInit(&bf, 4);
	BFSet(&bf, "������");
	BFSet(&bf, "sleep");
	BFSet(&bf, "λͼ");
	BFSet(&bf, "��¡������");
	printf("%d\n",BFTest(&bf, "λͼ"));
	printf("%d\n", BFTest(&bf, "������"));
	printf("%d\n", BFTest(&bf, "����"));
	system("pause");
	return 0;
}
void BFInit(BloomFliter *bf, size_t range)//��ʼ��
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
size_t BKDRHash1(char *str)//���ַ���ת������
{
	size_t hash = 0;
	while (*str)
	{
		hash = hash * 131 + *str;//*131��ͻ���ʼ���,����ֵҲ���� 
		str++;
	}
	return hash;
}
void BFSet(BloomFliter *bf, keyvaule x)//����
{   //���ڲ�¡�������������У���һ���ַ��������ڵ��Ǻ������ַ�����ͬһ��λ�ã�
	//���޷��жϸ��ַ����Ƿ����,���Խ��ַ�����������λ�ã���ͻ���ʵͣ�
	//�������λ�ö����ڣ�����ַ�������
	assert(bf);
	size_t hash1 = BKDRHash1(x) % bf->_range;//�Ƚ��ַ���תΪ����
	BSSet(bf, hash1);//��hash1λ�ñ��Ϊ1
	size_t hash2 = SNDMHash2(x) % bf->_range;
	BSSet(bf, hash2);//��hash2λ�ñ��Ϊ1
	size_t hash3 = APHash3(x) % bf->_range;
	BSSet(bf, hash3);//��hash3λ�ñ��Ϊ1
}
void BSSet(BloomFliter *bf, size_t hash)//λͼ����
{
	//����������Ҫ����Ϊ���Ϊ1
	size_t index = hash / 32;//�ҵ�x������������ size_t index=x>>5;
	size_t num = hash % 32;//�ҵ�x�ڸ������λ��
	bf->_bloom[index] |= (1 << num);
}
int BFTest(BloomFliter *bf, keyvaule x)//�ж�x�Ƿ����
{
	assert(bf);
	size_t hash1 = BKDRHash1(x) % bf->_range;//�Ƚ��ַ���תΪ����
	if (BSTest(bf, hash1) == 0)
		return 0;//��һ��λ�ò����ڼ��ɷ��ز�����
	//˵����һ��λ�ô���
	size_t hash2 = SNDMHash2(x) % bf->_range;
	if (BSTest(bf, hash2) == 0)
		return 0;//�ڶ���λ�ò����ڼ��ɷ��ز�����
    //ǰ����λ�ö�����
	size_t hash3 = APHash3(x) % bf->_range;
	if (BSTest(bf, hash3) == 0)
		return 0;//��һ��λ�ò����ڼ��ɷ��ز�����
	//����λ�ö�����
	return 1;	
}
int BSTest(BloomFliter *bf, size_t hash)//�ж�x�Ƿ���� ���ڷ���1�������ڷ���0
{
	size_t index = hash / 32; //size_t index=x>>5;
    size_t num = hash % 32;
	if ((bf->_bloom[index] & (1 << num)) == 0)//������
		return 0;
	else  //&������0 ������
		return 1;
}