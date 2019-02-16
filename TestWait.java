
class IMthread implements Runnable
{
    private Object object;
    private boolean flag;

    public IMthread(Object object, boolean flag) {
        this.object = object;
        this.flag = flag;
    }

    public void waitMethod()
    {
        synchronized (this)
        {
            try {
                System.out.println("wait方法开始"+Thread.currentThread().getName());
                wait();  //wait方法需要在synchronized里
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("wait方法结束"+Thread.currentThread().getName());
        }
    }

    public void notifyMethod()
    {
        synchronized (this)
        {
            System.out.println("唤醒开始");
           notifyAll();
            System.out.println("唤醒结束");
        }
    }
    @Override
    public void run() {
        if(flag)
        {
            waitMethod();
        }else
        {
            notifyMethod();
        }
    }
}
public class TestWait {
    public static void main(String[] args) throws InterruptedException {
        Object object=new Object();
        IMthread waitThread=new IMthread(object,true);
        IMthread notifyThread=new IMthread(object,false);
        for(int i=0;i<10;i++)
        {
            Thread waitT=new Thread(waitThread,"等待线程"+i);
            waitT.start();
        }
        Thread notifyT=new Thread(notifyThread,"唤醒线程");
        Thread.sleep(1000);
        notifyT.start();
    }
}
