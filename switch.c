/*ѡ���֧�ṹ�������*/ 
#include<stdio.h> 
void main()
{
	int a;
	printf("������ѧ���ɼ�:\n");
	scanf("%d\n",&a);
	switch(a/10)
	{
		case 10:printf("����\n");break;
		case 9:printf("����\n");break;
		case 8:printf("����\n");break;
		case 7:printf("һ��\n");break;
		case 6:printf("����\n");break;
		default:printf("���������ӱ�Ŭ��\n");
	}
	
}
