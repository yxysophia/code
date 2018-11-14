#include<stdio.h>
#define maxsize 100//定义线性表最大长度
typedef struct
{
	int Listdata[maxsize+1];//保存顺序表数组
	int listlen; 
}SeqlistType;
void SeqlistInit(SeqlistType *SL);//初始化顺序表  
int Seqlistlength(SeqlistType *SL)//计算长度 
int SeqlistAdd(SeqlistType *SL,int data) ;//添加元素 
int SeqlistInsert(SeqlistType *SL,int n,int data);//插入元素 
int SeqlistDelete(SeqlistType *SL,int x);//删除顺序表中元素
void SeqlistMerge(SeqlistType *Lc);//合并 
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
 //定义初始化函数`			
 void SeqlistInit(SeqlistType *SL)
{
   SL->listlen=0; //初始化时，顺序表长度为0 
}
//计算线性表长度
 Seqlistlength(SeqlistType *SL)
{
  return (SL->listlen);
 } 
//定义添加函数
int SeqlistAdd(SeqlistType *SL,int data)
{
  printf("please input data\n");
  while(scanf("%d",&data)!=EOF,data)//while(scanf("%d",&data)!=0) 
  {
  	if(SL->listlen>maxsize)
      return 0;
   	SL->Listdata[SL->listlen]=data;//++n的运算顺序 是先执行n=n+1,再讲n的值作为表达式++n的值 
   	SL->listlen++;
  }return 1;
}
//定义插入元素 
int SeqlistInsert(SeqlistType *SL,int n,int data)
{
	int i;
	printf("请输入要插入元素：\n");
	scanf("%d",&data);
	printf("请输入插入序号:\n");
	scanf("%d",&n);
	if(SL->listlen>maxsize)
	{
		printf("顺序表已满，不能再添加元素！\n");
		return 0;
	}
	if(n<1||n>SL->listlen-1)
	{
		printf("插入元素序号有误，不能插入元素！\n");
		return 0;
	}
	for(i=SL->listlen;i>=n-1;i--)
	  SL->Listdata [i]=SL->Listdata [i-1];
	SL->Listdata [n-1]=data;
	SL->listlen++;
	return 1;	
}
//定义删除元素 
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
 return 1;//返回成功删除 
}
/*定义删除序号为 x的元素
  int  SeqlistDelete(SeqlistType *SL,int x)

 {
   int i;
   if(x<1||x>=SL->listlen)
   {
      printf("不能删除\n");
      return 0;
   }

   for(i=x;i<SL->listlen;i++)
     SL->Listdata[i-1]=SL->Listdata[i];       
     SL->listlen--;
     teturn 0;
 }*/ 
 
//合并两个有序线性表保证无重复元素
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


 
