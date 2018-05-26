#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//模拟实现strncpy函数
char *my_strcpy(char *dest, const char * src,int count)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (count--)
	{
		*ret = *src;
		ret++;
		src++;
	}
	*ret = '\0';
	return dest;
}


int main()
{
	const char *msg = "hello world";
	char buf[64];
	my_strcpy(buf, msg,7);
	printf("buf:%s\n", buf);
	system("pause");

}
////模拟实现strncmp
//int my_strcmp(const char*s1, const char*s2,int count)
//{
//	int ret = 0;
//	assert(s1);
//	assert(s2); 
//	const unsigned char *str1 = (const unsigned char *)s1;
//	const unsigned char *str2 = (const unsigned char *)s2;
//	while (*str1 && *str2&&(count--))
//	{
//		if (*str1 == *str2)
//		{
//			str1++;
//			str2++;
//		}
//		else if (*str1 > *str2)
//			return ret = 1;
//		else
//			return ret = -1;
//	}
//	if (*str1 == '\0'&&*str2 == '\0')
//		return 0;
//	else if (*str1 == '\0')//判断是否为前缀
//		return -1;
//	else 
//	    return ret = 1;
//}
//
//int main()
//{
//	const char *msg1 = "abcde";
//	const char *msg2 = "abcdef";
//	int ret = 0;
//	ret = my_strcmp(msg1, msg2,6);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

////模拟实现strncat
////strncat 是字符串拼接，
//char *my_strcat(char *dst, const char *src,int count)
//{
//	char *p = dst;
//	assert(dst != NULL);
//	assert(src != NULL);
//	while (*p)
//	{
//		p++;
//	}
//	while (count--)
//	{
//		*p = *src;
//		p++;
//		src++;
//	}
//	return dst;
//}
//int main()
//{
//	const char *msg = "hello world";
//	char buf[64]="123";
//	my_strcat(buf, msg,2);
//	printf("buf:%s\n", buf);
//	system("pause");
//	return 0;
//}

////模拟实现memmove
//void *my_memmove(void *dst, const void *src, unsigned int len)
//{
//	char *pl_src = (char *)src;
//	char *pr_src = pl_src + len;
//	char *pl_dst = (char *)dst;
//	char *pr_dst = pl_dst + len;
//	char *pp_src = pr_src - 1;
//	char *pp_dst = pr_dst - 1;
//	while (len--)
//	{
//
//		if ((pl_src < pl_dst) && (pr_src > pl_dst))
//		{
//			*pp_dst = *pp_src;
//			pp_dst--;
//			pp_src--;
//		}
//		else
//		{
//			*pl_dst = *pl_src;
//			pl_dst++;
//			pl_src++;
//		}
//	}
//	return dst;
//}
//int main()
//{
//	char msg1[10] = "abc123";
//	//不可以定义为char *msg1="abc123",字符常量区不可以修改
//	char msg2[10];
//	int len = strlen(msg1) + 1;
//	my_memmove(msg1 + 1, msg1, len);
//	printf("%s\n", msg1+1);
//	//printf("%s\n",my_memmove(msg1+1,msg1,len));通过链式访问
//	system("pause");
//	return 0;
//}
////模拟实现memcpy
////memcpy是内存拷贝，可以拷贝任意类型，比如结构体，以字节为基本单位
//// void *memcpy(void *dest,const void *src,size_t count)
//void *memcpy(void *dest, const void *src,int len)
//{
//	int *p_dest = (void *)dest;
//	int *p_src = (void *)src;
//	while (len--)
//	{
//		*p_dest = *p_src;
//		p_dest++;
//		p_src++;
//	 }
//	return dest;
//}
//int main()
//{
//	int arr1[5] = { 5,6,7,8,9 };
//	int arr2[5] = { 0 };
//	int  i = 0;
//	int count = sizeof(arr1) / sizeof(arr1[0]);
//	int len = sizeof(arr1);
//	memcpy(arr2, arr1, len);
//	for (i = 0; i < count; i++)
//	{
//		printf("%d\n", arr2[i]);
//	}
//	system("pause");
//	return 0;
// }
////模拟实现strcmp
//int my_strcmp(const char*s1, const char*s2)
//{
//	int ret = 0;
//	assert(s1);
//	assert(s2); 
//	const unsigned char *str1 = (const unsigned char *)s1;
//	const unsigned char *str2 = (const unsigned char *)s2;
//	while (*str1 && *str2)
//	{
//		if (*str1 == *str2)
//		{
//			str1++;
//			str2++;
//		}
//		else if (*str1 > *str2)
//			return ret = 1;
//		else
//			return ret = -1;
//	}
//	if (*str1 == '\0'&&*str2 == '\0')
//		return 0;
//	else if (*str1 == '\0')//判断是否为前缀
//		return -1;
//	else 
//	    return ret = 1;
//}
//int my_strcmp(const char*str1, const char*str2)
//{
//	int ret = 0;
//	while (!(ret = *(unsigned char *)str1 - *(unsigned char *)str2) && *str1)
//	{//前一个条件判断是否相等，如果相等，取反满足条件，第二个是*str1!='\0'
//		str1++;
//		str2++;
//	}
//	if (ret < 0)
//		ret = -1;
//	else
//		ret = 1;
//	return ret;//如果没有走if或者else，走到这里，说明两个串相等，
//	//是不满足循环第二个条件跳出循环，即*str1='\0'，*str2也等于'\0'	           
//}
//int main()
//{
//	const char *msg1 = "abcde";
//	const char *msg2 = "abcdef";
//	int ret = 0;
//	ret = my_strcmp(msg1, msg2);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
////模拟实现strstr
////strstr是子串查找，在str1中查找str2串在str1中第一次出现,返回str1中出现后的串
//char *my_strstr(const char *str1, const char *str2)
//{
//	char *cp = (char *)str1;
//	char *p_str1 = NULL;
//	char *p_str2 = (char *)str2;
//	assert(str1);
//	assert(str2);
//	while (*cp)
//	{
//		p_str1 = cp;
//		p_str2 = (char *)str2;
//		while (*p_str1 && *p_str2 && *p_str1 == *p_str2)
//		{
//			p_str1++;
//			p_str2++;
//		}
//		if (*p_str2 == '\0')
//		{
//			return cp;
//		}
//	    cp++;
//	}
//	return NULL;
//}
//int main()
//{
//	const char *msg1 = "1267abc43abcdexyz";
//	const char *msg2 = "abcde";
//	char *msg;
//	msg=my_strstr(msg1, msg2);
//	printf("%s", msg);
//	system("pause");
//	return 0;
//}
////模拟实现strcat
////strcat 是字符串拼接，是将后一个字符串拼接到前一个字符串
//char *my_strcat(char *dst, const char *src)
//{
//	char *p = dst;
//	assert(dst != NULL);
//	assert(src != NULL);
//	while (*p)
//	{
//		p++;
//	}
//	while ((*p++ = *src++))
//	{
//		;
//	}
//	return dst;
//}
//int main()
//{
//	const char *msg = "hello world";
//	char buf[64]="123";
//	my_strcat(buf, msg);
//	printf("buf:%s\n", buf);
//	system("pause");
//	return 0;
//}
////模拟实现strlen函数
////计数器的方式 
//int my_strlen(const char *dst)
//{
//	assert(dst != NULL);
//	int ret = 0;
//	while (*dst)
//	{
//		ret++;
//		dst++;
//
//	}
//	return ret;
//}
////指针-指针的方式
//int my_strlen(const char *dst)
//{
//	char *p = dst;
//	while (*p)
//	{
//		p++;
//	}
//	return p - dst;
//}
////递归的方式
//int my_strlen(const char *dst)
//{
//	int count = 0;
//	char *p = dst;
//
//	if (*p == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(p + 1);
//}
//int main()
//{
//	const char *msg = "hello world";
//	int ret = 0;
//	ret=my_strlen(msg);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
/////////////////////////////////////////////////////////////////////////////////////////
////模拟实现strcpy函数
//char *my_strcpy(char *dest, const char * src)
//{
//	char *ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*src)
//	{
//		*ret = *src;
//		ret++;
//		src++;
//	}
//	*ret = '\0';
//	return dest;
//}
//char *my_strcpy(char *dest, const char *src)
//{
//	char *ret = dest;
//	while (*ret++ = *src++)//*ret++相当于先使用后++，将*src的值赋给*ret,在++，直至最后*ret='\0',退出循环
//	{
//		;
//	}
//	return dest;
//}
//
//int main()
//{
//	const char *msg = "hello world";
//	char buf[64];
//	my_strcpy(buf, msg);
//	printf("buf:%s\n", buf);
//	system("pause");
//
//}