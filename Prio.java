package CODE.多线程;



//线程优先级



//主线程优先级
//public class Prio
//{
//    public static void main(String[] args)
//    {
//        System.out.println(Thread.currentThread().getPriority());  //主线程优先级为5
//    }
//}


/////设置线程优先级
//class  Mythraed3 implements Runnable
//{
//    public  void run()
//    {
//        for(int i=0;i<3;i++)
//        {
//            System.out.println(Thread.currentThread().getName()+":"+i);
//        }
//    }
//}
//
//public class Prio
//{
//    public static void main(String[] args)
//    {
//        Mythraed3 thread=new Mythraed3();
//        Thread thread1=new Thread(thread,"线程1");
//        Thread thread2=new Thread(thread,"线程2");
//        Thread thread3=new Thread(thread,"线程3");
//        thread1.setPriority(2);
//        thread2.setPriority(6);
//        thread3.setPriority(Thread.MAX_PRIORITY); //将线程3优先级设置最高
//        thread1.start();
//        thread2.start();
//        thread3.start();
//    }
//}


////线程具有继承性

class  Mythraed3 implements Runnable
{
    public  void run()
    {
        System.out.println(Thread.currentThread().getName()+"优先级为"+Thread.currentThread().getPriority());
        Thread thread=new Thread(new Mythraed4(),"线程2");
        thread.start(); //在线程1里启动线程2，线程2优先级和线程1优先级一样
    }
}
class Mythraed4 implements  Runnable
{
    public void run()
    {
        System.out.println(Thread.currentThread().getName()+"优先级为"+Thread.currentThread().getPriority());
    }
}
public class Prio
{
    public static void main(String[] args)
    {
        Mythraed3 thread=new Mythraed3();
        Thread thread1=new Thread(thread,"线程1");
        thread1.start();
        thread1.setPriority(3);
    }
}
