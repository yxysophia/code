package CODE.线程复习;


//同步代码块
//多个线程卖票
//class ISealTickets implements Runnable
//{
//    private int tickets=10;
//    public void run()
//    {
//        for(int i=0;i<10;i++)
//        {
//            synchronized (this)  //锁住的当前对象ISealTickets对象，
//            // 而只有一个ISealTickets对象，所以在同一时刻只有一个线程可以进入该同步代码块
//            {
//                if(tickets>0)
//                {
//                    try {
//                        Thread.sleep(1000);
//                        System.out.println(Thread.currentThread().getName()+"在卖票，还剩"+tickets--+"张票");
//                    } catch (InterruptedException e) {
//                        e.printStackTrace();
//                    }
//                }
//            }
//        }
//    }
//}
//public class Synchronized1 {
//    public static void main(String[] args) {
//        ISealTickets iSealTickets=new ISealTickets();
//        Thread thread1=new Thread(iSealTickets,"黄牛A");
//        Thread thread2=new Thread(iSealTickets,"黄牛B");
//        Thread thraed3=new Thread(iSealTickets,"黄牛C");
//        thread1.start();
//        thread2.start();
//        thraed3.start();
//    }
//}

//同步方法
//class ISealTickets implements Runnable
//{
//    private int tickets=100;
//    public void run()
//    {
//        sale();
//    }
//    synchronized  public void sale() //同步方法，锁住的ISealTickets实例化对象
//    {
//        for(int i=0;i<10;i++)
//        {
//            if(tickets>0)
//            {
//                try {
//                    Thread.sleep(1000);
//                    System.out.println(Thread.currentThread().getName()+"在卖票，还剩"+tickets--+"张票");
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//            }
//        }
//
//    }
//}
//public class Synchronized1
//{
//    public static void main(String[] args) {
//        ISealTickets iSealTickets=new ISealTickets();
//        new Thread(iSealTickets,"黄牛A").start();
//        new Thread(iSealTickets,"黄牛B").start();
//        new Thread(iSealTickets,"黄牛C").start();
//
//    }
//}


//锁住同一个对象 ，只实例化一个对象
//class A
//{
//   synchronized public void print()
//    {
//        System.out.println(Thread.currentThread().getName()+"进入同步方法");
//        try {
//            Thread.sleep(1000);
//            System.out.println(Thread.currentThread().getName()+"退出同步方法");
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }
//    }
//}
//class IB implements Runnable
//{
//    private A a;
//    public IB(A a)
//    {
//        this.a=a;
//    }
//    public void run()
//    {
//       a.print();
//    }
//}
//
//public class Synchronized1
//{
//    public static void main(String[] args) {
//        A a=new A();
//        IB ib=new IB(a);
//        new Thread(ib,"线程1").start();
//        new Thread(ib,"线程2").start();
//        new Thread(ib,"线程3").start();
//
//    }
//}


//使用的全局同步方法，定义为静态方法

//class A
//{
//    synchronized static public void print()  //定义为静态方法，即在类加载时，而类只会加载一次，将class对象锁住
//    {
//        System.out.println(Thread.currentThread().getName()+"进入同步方法");
//        try {
//            Thread.sleep(1000);
//            System.out.println(Thread.currentThread().getName()+"退出同步方法");
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }
//    }
//}
//class IB implements Runnable
//{
//    public void run()
//    {
//        A.print();
//    }
//}
//
//public class Synchronized1
//{
//    public static void main(String[] args) {
//        IB ib=new IB();
//        new Thread(ib,"线程1").start();
//        new Thread(ib,"线程2").start();
//        new Thread(ib,"线程3").start();
//
//    }
//}




//class A
//{
//     public void print()
//    {
//        synchronized (A.class)  //将类对象锁住
//        {
//            System.out.println(Thread.currentThread().getName()+"进入同步方法");
//            try {
//                Thread.sleep(1000);
//                System.out.println(Thread.currentThread().getName()+"退出同步方法");
//            } catch (InterruptedException e) {
//                e.printStackTrace();
//            }
//        }
//    }
//}
//class IB implements Runnable
//{
//    public void run()
//    {
//       new A().print();
//    }
//}
//
//public class Synchronized1
//{
//    public static void main(String[] args) {
//        IB ib=new IB();
//        new Thread(ib,"线程1").start();
//        new Thread(ib,"线程2").start();
//        new Thread(ib,"线程3").start();
//
//    }
//}


class C
{
    synchronized public void testA()
    {
        if(Thread.currentThread().getName().equals("线程1"));
        {
            while(true)
            {
                System.out.println("线程1在执行");
            }
        }
    }

    synchronized public void testB()
    {
        if(Thread.currentThread().getName().equals("线程2"))
        {
            while(true)
            {
                System.out.println("线程2在运行");
            }
        }
    }
}
class IMythread implements Runnable
{
    private C c;

    public IMythread(C c)
    {
        this.c=c;
    }
    public void run()
    {
        c.testA();
        c.testB();
    }
}

public class Synchronized1
{
    public static void main(String[] args) {
        IMythread iMythread=new IMythread(new C());
        new Thread(iMythread,"线程1").start();
        new Thread(iMythread,"线程2").start();


    }
}