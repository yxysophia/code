#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 �� AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
int is_left(char *str1, char *str2,int len)
{
	char *mem = (char *)malloc(2 * len + 1);
	strcpy(mem, str1);
	strcat(mem, str1);
	if (strstr(mem, str2) != NULL)
	{
		return 1;
	}
	else
		return -1;
}
int main()
{
	char str1[] = "1234";
	char str2[] = "2314";
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return -1;
	int ret=is_left(str1, str2,len1);
	if (ret > 0)
	{
		printf("'%s' ��'%s'�����Ľ��\n", str2,str1);
	}
	else 
		printf("'%s' ����'%s'�����Ľ��\n", str2, str1);
	system("pause");
	return 0;
}


//����
void  right_move(char *str, int count,int len)
{
	char tmp = 0;
	int i = 0;//iΪһ�������ƶ�����
	while (count--)
	{
		tmp = str[len-1];//��ѭ��һ�κ��轫tmp,i���³�ʼ��
		i = len-1;
		while (i > 0)
		{
			str[i] = str[i-1];
			i--;
		}
		str[i] = tmp;
	}
}
int main()
{
	char str[] = "abcd";
	int count = 0;//count����������
	int len = strlen(str);
	printf("��������������\n");
	scanf("%d", &count);
	count = count % len;//����Ϊ4������������Ϊ7��ʵ��������3��
	right_move(str, count,len);
	printf("�������Ϊ��%s\n", str);
	system("pause");
	return 0;
}


//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

void  left_move(char *str, int count, int len)
{
	char *mem = (char *)malloc(2 * len + 1);
	strcpy(mem, str);
	strcat(mem, str);
	strncpy(str, mem + count, len);
	free(mem);
}
int main()
{
	char str[] = "abcd";
	int count = 0;//count����������
	int len = strlen(str);
	printf("��������������\n");
	scanf("%d", &count);
	count = count % len;//����Ϊ4������������Ϊ7��ʵ��������3��
	left_move(str, count, len);
	printf("�������Ϊ��%s\n", str);
	system("pause");
	return 0;
}

//���õķ���

void reverse(char *start, char*end)
{
	while (start < end)
	{
		*start ^= *end;
		*end ^= *start;
		*start ^= *end;
		start++;
		end--;
	}
}

void  left_move(char *str, int count, int len)
{
	reverse(str, str + count - 1);
	reverse(str + count, str + len - 1);
	reverse(str, str + len - 1);
}
int main()
{
	char str[] = "abcd";
	int count = 0;//count����������
	int len = strlen(str);
	printf("��������������\n");
	scanf("%d", &count);
	count = count % len;//����Ϊ4������������Ϊ7��ʵ��������3��
	left_move(str, count, len);
	printf("�������Ϊ��%s\n", str);
	system("pause");
	return 0;
}




void  left_move(char *str, int count,int len)
{
	char tmp = 0;
	int i = 0;//iΪһ�������ƶ�����
	while (count--)
	{
		tmp = str[0];//��ѭ��һ�κ��轫tmp,i���³�ʼ��
		i = 0;
		while (i < len - 1)
		{
			str[i] = str[i + 1];
			i++;
		}
		str[i] = tmp;
	}
}
int main()
{
	char str[] = "abcd";
	int count = 0;//count����������
	int len = strlen(str);
	printf("��������������\n");
	scanf("%d", &count);
	count = count % len;//����Ϊ4������������Ϊ7��ʵ��������3��
	left_move(str, count,len);
	printf("�������Ϊ��%s\n", str);
	system("pause");
	return 0;
}
