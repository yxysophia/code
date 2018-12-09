package CODE.银行家算法;

import java.io.Reader;
import java.util.Scanner;

class Banker
{
    private  int pN; //进程数量
    private int sN; //资源数量
    private int[] Avaiable; //可利用资源：每类资源数量
    private int[][] Max; //最大需求：进程i需要j类资源最大数目
    private int[][] Allocation; //分配矩阵：进程i已获得j类资源数目
    private int[][] Need; //需求矩阵：进程i还需要j类资源数目
    private int[][] Requst;
    private int[] Work; //工作向量
    private String[] sName; //资源名称
    Scanner scanner=new Scanner(System.in);
    public void init() //初始化
    {
        setNumSource();  //进程数量和资源名称及数量
        setMax();     //进程的最大需求
        setAllocation(); //进程的分配矩阵
        printSystemVariable(); //打印进程资源情况
        SecurityAlgorithm();  //安全性算法
    }
    public void printSystemVariable()
    {
        System.out.println("***********************************************");
        System.out.println("此时各个进程资源分配情况如下");
        System.out.println("       Max     "+"  Allocation   "+" Need    "+"Avaiable");
        System.out.print("进程名+");
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<sN;j++)
            {
                System.out.print(sName[j]+"     ");
            }
        }
        System.out.println();
        for(int i=0;i<pN;i++)
        {
            System.out.print("p"+i+"  ");
            //Max
            for(int j=0;j<sN;j++)
            {
                System.out.print(Max[i][j]+" ");
            }
            System.out.print("|  ");
            //Allocation
            for(int j=0;j<sN;j++)
            {
                System.out.print(Allocation[i][j]+"  ");
            }
            System.out.print("|  ");
            //Need
            for(int j=0;j<sN;j++)
            {
                System.out.print(Need[i][j]+"  ");
            }
            System.out.print("|  ");
            //Avaiable
            if(i==0) {
                for (int j = 0; j < sN; j++) {
                    System.out.print(Avaiable[j]+" ");
                }
            }
            System.out.println();
        }
        System.out.println("***********************************************");
    }
    private void setAllocation()
    {
        System.out.println("请设置各个进程分配矩阵Alloction：");
        for(int i=0;i<pN;i++)
        {
            System.out.println("请输入进程p"+i+"的分配资源数量");
            for(int j=0;j<sN;j++)
            {
                System.out.print(sName[j]+":");
                Allocation[i][j]=scanner.nextInt();
            }
        }
        System.out.println("Available=Available-Allocation.");
        System.out.println("Need=Max-Alloction.");
        for(int i=0;i<sN;i++)
        {
            //设置Available矩阵
            for(int j=0;j<pN;j++)
            {
                Avaiable[i]=Avaiable[i]-Allocation[j][i];
            }
        }
        for(int i=0;i<pN;i++)
        {
            //设置Need矩阵
            for(int j=0;j<sN;j++)
            {
                Need[i][j]=Max[i][j]-Allocation[i][j];
            }
        }
    }
    private void setMax()
    {
        System.out.println("请输入各个进程的最大需求矩阵Max:");
        for(int i=0;i<pN;i++)
        {
            System.out.println("请输入进程p"+i+"需要资源数量:");
            for(int j=0;j<sN;j++)
            {
                System.out.print("需要"+sName[j]+":");
                Max[i][j]=scanner.nextInt();
            }
        }
    }
    private void setNumSource()
    {
        System.out.print("请输入进程数量:");
        pN=scanner.nextInt();
        System.out.print("请输入资源数量:");
        sN=scanner.nextInt();
        System.out.println("请输入资源名称和对应的系统数量:");
        sName=new String[pN];
        Avaiable=new int[sN];
        Allocation=new int[pN][sN];
        Need=new int[pN][sN];
        Max=new int[pN][sN];
        Requst=new int[pN][sN];
        Work=new int[sN];
        for(int i=0;i<sN;i++)
        {
            sName[i]=scanner.next(); //资源名称
            Avaiable[i]=scanner.nextInt(); //资源数量
        }
    }
    public boolean SecurityAlgorithm()
    {
        //Finish表示系统是否有足够资源分配给进程，开始将每个进程的finish置为false
        boolean[] Finish=new boolean[pN];
        for(int i=0;i<pN;i++)
        {
            Finish[i]=false;
        }
        int count=0;  //完成进程数目
        int circle=0; //循环圈数
        boolean flag=true;
        int[] S=new int[pN]; //存储当前的安全序列

        for(int i=0;i<sN;i++)
        {
            //工作向量Work,它表示系统可提供给进程继续运行所需的各类资源数目，
            //在执行安全算法开始时，Work=Available
            Work[i]=Avaiable[i];
        }
        while(count<pN)
        {
            if(flag)
            {
                System.out.println("        Work "+"   Allocation  "+"   Need   "+"Work=Work+Allocation");
                System.out.print("进程名"+"  ");
                //资源名称
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<sN;j++)
                    {
                        System.out.print(sName[j]+" ");
                    }
                    System.out.print("|"+" ");
                }
                System.out.println();
                flag=false;
            }
            for(int i=0;i<pN;i++)
            {
                if(Finish[i]==false&&needIsSmallWork(i))
                {
                    count++;
                    Finish[i]=true;  //系统有足够资源给该进程分配资源
                    S[count-1]=i; //设置当前进程序列号
                    System.out.print("P"+i+" ");
                    for(int j=0;j<sN;j++)
                    {
                        //Work
                        System.out.print(Work[j]+" ");
                    }
                    System.out.print("|"+" ");
                    for(int j=0;j<sN;j++)
                    {
                        //Allocation,已获得资源数
                        System.out.print(Allocation[i][j]+" ");
                    }
                    System.out.print("|"+" ");
                    for(int j=0;j<sN;j++)
                    {
                        //Need数
                        System.out.print(Need[i][j]+" ");
                    }
                    System.out.print("|"+" ");
                    for(int j=0;j<sN;j++)
                    {
                        //Work=Work+Allocation
                        Work[j]=Work[j]+Allocation[i][j];
                        System.out.print(Work[j]+" ");
                    }
                    System.out.println();
                }
            }
            circle++; //循环圈数+1
            if(count==pN) //证明每个进程都满足Finish[i]=false且Need[i][j]<=Work[j]
            {
                System.out.println("系统处于安全状态，安全序列为：");
                for(int i=0;i<pN;i++)
                {
                    System.out.println("p"+S[i]+" ");
                }
                System.out.println("故当前可分配");
                return true;
            }
            if(count<circle)
            {
                System.out.println("当前系统处于不安全状态，不存在安全序列");
                return false;
            }
        }
        return false;
    }
    //判断进程的每个资源还需量是否小于等于系统提供量
    private boolean needIsSmallWork(int i)
    {
        for(int j=0;j<sN;j++)
        {
            if(Need[i][j]>Work[j])
                return false;

        }
        return true;
    }
    public void setRequst()
    {
        int num=0;
        System.out.println("请输入请求资源的进程编号：");
        num=scanner.nextInt();
        System.out.println("请输入请求资源的数量");
        for(int i=0;i<sN;i++)
        {
            System.out.print(sName[i]+":");
            Requst[num][i]=scanner.nextInt();
        }
        BankerAlgorithm(num);
    }
    public void BankerAlgorithm(int num)
    {
        Boolean flag=true;
        //Requst[i][j]<=Need[i][j]
        if(requestIsSmallNeed(num))
        {
            //Requst[i][j]<=Available[i][j]
            if(requstIsSmallAvailable(num))
            {
                for(int i=0;i<sN;i++)
                {
                    //系统提供的资源数
                    Avaiable[i]=Avaiable[i]-Requst[num][i];
                    //
                    Allocation[num][i]+=Requst[num][i];
                    Need[num][i]-=Requst[num][i];
                }
            }
            else
            {
                System.out.println("系统没有足够资源，进程"+num+"需要等待");
                flag=false;
            }
        }
        else
        {
            System.out.println("进程"+num+"请求资源数量超过需要数Need");
            flag=false;
        }
        if(flag==true)
        {
            //申请资源合理并且可以分配
            //系统执行安全性算法
            System.out.println("系统执行安全性算法");
            if(SecurityAlgorithm())
            {
                System.out.println("系统正式分配资源给进程p"+num);
                printSystemVariable();
            }
            else
            {
                System.out.println("本次试探作废，恢复原有资源分配状态，进程p"+num+"等待");
                for(int i=0;i<sN;i++)
                {
                    //系统提供的资源数
                    Avaiable[i]=Avaiable[i]+Requst[num][i];
                    //
                    Allocation[num][i]-=Requst[num][i];
                    Need[num][i]+=Requst[num][i];
                }
                printSystemVariable();
            }
        }

    }
    private boolean requestIsSmallNeed(int num)
    {
        for(int i=0;i<sN;i++)
        {
            if(Requst[num][i]>Need[num][i])
                return false;
        }
        return true;
    }
    public boolean requstIsSmallAvailable(int num)
    {
        for(int i=0;i<sN;i++)
        {
            if(Requst[num][i]>Avaiable[i])
                return false;
        }
        return true;
    }
}

public class Bank {
    public static void main(String[] args) {
        System.out.println("模拟银行家算法");
        Banker banker=new Banker();
        banker.init();
        boolean choose=true;
        Scanner scanner=new Scanner(System.in);
        while(choose)
        {
            banker.setRequst();
            System.out.println("是否还需要请求：y/n");
            String c=scanner.nextLine();
            if("n".equals(c))
                choose=false;

        }



    }

}
