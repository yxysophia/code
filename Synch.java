package CODE.多线程;


//class MythreadB implements  Runnable
//{
//    private Integer tickets=10;
//    public void run()
//    {
//        while(tickets>0) {
//            try {
//                System.out.println(Thread.currentThread().getName() + "还剩" + tickets + "张票");
//                tickets--;
//                Thread.sleep(100);
//            } catch (InterruptedException e) {
//                e.printStackTrace();
//            }
//        }
//    }
//}
//public class Synch
//{
//    public static void main(String[] args) {
//        MythreadB thread=new MythreadB();
//        new Thread(thread,"黄牛1").start();
//        new Thread(thread,"黄牛2").start();
//        new Thread(thread,"黄牛3").start();
//    }
//
//}


////同步代码块
//class MythreadB implements  Runnable
//{
//    private Integer tickets=10;
//    public void run()
//    {
//        for(int i=0;i<10;i++)
//        {
//            ////同步代码块，一次只允许一个线程进入该代码块
//            synchronized (this)
//            //锁住的是当前MythreadB对象，而只有一个MythreadB对象，3个线程是通过MythreadB转换为Thread创建出来的，
//            // 所以实现了同步，一次只能有线程卖票，一个线程卖完一张票后，隐式解锁，其他线程可以卖票
//            {
//                  if(tickets>0) {
//                    try {
//                        System.out.println(Thread.currentThread().getName() + "还剩" + tickets + "张票");
//                        tickets--;
//                        Thread.sleep(20);
//                    } catch (InterruptedException e) {
//                        e.printStackTrace();
//                    }
//                }
//            }
//        }
//    }
//}


////同步方法

//class MythreadB implements  Runnable
//{
//    private Integer tickets=10;
//    public void run()
//    {
//        for(int i=0;i<10;i++)
//        {
//            sale();
//        }
//    }
//    synchronized public void sale()  //同步方法，表示同一时刻只能有一个线程进入该方法，锁住的是MythraedB对象
//    {
//        if(tickets>0) {
//            try {
//                System.out.println(Thread.currentThread().getName() + "还剩" + tickets + "张票");
//                tickets--;
//                Thread.sleep(20);
//            } catch (InterruptedException e) {
//                e.printStackTrace();
//            }
//        }
//    }
//}


////并没有锁住整个类

//class A
//{
//    synchronized public void print()
//    {
//        System.out.println(Thread.currentThread().getName()+":进入print方法");
//        try {
//            Thread.sleep(100);
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }
//        System.out.println(Thread.currentThread().getName()+":离开print方法");
//    }
//
//}
//class MythreadB implements  Runnable
//{
//    public void run()
//    {
//       A myA=new A();
//       myA.print();
//    }
//}
//public class Synch
//{
//    public static void main(String[] args) {
//        MythreadB thread=new MythreadB();
//        new Thread(thread,"线程1").start();
//        new Thread(thread,"线程2").start();
//        new Thread(thread,"线程3").start();
//    }
//}


//////锁同一个对象
//class A
//{
//    synchronized public void print()
//    {
//        System.out.println(Thread.currentThread().getName()+":进入print方法");
//        try {
//            Thread.sleep(100);
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }
//        System.out.println(Thread.currentThread().getName()+":离开print方法");
//    }
//
//}
//class MythreadB implements  Runnable
//{
//    private A myA;  //现在就只有一个A对象
//
//    public MythreadB(A a)
//    {
//        this.myA=a;
//    }
//
//    public void run()
//    {
//        this.myA.print();
//    }
//}
//public class Synch
//{
//    public static void main(String[] args) {
//        MythreadB thread=new MythreadB(new A());
//        new Thread(thread,"线程1").start();
//        new Thread(thread,"线程2").start();
//        new Thread(thread,"线程3").start();
//    }
//}

////锁class对象，静态同步方法
//class A
//{
//    synchronized static  public void print()
//    //定义为静态方法，也就是将A这个类锁住，那么同一时刻，只能有一个类对象进入代码块
//    {
//        System.out.println(Thread.currentThread().getName()+":进入print方法");
//        try {
//            Thread.sleep(100);
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }
//        System.out.println(Thread.currentThread().getName()+":离开print方法");
//    }
//
//}

////  同步代码块 ：synchronized(类名称.class)
//class A
//{
//      public void print()
//      {
//          synchronized (A.class)
//          {
//              System.out.println(Thread.currentThread().getName() + ":进入print方法");
//              try {
//                  Thread.sleep(100);
//              } catch (InterruptedException e) {
//                  e.printStackTrace();
//              }
//              System.out.println(Thread.currentThread().getName() + ":离开print方法");
//          }
//      }
//}
//class MythreadB implements  Runnable
//{
//    public void run()
//    {
//      new A().print();
//    }
//}
//public class Synch
//{
//    public static void main(String[] args) {
//        MythreadB thread=new MythreadB();
//        new Thread(thread,"线程1").start();
//        new Thread(thread,"线程2").start();
//        new Thread(thread,"线程3").start();
//    }
//}

//线程1进入同步方法1，线程2能否进入同步方法2
class A
{
    ////线程1持有A实例化出对象锁，并且一直死循环
      public void testA() {
         if (Thread.currentThread().getName().equals("线程1")) {
             while (true) {
             }
         }
     }

     ///线程2进入testB
     synchronized public void testB() {
         if (Thread.currentThread().getName().equals("线程2")) {
             System.out.println("线程2进入同步");
         }
     }
}
class MythreadB implements  Runnable
{
    private A myA;
    public MythreadB(A a)
    {
        this.myA=a;
    }
    public void run()
    {
       this.myA.testA();
       this.myA.testB();
    }
}
public class Synch
{
    public static void main(String[] args) {
        MythreadB thread=new MythreadB(new A());
        new Thread(thread,"线程1").start();
        new Thread(thread,"线程2").start();
    }
}



