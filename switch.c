/*选择分支结构程序设计*/ 
#include<stdio.h> 
void main()
{
	int a;
	printf("请输入学生成绩:\n");
	scanf("%d\n",&a);
	switch(a/10)
	{
		case 10:printf("优秀\n");break;
		case 9:printf("优秀\n");break;
		case 8:printf("良好\n");break;
		case 7:printf("一般\n");break;
		case 6:printf("及格\n");break;
		default:printf("不及格，望加倍努力\n");
	}
	
}
