#include<stdio.h>
#define maxsize 100//�������Ա���󳤶�
typedef struct
{
	int Listdata[maxsize+1];//����˳�������
	int listlen; 
}SeqlistType;
void SeqlistInit(SeqlistType *SL);//��ʼ��˳���  
int Seqlistlength(SeqlistType *SL)//���㳤�� 
int SeqlistAdd(SeqlistType *SL,int data) ;//���Ԫ�� 
int SeqlistInsert(SeqlistType *SL,int n,int data);//����Ԫ�� 
int SeqlistDelete(SeqlistType *SL,int x);//ɾ��˳�����Ԫ��
void SeqlistMerge(SeqlistType *Lc);//�ϲ� 
int main()
{   
    SeqlistType SLL;
	SeqlistType *SL;
	SeqlistType *Lc;
	SL=&SLL;
	Lc=&SLL;
	int x,n,p,data;
	printf("please input x\n")
    scanf("%d",&x); 
	SeqlistInit(SL);
	Seqlistlength(SL);
	SeqlistAdd(SL,SL->Listdata[SL->listlen]);
	SeqlistInsert(SL,n,data);
	SeqlistDelete(SL,x); 
	for(p=0;p<SL->listlen;p++)
	printf("%d\t",SL->Listdata[p]);  
	SeqlistMerge(Lc);
	return 0;
 } 
 //�����ʼ������`			
 void SeqlistInit(SeqlistType *SL)
{
   SL->listlen=0; //��ʼ��ʱ��˳�����Ϊ0 
}
//�������Ա���
 Seqlistlength(SeqlistType *SL)
{
  return (SL->listlen);
 } 
//������Ӻ���
int SeqlistAdd(SeqlistType *SL,int data)
{
  printf("please input data\n");
  while(scanf("%d",&data)!=EOF,data)//while(scanf("%d",&data)!=0) 
  {
  	if(SL->listlen>maxsize)
      return 0;
   	SL->Listdata[SL->listlen]=data;//++n������˳�� ����ִ��n=n+1,�ٽ�n��ֵ��Ϊ���ʽ++n��ֵ 
   	SL->listlen++;
  }return 1;
}
//�������Ԫ�� 
int SeqlistInsert(SeqlistType *SL,int n,int data)
{
	int i;
	printf("������Ҫ����Ԫ�أ�\n");
	scanf("%d",&data);
	printf("������������:\n");
	scanf("%d",&n);
	if(SL->listlen>maxsize)
	{
		printf("˳������������������Ԫ�أ�\n");
		return 0;
	}
	if(n<1||n>SL->listlen-1)
	{
		printf("����Ԫ��������󣬲��ܲ���Ԫ�أ�\n");
		return 0;
	}
	for(i=SL->listlen;i>=n-1;i--)
	  SL->Listdata [i]=SL->Listdata [i-1];
	SL->Listdata [n-1]=data;
	SL->listlen++;
	return 1;	
}
//����ɾ��Ԫ�� 
 int  SeqlistDelete(SeqlistType *SL,int x)
{
 int i,j; 
 
for(i=0;i<SL->listlen;i++)
 {
   if(SL->Listdata[i]==x)
   { for(j=i;j<SL->listlen;j++)
      
	  SL->Listdata[j]=SL->Listdata[j+1];       
   SL->listlen--;
   }
 }
 return 1;//���سɹ�ɾ�� 
}
/*����ɾ�����Ϊ x��Ԫ��
  int  SeqlistDelete(SeqlistType *SL,int x)

 {
   int i;
   if(x<1||x>=SL->listlen)
   {
      printf("����ɾ��\n");
      return 0;
   }

   for(i=x;i<SL->listlen;i++)
     SL->Listdata[i-1]=SL->Listdata[i];       
     SL->listlen--;
     teturn 0;
 }*/ 
 
//�ϲ������������Ա�֤���ظ�Ԫ��
void SeqlistMerge(SeqlistType *Lc)
{
	SeqlistType *La; 
	SeqlistType *Lb;
	SeqlistType L;
	La=&L;
	Lb=&L;
	SeqlistInit(Lc);
    *La={3,5,8,11};
    *Lb={2,6,8,9,11,15,20};
    int i=1,j=1,k=0;
    La->listlen=Seqlistlength(La);
    Lb->listlen=Seqlistlength(Lb);
    while((i<=La->listlen)&(j<=Lb->listlen))
    {
    	if((La->Listdata [i-1]<=(Lb->Listdata [j-1]))
    	{
    	   SeqlistInsert(Lc, ++k,La->Listdata [i-1])	
    	   i++;
		}
		else
		{
		   SeqlistInsert(Lc, ++k,Lb->Listdata [j-1])
		   j++;	
		}  
	}
    while(i<=La->listlen)
      SeqlistInsert(Lc, ++k,La->Listdata [i-1]);
    while(j<=Lb->listlen)
      SeqlistInsert(Lc, ++k,Lb->Listdata [j-1]);
	
}


 
