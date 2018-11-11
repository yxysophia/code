package CODE.多线程;


////线程休眠与线程让步

//sleep
//class Mythread2 implements Runnable
//{
//    public void run()
//    {
//        for(int i=0;i<5;i++)
//        {
//            try {
//                Thread.sleep(100);
//            } catch (InterruptedException e) {
//                e.printStackTrace();
//            }
//            System.out.println(Thread.currentThread().getName()+":"+i);
//        }
//    }
//}
//public class SleepYield
//{
//    public static void main(String[] args) {
//        Mythread2 thread=new Mythread2();
//        new Thread(thread).start();
//        new Thread(thread).start();
//    }
//}

//yield
//class Mythread2 implements Runnable
//{
//    public void run()
//    {
//        for(int i=0;i<5;i++)
//        {
//            Thread.yield();
//            System.out.println(Thread.currentThread().getName()+":"+i);
//        }
//    }
//}
//public class SleepYield
//{
//    public static void main(String[] args) {
//        Mythread2 thread=new Mythread2();
//        new Thread(thread).start();
//        new Thread(thread).start();
//    }
//}


/////join方法
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

class Mythread2 implements Runnable
{
    public void run()
    {
        System.out.print("主线程睡眠前的时间：");
        printTime();
        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.print("主线程唤醒时间");
        printTime();
    }

    private void printTime()
    {
        Date date=new Date();
        DateFormat dateFormat=new SimpleDateFormat(("yyyy-MM-dd HH:mm:ss"));
        String time=dateFormat.format(date);
        System.out.println(time);
    }
}
public class SleepYield
{
    public static void main(String[] args) throws InterruptedException {
        Mythread2 thread=new Mythread2();
        Thread thread1=new Thread(thread,"子线程1");
        thread1.start();
        System.out.println(Thread.currentThread().getName());
        thread1.join(); //子线程1调用join，会让主线程休眠，直至子线程1的run执行结束
        System.out.println("代码结束"); //最后打印
    }
}