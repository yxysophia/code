package CODE.多线程;


import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

////lock与unclock
class Mythead implements Runnable
{
    private Integer tickets=10;
    private Lock ticketslock=new ReentrantLock();  //声明一个lock锁
    public void run()
    {
        for(int i=0;i<10;i++)
        {
            ticketslock.lock();  //上锁
            if(tickets>0)
            {
                try {
                    Thread.sleep(20);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println(Thread.currentThread().getName()+":"+tickets--);
            }
            ticketslock.unlock();  //解锁

        }

    }
}
public class Lock1
{
    public static void main(String[] args) {
        Mythead thread=new Mythead();
        new Thread(thread,"黄牛1").start();
        new Thread(thread,"黄牛2").start();
        new Thread(thread,"黄牛3").start();
    }
}
