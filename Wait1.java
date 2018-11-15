package CODE.生产者消费模型;

class Mythread implements  Runnable
{
    private Object obj;
    private boolean flag;

    public Mythread(Object obj, boolean flag) {
        this.obj = obj;
        this.flag = flag;
    }
    public void waitmethod()
    {
        synchronized (obj)
        {
            System.out.println(Thread.currentThread().getName()+":"+"wait方法开始..");
            try {
                obj.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }System.out.println(Thread.currentThread().getName()+"："+"wait方法结束");
        }
    }
    public void notifymethod()
    {
        synchronized (obj)
        {
            System.out.println(Thread.currentThread().getName()+":"+"notify方法开始");
            obj.notifyAll();
            System.out.println(Thread.currentThread().getName()+":"+"notify方法结束");
        }
    }


    @Override
    public void run()
    {
        if(flag)
        {
            waitmethod();
        }
        else
            notifymethod();

    }
}

public class Wait1
{
    public static void main(String[] args) throws InterruptedException {
        Object obj=new Object();
        Mythread waitThread=new Mythread(obj,true);
        Mythread notifyThread=new Mythread(obj,false);
        for(int i=0;i<10;i++)
        {
            Thread thread1=new Thread(waitThread,"等待线程"+i);
            thread1.start();
        }
        //Thread thread1=new Thread(waitThread,"等待线程");
        Thread thread2=new Thread(notifyThread,"唤醒线程");
        //thread1.start();
        Thread.sleep(1000);
        thread2.start();

    }

}
