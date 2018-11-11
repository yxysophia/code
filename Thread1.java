package CODE.多线程;

///继承Thread类实现多线程
class Mythread extends Thread
{
    private String title;
    public Mythread(String title)
    {
        this.title=title;
    }
    @Override
    public void run()  //run是线程的入口，相当于main
    {
        for(int i=0;i<10;i++)
        {
            System.out.println(title+" "+ i);
        }
    }
}

public class Thread1
{
    public static void main(String[] args) {
        Mythread thread1=new Mythread("thread1");
        Mythread thread2=new Mythread("thread2");
        Mythread thread3=new Mythread("thread3");
        thread1.run();
        thread2.run();
        thread3.run();
    }
}
////从结果看出，三个线程顺序打印，并没有实现多线程，是因为实现多线程必须用Thread.start()方法。


/////Thread类的start方法
class Mythread extends Thread
{
    private String title;
    public Mythread(String title)
    {
        this.title=title;
    }
    @Override
    public void run()  //run是线程的入口，相当于main
    {
        for(int i=0;i<10;i++)
        {
            System.out.println(title+" "+ i);
        }
    }
}
public class Thread1
{
    public static void main(String[] args) {
        Mythread thread1=new Mythread("thread1");
        Mythread thread2=new Mythread("thread2");
        Mythread thread3=new Mythread("thread3");
        thread1.start();  //实现多线程必须用Thread类的start方法
        thread2.start();
        thread3.start();
    }
}
/////可以实现多线程并发执行


import com.sun.imageio.plugins.common.I18N;
////实现Runable接口
class MythreadImpl implements  Runnable
{
    private String title;
    public MythreadImpl(String title)
    {
        this.title=title;
    }
    public void run()
    {
        for(int i=0;i<5 ;i++)
        {
            try {
                Thread.sleep(20);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println(title+":"+ i);
        }
    }
}
public class Thread1
{
    public static void main(String[] args)
    {
        Runnable thread1=new MythreadImpl("thread1");
        Runnable thread2=new MythreadImpl("thraed2");
        Runnable thread3=new MythreadImpl("thraed3");
        new Thread(thread1).start();
        new Thread(thread2).start();
        new Thread(thread3).start();
    }
}

/////匿名内部类进行Runnable对象创建
public class Thread1
{
    public static void main(String[] args)
    {
       new Thread(new Runnable() {
           @Override
           public void run() {
               for (int i = 0; i < 5; i++) {
                   System.out.println(Thread.currentThread().getName()+":" + i);
               }
           }
       }).start();

    }
}

///lambada实现Runnable接口
public class Thread1
{
    public static void main(String[] args) {
        Runnable thread1 = () -> {
            for (int i = 0; i < 5; i++) {
                System.out.println(Thread.currentThread().getName() + " " + i);
            }
        };

        Runnable thread2 = () -> {
            for (int i = 5; i < 10; i++) {
                System.out.println(Thread.currentThread().getName() + " " + i);
            }
        };
        //两个线程同时执行
        new Thread(thread1).start();
        new Thread(thread2).start();
    }
}



/////Runable接口实现数据共享
class Mythread implements Runnable
{
    private Integer tickets=10;

    @Override
    public void run()
    {
        while(tickets>0)
        {
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println(Thread.currentThread().getName()+":"+"还剩票数:"+tickets--);
        }
    }
}
public class Thread1
{
    public static void main(String[] args)
    {
        Mythread thread = new Mythread();
        new Thread(thread, "A").start();
        new Thread(thread, "B").start();
        new Thread(thread, "C").start();
    }
}
