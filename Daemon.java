package CODE.多线程;


////守护线程

import org.omg.PortableServer.THREAD_POLICY_ID;

class MythreadA implements Runnable
{
    public void run()
    {
        int i=1;
        while(true)
        {

            try {
                System.out.println(Thread.currentThread().getName()+":"+i+"次进入循环 是否为守护线程"+Thread.currentThread().isDaemon());
                i++;
                Thread.sleep(1000);
            }
            ////如果发送终端信号，会抛异常InterruptedException
            catch (InterruptedException e) {
                System.out.println(Thread.currentThread().getName()+"线程被中断");
                return;
            }
        }

    }
}
public class Daemon
{
    public static void main(String[] args) throws InterruptedException {
        MythreadA thread=new MythreadA();
        Thread thread1=new Thread(thread,"线程1");
        Thread thread2=new Thread(thread,"线程2");
        ////将线程1设置为守护线程，设置守护线程必须在启动该线程前
        thread1.setDaemon(true);
        thread1.start();

        thread2.start();
        Thread.sleep(4000);
        thread2.interrupt();  //给线程2发送中断状态信号
        Thread.sleep(4000);//线程2中断后，线程1还在执行，因为主线程还没结束
        System.out.println("代码结束");

    }
}
