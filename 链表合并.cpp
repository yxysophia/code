#include<stdio.h>
#include<stdlib.h> 
typedef struct node
{
	int data;
    struct node *next;
}LNode,*Linklist;
 void Init(Linklist Lc);
 Linklist Addend(Linklist head); //���Ԫ�ص�����w�� 
 Linklist Merge(Linklist La, Linklist ,Linklist Lc ) ;
void Print(Linklist Lc);//����
int main()
{   
    
	Linklist La,Lb,Lc;
	LNode L1,L2,L3;
	La=&L1;
	Lb=&L2;
	Lc=&L3;
	Init(Lc);
    Init(La);
	Init(Lb);
	printf("������La��ֵ��\n");
	Addend(La); //���Ԫ�ص�����LLawei��  
	printf("������Lb��ֵ��\n");
	Addend(Lb); //���Ԫ�ص�����Lbwei��  
    Merge(La,Lb,Lc) ;//�ϲ�
	Print(Lc);//����
 } 
 //��ʼ������ 
 void  Init(Linklist head)
 {
 	if(head!=NULL)
 	{
 		head->next=NULL;
		head->data =0; 
	 }
 }
 //�����Ԫ�� 
 Linklist Addend(Linklist head)
 {  
    int data;
 	Linklist node,h; //node������ӽ�� 
 
 	while(scanf("%d",&data)!=EOF,data)
 	{
	 
      if(!(node=(Linklist)malloc(sizeof(LNode)))) 
 	 {  
 		printf("Ϊ���������������ڴ�ʧ�ܣ�\n");
 		return 0;
	 } //�ڴ����ʧ�� 
	 h=head;
	 node->data=data;
      while(h->next!=NULL)
	   h=h->next;
      h->next=node;
      node->next=NULL;
    }
	return NULL;
 }
  Linklist Merge(Linklist La, Linklist Lb ,Linklist Lc) 
 {
 	Linklist pa=La->next;
 	Linklist pb=Lb->next;
 	Linklist pc;
 	pc=Lc;//��La��ͷ�����ΪLc��ͷ���
	while((pa!=NULL)&&(pb!=NULL))
	{
	 	if(pa->data <=pb->data )
	 	{
	 		pc->next =pa;
	 		pc=pa;
	 		pa=pa->next ;
		 }
		 else
		 {
		 	pc->next =pb;
	 		pc=pb;
	 		pb=pb->next ;
		 }
	}
	while(pa!=NULL)
	  {
	  	pc->next =pa;
	  	pc=pa;
	  	pa=pa->next; 
	  }
	 while(pb!=NULL)
	  {
	  	pc->next =pb;
	  	pc=pb;
	  	pb=pb->next; 
	  }
	return NULL;	
 }
 //����
void Print(Linklist Lc)
{
	Linklist ptr;
	if(Lc==NULL)
	{
		printf("no records\n");
	
	}
	for(ptr=Lc->next ;ptr !=NULL;ptr=ptr->next )
	printf("%d\t",ptr->data );
 }    
