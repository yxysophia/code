package CODE.集合类;

import java.util.ArrayList;
import java.util.List;


 class OSProcess{
    private String name; //进程名
    private OSProcess next;//指向下一个进程
    private int run_time; //要求运行时间
    private int allo_time;//已运行时间
    private int req_time;//还需要运行时间
    private char state;//状态
    private int pri;//优先数

    public OSProcess(){}
    //构造方法1  优先权方法
    public OSProcess(String name, int run_time, int pri, char state) {

        this.name = name;
        this.run_time = run_time;
        this.pri=pri;
        this.state = state;
    }

    //构造方法2  时间片轮转方法
    public OSProcess(String name, int run_time, char state, int allo_time) {
        this.name = name;
        this.run_time = run_time;
        this.allo_time = allo_time;
        this.state = state;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public OSProcess getNext() {
        return next;
    }
    public void setNext(OSProcess next) {
        this.next = next;
    }
    public int getRun_time() {
        return run_time;
    }
    public void setRun_time(int run_time) {
        this.run_time = run_time;
    }
    public int getAllo_time() {
        return allo_time;
    }
    public void setAllo_time(int allo_time) {
        this.allo_time = allo_time;
    }

    public int getReq_time() {
        return req_time;
    }
    public void setReq_time(int req_time) {
        this.req_time = req_time;
    }
    public char getState() {
        return state;
    }
    public void setState(char state) {
        this.state = state;
    }
    public int getPri() {
        return pri;
    }
    public void setPri(int pri) {
        this.pri = pri;
    }


}



public class Cpu {


    List<OSProcess> list = new ArrayList<>();

    OSProcess op1,op2,op3,op4,op5;
    public void init(){
//初始化进程
        op1 = new OSProcess("p1",2,1,'R');
        op2 = new OSProcess("p2",3,5,'R');
        op3 = new OSProcess("p3",1,3,'R');
        op4 = new OSProcess("p4",2,4,'R');
        op5 = new OSProcess("p5",4,2,'R');

        op1.setNext(null);
        op2.setNext(op4);
        op3.setNext(op5);
        op4.setNext(op3);
        op5.setNext(op1);


//添加到进程队列
        OSProcess temp = op2;
        while(temp!=null){
            list.add(temp);
            temp=temp.getNext();

        }
    }
    //寻找优先数最大的进程
    public int findMax(OSProcess current,List<OSProcess> list){
        if(!list.contains(current)){
            int t=list.get(0).getPri();
            int max=0;
            for(int i=1;i<list.size();i++){
                if(t<list.get(i).getPri()){
                    t=list.get(i).getPri();
                    max=i;
                }
            }
            return max;

        }else if(current.getPri()>=list.get(0).getPri())
            return list.indexOf(current);

        return 0;

    }
    //执行某一个位置为curPosition进程
    public void run(int curPosition)
    {
        OSProcess cur = list.get(curPosition);
        System.out.println("当前:"+cur.getName()+"进程执行");
        cur.setPri(cur.getPri()-1);
        cur.setRun_time(cur.getRun_time()-1);
        OSProcess temp = list.remove(curPosition);//获得删除的进程
        if(temp.getRun_time()>0)//若进程优先数大于0加到列表中
            list.add(temp);
        else {
            temp.setState('E');
            System.out.println("进程"+temp.getName()+"出队！");
        }
        if(list.size()>0){
            System.out.print("此时list的值：");
            for(int i=0;i<list.size();i++){
                System.out.print(list.get(i).getName()+"");
            }
            System.out.println();
        }else{
            System.out.println("进程队列为空！");
        }
    }
    public void runProcess()
    {
        OSProcess cur = this.list.get(0);
        this.run(0);
        while(list.size()>0){
            int a=this.findMax(cur, list);
            cur = this.list.get(a);
            this.run(a);
        }
    }
    public static void main(String[] args) {
        Cpu ot = new Cpu();
        ot.init();
        ot.runProcess();
    }

}
