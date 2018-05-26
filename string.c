#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//ģ��ʵ��strncpy����
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
////ģ��ʵ��strncmp
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
//	else if (*str1 == '\0')//�ж��Ƿ�Ϊǰ׺
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

////ģ��ʵ��strncat
////strncat ���ַ���ƴ�ӣ�
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

////ģ��ʵ��memmove
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
//	//�����Զ���Ϊchar *msg1="abc123",�ַ��������������޸�
//	char msg2[10];
//	int len = strlen(msg1) + 1;
//	my_memmove(msg1 + 1, msg1, len);
//	printf("%s\n", msg1+1);
//	//printf("%s\n",my_memmove(msg1+1,msg1,len));ͨ����ʽ����
//	system("pause");
//	return 0;
//}
////ģ��ʵ��memcpy
////memcpy���ڴ濽�������Կ����������ͣ�����ṹ�壬���ֽ�Ϊ������λ
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
////ģ��ʵ��strcmp
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
//	else if (*str1 == '\0')//�ж��Ƿ�Ϊǰ׺
//		return -1;
//	else 
//	    return ret = 1;
//}
//int my_strcmp(const char*str1, const char*str2)
//{
//	int ret = 0;
//	while (!(ret = *(unsigned char *)str1 - *(unsigned char *)str2) && *str1)
//	{//ǰһ�������ж��Ƿ���ȣ������ȣ�ȡ�������������ڶ�����*str1!='\0'
//		str1++;
//		str2++;
//	}
//	if (ret < 0)
//		ret = -1;
//	else
//		ret = 1;
//	return ret;//���û����if����else���ߵ����˵����������ȣ�
//	//�ǲ�����ѭ���ڶ�����������ѭ������*str1='\0'��*str2Ҳ����'\0'	           
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
////ģ��ʵ��strstr
////strstr���Ӵ����ң���str1�в���str2����str1�е�һ�γ���,����str1�г��ֺ�Ĵ�
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
////ģ��ʵ��strcat
////strcat ���ַ���ƴ�ӣ��ǽ���һ���ַ���ƴ�ӵ�ǰһ���ַ���
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
////ģ��ʵ��strlen����
////�������ķ�ʽ 
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
////ָ��-ָ��ķ�ʽ
//int my_strlen(const char *dst)
//{
//	char *p = dst;
//	while (*p)
//	{
//		p++;
//	}
//	return p - dst;
//}
////�ݹ�ķ�ʽ
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
////ģ��ʵ��strcpy����
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
//	while (*ret++ = *src++)//*ret++�൱����ʹ�ú�++����*src��ֵ����*ret,��++��ֱ�����*ret='\0',�˳�ѭ��
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