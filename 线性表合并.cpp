#include<stdio.h>
#define maxsize 100//�������Ա���󳤶�
typedef struct
{
	int Listdata[maxsize+1];//����˳�������
	int listlen; 
}SeqlistType;
void SeqlistMerge(SeqlistType *Lc);//�ϲ� 
void SeqlistInit(SeqlistType *Lc);//��ʼ��˳���  
int Seqlistlength(SeqlistType *Lc);//���㳤�� 
int SeqlistInsert(SeqlistType *Lc,int n,int data);
int main()
{   
    SeqlistType SLL;
	SeqlistType *Lc;
	Lc=&SLL;
	int n,p,data;
	SeqlistInit(Lc);
    SeqlistMerge(Lc);//�ϲ�	
	//SeqlistInsert(Lc,n,data);
	 printf("�ϲ���Ϊ�� \n");
	for(p=0;p<Lc->listlen;p++)
	printf("%d\t",Lc->Listdata[p]);  
	return 0;
}
//�����ʼ������			
 void SeqlistInit(SeqlistType *Lc)
{
   Lc->listlen=0; //��ʼ��ʱ��˳�����Ϊ0 
}
/*�������Ա���
 Seqlistlength(SeqlistType *Lc)
{
  return (Lc->listlen);
}*/ 
//�������Ԫ�� 
int SeqlistInsert(SeqlistType *Lc,int n,int data)
{ 
    
	if(Lc->listlen>maxsize)
	{
		printf("˳������������������Ԫ�أ�\n");
		return 0;
	}
	/*for(i=Lc->listlen;i>=n-1;i--)
	  Lc->Listdata [i]=Lc->Listdata [i-1];*/
	Lc->Listdata [n-1]=data;
	Lc->listlen++;
	return 1;	
}
void SeqlistMerge(SeqlistType *Lc)
{   int p;
	SeqlistType *La; 
	SeqlistType *Lb;
	SeqlistType L1,L2;
	La=&L1;
	Lb=&L2;
	SeqlistInit(Lc);
    *La={{3,5,8,11},4};
    *Lb={{2,6,8,9,11,15,20},7};
    printf("������La:\n");
    for(p=0;p<La->listlen;p++)
	printf("%d\t",La->Listdata[p]);
	printf("\n");
	printf("������Lb:\n");
	for(p=0;p<Lb->listlen;p++)
	printf("%d\t",Lb->Listdata[p]); 
	printf("\n");
    int i=1,j=1,k=0;
    //La->listlen=Seqlistlength(La);
    //Lb->listlen=Seqlistlength(Lb);
    while((i<=La->listlen)&&(j<=Lb->listlen))
    {
    	if((La->Listdata [i-1])<=(Lb->Listdata [j-1]))
    	{
    	   SeqlistInsert(Lc, ++k,La->Listdata [i-1]);	
    	   i++;
		}
		else   
		{
		   SeqlistInsert(Lc, ++k,Lb->Listdata [j-1]);
		   j++;	
		}  
	}
    while(i<=La->listlen)
     {
	  SeqlistInsert(Lc, ++k,La->Listdata [i-1]);
	  i++;
     }
    while(j<=Lb->listlen)
    {
	  SeqlistInsert(Lc, ++k,Lb->Listdata [j-1]);
	  j++;
    }
}
