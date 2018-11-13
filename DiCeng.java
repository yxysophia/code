package CODE.多线程;
//
//
///////同步代码块底层实现
//
////public class DiCeng {
////
////    public static void main(String[] args)
////    {
////        Object obj=new Object();
////        synchronized (obj)  //把obj对象锁住
////        {
////            System.out.println("hello sun");
////        }
////    }
////}
//
////执行同步代码块后，首先执行moniterenter,退出时执行moniterexit指令。
//// 使用synchronized实现同步，关键点就在于要获取对象的监视器monitor对象，
//// 当线程获取到monitor对象后，才可以执行同步代码块，
//// 否则就只能等待。同一时刻只有一个线程可以获取到该对象的monitor监听器。
////
//// 通常一个monitor指令会包含多个monitorexit指令。
//// 因为JVM要确保所获取的锁无论在正常执行路径或者异常执行路径都能正确解锁。
//
//
////////同步方法
////public class DiCeng {
////
////    public static void main(String[] args)
////    {
////        new DiCeng().print();
////    }
////    synchronized public void print()
////    {
////        System.out.println("hello sun");
////    }
////}
//
//
/////可重入锁

class Mythread4 implements Runnable
{
    public void run()
    {
        print1();
        print2();
    }

    ///线程1先获取到Mythread4实例化对象的锁，monitor监视器变为1
   public synchronized void print1()
   {
       if(Thread.currentThread().getName().equals("线程1"));
       {
           print2(); //进入同步方法print2，monitor不为0，但是锁持有的线程是当前线程1，将mobitor变为2
           while(true) {
              // 一个循环使线程1一直不释放锁，那么线程2就无法获取锁
           }
       }
   }

   ////线程2启动后，该方法是同步方法，但是线程1没有释放锁，monitor不为0，所以线程2进不了该方法
   public synchronized void print2()
   {
       if(Thread.currentThread().getName().equals("线程1"))
       {
           System.out.println("线程1进入另一个同步方法");
       }
       else
       {
           System.out.println("线程1没有释放锁，线程2进入同步方法");
       }
   }
}
public class DiCeng
{
    public static void main(String[] args) throws InterruptedException {
        Mythread4 thread=new Mythread4();
        new Thread(thread,"线程1").start();
        Thread.sleep(5000);  //确保线程1先获取到锁
        new Thread(thread,"线程2").start();

    }
}