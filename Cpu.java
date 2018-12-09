package CODE.模拟处理机;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class ProcessCpu
{
    private String pcbName; //进程名
    private ProcessCpu next; //指向下一个进程
    private int run_time; //要求运行时间
    private int priority; //优先数
    private char state;   //状态

    public ProcessCpu(String pcbName, int run_time, int priority, char state) {
        this.pcbName = pcbName;
        this.run_time = run_time;
        this.priority = priority;
        this.state = state;
    }

    public void setPcbName(String pcbName) {
        this.pcbName = pcbName;
    }

    public void setNext(ProcessCpu next) {
        this.next = next;
    }

    public int getPriority() {
        return priority;
    }

    public String getPcbName() {
        return pcbName;
    }

    public void setRun_time(int run_time) {
        this.run_time = run_time;
    }

    public void setPriority(int priority) {
        this.priority = priority;
    }

    public void setState(char state) {
        this.state = state;
    }

    public ProcessCpu getNext() {
        return next;
    }

    public int getRun_time() {
        return run_time;
    }

    public char getState() {
        return state;
    }

    @Override
    public String toString() {
        if (next != null) {
            return "ProcessCpu{" +
                    "pcbName='" + pcbName + '\'' +
                    ", next=" + next.getPcbName() +
                    ", run_time=" + run_time +
                    ", priority=" + priority +
                    ", state=" + state +
                    '}';
        }
        return "ProcessCpu{" +
                "pcbName='" + pcbName + '\'' +
                ", next=" + null +
                ", run_time=" + run_time +
                ", priority=" + priority +
                ", state=" + state +
                '}';
    }

}
public class Cpu {
    List<ProcessCpu> pcbQueue = new ArrayList<>();  //存一开始的5个进程，
    ProcessCpu pcb1, pcb2, pcb3, pcb4, pcb5;
    List<Integer> time = Time();  //5个进程运行时间随机数
    List<Integer> pri = Pri();   //5个进程的运行优先级随机数

    public void Init() {
        pcb1 = new ProcessCpu("p1", time.get(0), pri.get(0), 'R');
        pcb2 = new ProcessCpu("p2", time.get(1), pri.get(1), 'R');
        pcb3 = new ProcessCpu("p3", time.get(2), pri.get(2), 'R');
        pcb4 = new ProcessCpu("p4", time.get(3), pri.get(3), 'R');
        pcb5 = new ProcessCpu("p5", time.get(4), pri.get(4), 'R');
        sortPcb();
        //设置next
        for (int i = 0; i < 4; i++) {
            pcbQueue.get(i).setNext(pcbQueue.get(i + 1));
        }
        pcbQueue.get(4).setNext(null);
        System.out.println(pcb1);
        System.out.println(pcb2);
        System.out.println(pcb3);
        System.out.println(pcb4);
        System.out.println(pcb5);
    }

    //将进程按照优先级进行排序入队列
    public void sortPcb() {
        pcbQueue.add(pcb1);
        pcbQueue.add(pcb2);
        pcbQueue.add(pcb3);
        pcbQueue.add(pcb4);
        pcbQueue.add(pcb5);
        for (int i = 1; i < 5; i++) {
            for (int j = 0; j < 5 - i; j++) {
                if (pcbQueue.get(j).getPriority() < pcbQueue.get(j + 1).getPriority()) {
                    ProcessCpu tmp=pcbQueue.get(j);
                    pcbQueue.set(j,pcbQueue.get(j+1));
                    pcbQueue.set(j+1,tmp);

                }
            }
        }
    }

    //交换两个进程在队列中位置
    public void swap(ProcessCpu p1, ProcessCpu p2) {
        ProcessCpu tmp = p1;
        p1 = p2;
        p2 = tmp;
    }

    public List<Integer> Time() {
        //生成运行时间随机数
        Random r = new Random();
        List<Integer> time = new ArrayList<>(); //放生成运行时间随机数
        for (int i = 0; i < 5; i++) {
            time.add(r.nextInt(6) + 1); //生成[1-6]之间的随机数
        }
        return time;
    }

    public List<Integer> Pri() {
        //生成优先级随机数
        Random r = new Random();
        List<Integer> pri = new ArrayList<>(); //放生成进程优先级随机数
        for (int i = 0; i < 5; i++) {
            pri.add(r.nextInt(19) + 1); ////生成[1-19]之间的随机数
        }
        return pri;
    }
    //执行5个进程
    public void runProcess()
    {
        //首先执行第一个进程
        ProcessCpu cur=pcbQueue.get(0);  //获取队列第一个进程
        run(0);
        //cur进程有2种情况：1.尾插到队列，2.要求运行时间结束，出队列
        //只要队列里有进程，就继续
        while(pcbQueue.size()>0)
        {
            //获取当前优先级最大进程
            int max=getMaxPriPcb();
            run(max);
        }
    }
    //获取当前最大优先级进程
    public int getMaxPriPcb() {
        int max = 0;
        ProcessCpu maxPcb = pcbQueue.get(0);
        for (int i = 1; i < pcbQueue.size(); i++) {
            if (maxPcb.getPriority() < pcbQueue.get(i).getPriority()) {
                maxPcb = pcbQueue.get(i);
                max = i;
            }
        }
        return max;
    }

    //执行某一具体的进程
    public void run(int curPositoiong)
    {
        ProcessCpu cur=pcbQueue.get(curPositoiong);  //获取当前进程
        System.out.println("正在执行的进程为:"+cur.getPcbName());
        cur.setRun_time(cur.getRun_time()-1);  //执行该进程一次后，运行时间-1
        cur.setPriority(cur.getPriority()-1);   //执行该进程一次后，优先级-1
        if(cur.getPriority()<-20)  //进程优先级[-20-19]
        {
            cur.setPriority(-20);
        }
        pcbQueue.remove(curPositoiong); //将该进程删除
        if(cur.getRun_time()==0)
        {
            cur.setState('E'); //将该进程置为完成状态
            System.out.println(cur.getPcbName()+"出队列");
        }
        else
        {
            pcbQueue.add(cur); //当前进程要去运行时间不为0 ，入队
        }
        //队列不为空，打印队列的进程排列情况
        if(pcbQueue.size()!=0)
        {
            System.out.print("队列进程变为：");
           for(int i=0;i<pcbQueue.size();i++)
           {
               System.out.println(pcbQueue.get(i));
           }
            System.out.println(); //换行
        }
        else
        {
            System.out.println("队列为空，没有进程");
        }
    }

    public static void main(String[] args) {
        Cpu cpu=new Cpu();
        cpu.Init();
        cpu.runProcess();
    }
}
