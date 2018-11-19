package CODE.多线程;

public class Wait1
{
    public static void main(String[] args) throws InterruptedException {
        Object ob=new Object();
        synchronized (ob)
        {
            System.out.println("等待开始...");
            ob.wait();
            System.out.println("等待结束...");
        }
        System.out.println("main方法结束...");
    }
}
