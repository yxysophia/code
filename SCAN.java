package CODE.磁盘调度;


//电梯调度算法

import sun.misc.Request;

import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

//进程访问磁盘的磁道号
class Requst
{
    private int Number;  //访问的磁道号

    public Requst(int number) {
        Number = number;
    }

    public int getNumber() {
        return Number;
    }
}

class DiaoDu
{
    private Requst[] requests; //磁道请求数
    private int start;  //起始磁道号
    private int end;    //终止磁道号
    private int num;    //磁道请求数
    private int curCidao=100;  //当前磁头在100磁道

    public DiaoDu(int start, int end, int num) {
        this.start = start;
        this.end = end;
        this.num = num;
    }

    //设置请求的磁道号
    public void setRandomRequests()
    {
        requests=new Requst[num];
        Set<Integer> reqSet=new TreeSet<>(); //Set不存放重复数据，TreeSet是有序存储
        int n=num;
        //先将随机磁道号放在TreeSet中
        int randomReq=0;
        while((n--)>0)
        {
            Random random=new Random();
            randomReq=random.nextInt(end-start)+start;
            while(reqSet.contains(randomReq))
            {
                randomReq=random.nextInt(end-start)+start;
            }
            reqSet.add(randomReq);  //生成start-end之间的随机整数
            System.out.println(randomReq);
        }
        int i=0;

        //初始化每一个磁道请求
        for(int tmp:reqSet)
        {
            requests[i]=new Requst(tmp);
            i++;
        }
    }

    //电梯调度算法
    // 假定当前磁头在100号磁道上，
    // 并向磁道号增加的方向上移动。请给出按电梯调度算法进行磁盘调度时满足请求的次序,
    // 并计算出它们的平均寻道长度
    //返回平均寻道长度
    public float realSCAN()
    {
        float sum=0;
        TreeSet<Integer> bigNum=new TreeSet<>();  //存放高于当前磁道号的磁道号
        TreeSet<Integer> smallNum=new TreeSet<>();  //存放低于当前磁道号的磁道号
        for(int i=0;i<num;i++)
        {
            //存放高于当前磁道号的磁道号
            if(i<num&&requests[i].getNumber()>=curCidao)
            {
                bigNum.add(requests[i].getNumber());
            }
            //存放低于当前磁道号的磁道号
            else
            {
                smallNum.add(requests[i].getNumber());
            }
        }
        System.out.println("被访问的下一个磁道号  移动距离（磁道数）");
        //将要访问的磁道在当前位置内未距离最近者，也就是bigNum的下一个数字
        for(int tmp:bigNum)
        {
            System.out.println("     "+tmp+"             "+(tmp-curCidao));
            sum=sum+(tmp-curCidao);
            curCidao=tmp;
        }
        //自里向外地访问，直至再无更外的磁道需要访问，才将磁臂换向为子外向里，所以需要将smallNum逆序
        for(int tmp:smallNum.descendingSet())
        {
            System.out.println("      "+tmp+"           "+(curCidao-tmp));
            sum=sum+(curCidao-tmp);
            curCidao=tmp;
        }
        return sum/num;
    }
}
public class SCAN {
    private static Scanner scanner =new Scanner(System.in);
    public static void main(String[] args) {
        System.out.print("请输入起始磁道号:");
        int start=scanner.nextInt();
        System.out.print("请输入终止磁道号：");
        int end=scanner.nextInt();
        System.out.println("请输入磁盘请求序列数（当前磁头在100）");
        int num=scanner.nextInt();
        DiaoDu diaoDu=new DiaoDu(start,end,num);
        diaoDu.setRandomRequests();
        float avglen=diaoDu.realSCAN();
        System.out.println("平均寻道长度:"+avglen);
    }
}
