#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
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
		printf("'%s' 是'%s'左旋的结果\n", str2,str1);
	}
	else 
		printf("'%s' 不是'%s'左旋的结果\n", str2, str1);
	system("pause");
	return 0;
}


//右旋
void  right_move(char *str, int count,int len)
{
	char tmp = 0;
	int i = 0;//i为一次右旋移动次数
	while (count--)
	{
		tmp = str[len-1];//在循环一次后，需将tmp,i重新初始化
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
	int count = 0;//count是右旋次数
	int len = strlen(str);
	printf("请输入右旋次数\n");
	scanf("%d", &count);
	count = count % len;//长度为4，若右旋次数为7，实质需右旋3次
	right_move(str, count,len);
	printf("右旋结果为：%s\n", str);
	system("pause");
	return 0;
}


//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

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
	int count = 0;//count是左旋次数
	int len = strlen(str);
	printf("请输入左旋次数\n");
	scanf("%d", &count);
	count = count % len;//长度为4，若左旋次数为7，实质需左旋3次
	left_move(str, count, len);
	printf("左旋结果为：%s\n", str);
	system("pause");
	return 0;
}

//逆置的方法

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
	int count = 0;//count是左旋次数
	int len = strlen(str);
	printf("请输入左旋次数\n");
	scanf("%d", &count);
	count = count % len;//长度为4，若左旋次数为7，实质需左旋3次
	left_move(str, count, len);
	printf("左旋结果为：%s\n", str);
	system("pause");
	return 0;
}




void  left_move(char *str, int count,int len)
{
	char tmp = 0;
	int i = 0;//i为一次左旋移动次数
	while (count--)
	{
		tmp = str[0];//在循环一次后，需将tmp,i重新初始化
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
	int count = 0;//count是左旋次数
	int len = strlen(str);
	printf("请输入左旋次数\n");
	scanf("%d", &count);
	count = count % len;//长度为4，若左旋次数为7，实质需左旋3次
	left_move(str, count,len);
	printf("左旋结果为：%s\n", str);
	system("pause");
	return 0;
}
