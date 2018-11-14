#include<stdio.h>
#include<stdlib.h> 
typedef struct node
{
	int data;
    struct node *next;
}LNode,*Linklist;
 void Init(Linklist Lc);
 Linklist Addend(Linklist head); //添加元素到链表w部 
 Linklist Merge(Linklist La, Linklist ,Linklist Lc ) ;
void Print(Linklist Lc);//遍历
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
	printf("请输入La的值：\n");
	Addend(La); //添加元素到链表LLawei部  
	printf("请输入Lb的值：\n");
	Addend(Lb); //添加元素到链表Lbwei部  
    Merge(La,Lb,Lc) ;//合并
	Print(Lc);//遍历
 } 
 //初始化链表 
 void  Init(Linklist head)
 {
 	if(head!=NULL)
 	{
 		head->next=NULL;
		head->data =0; 
	 }
 }
 //后添加元素 
 Linklist Addend(Linklist head)
 {  
    int data;
 	Linklist node,h; //node是新添加结点 
 
 	while(scanf("%d",&data)!=EOF,data)
 	{
	 
      if(!(node=(Linklist)malloc(sizeof(LNode)))) 
 	 {  
 		printf("为保存结点数据申请内存失败！\n");
 		return 0;
	 } //内存分配失败 
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
 	pc=Lc;//用La的头结点作为Lc的头结点
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
 //遍历
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
