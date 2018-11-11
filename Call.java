package CODE.多线程;

/////Callable接口实现多线程
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

class MyCallImpl implements Callable<String>
{
    private Integer tickets=50;

    public String call() throws Exception
    {
        for(int i=0;i<10;i++)
        {
            System.out.println(Thread.currentThread().getName()+"剩余票数:"+tickets--);
        }
        return "票已售罄";
    }
}

public class Call
{
    public static void main(String[] args) throws InterruptedException ,ExecutionException
    {
        FutureTask<String> task=new FutureTask<>(new MyCallImpl());
        new Thread(task,"线程1").start();
        new Thread(task,"线程2").start();
        new Thread(task,"线程3").start();
        System.out.println(task.get()); //票已售罄
    }
}
