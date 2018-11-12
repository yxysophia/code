package CODE.多线程;

////线程停止


////使用标记位
class Mythread3 implements  Runnable
{
    private boolean flag=true;
    public void run()
    {
        int i=1;
        while(flag)
        {
            try {
                Thread.sleep(1000);
                System.out.println(i+"次进入for循环" );
                i++;
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void setFlag(boolean flag) {
        this.flag = flag;
    }
}
public class Stop1
{
    public static void main(String[] args) throws InterruptedException {
        Mythread3 thread=new Mythread3();
        Thread thread1=new Thread(thread,"子线程");
        thread1.start();
        Thread.sleep(4000); //主线程4秒后会将thread1的falg置false,那么就会推出循环，子线程就会停止
        thread.setFlag(false);
    }
}


//////使用stop
//import java.text.DateFormat;
//import java.text.SimpleDateFormat;
//import java.util.Date;
//
//class Mythread3 implements  Runnable
//{
//   private boolean falg=true;
//    public void run()
//    {
//
//        System.out.print("子线程运行时间");
//        Stop1.printTime();
//        int i=1;
//        while(true)
//        {
//            try {
//                Thread.sleep(1000);
//                System.out.print("子线程第"+i+"次进入for循环时间");
//                Stop1.printTime();
//                i++;
//            } catch (InterruptedException e) {
//                e.printStackTrace();
//            }
//
//        }
//    }
//}
//public class Stop1
//{
//    public static void main(String[] args) throws InterruptedException {
//        Mythread3 thread=new Mythread3();
//        Thread thread1=new Thread(thread,"子线程");
//        thread1.start();
//        System.out.println("");
//        System.out.println("");
//        System.out.print("子线程stop前4秒时间:");
//        printTime();
//        Thread.sleep(4000); //主线程4秒后会将执行thread1.stop，使子线程停止
//        thread1.stop();
//        System.out.print("子线程结束时间：");
//        printTime();
//    }
//    public static  void printTime()
//    {
//        Date date=new Date();
//        DateFormat dateFormat=new SimpleDateFormat(("yyyy-MM-dd HH:mm:ss"));
//        String time=dateFormat.format(date);
//        System.out.println(time);
//    }
//}


////使用Thread.interupt方法

//class Mythread3 implements  Runnable
//{
//    public void run() {
//        int i = 1;
//        while (true) {
//            try {
//                Thread.sleep(1000);
//                boolean bool = Thread.currentThread().isInterrupted();//当前线程是否被置为中断状态，是返回ture
//                //如果状态被置为中断状态，并且处于阻塞状态，会抛异常java.lang.InterruptedException，catch处理异常，不会走这个if语句
//                if (bool) {
//                    System.out.println("非阻塞情况下执行该操作....线程状态" + bool);
//                    break;
//                }
//                System.out.println("第" + i + "次执行，线程名称为:" + Thread.currentThread().getName());
//                i++;
//            } catch (InterruptedException e) {
//                //抛异常后，中断标志被系统会自动清除，线程中断状态由true变为false
//                boolean bool = Thread.currentThread().isInterrupted();
//                System.out.println(bool);  //false
//                return;  //退出run方法
//            }
//
//        }
//    }
//
//}
//public class Stop1
//{
//        public  static void main(String[] args) throws InterruptedException {
//            Mythread3 thread = new Mythread3();
//            Thread thread1 = new Thread(thread, "子线程");
//            thread1.start();
//            Thread.sleep(4000);
//           thread1.interrupt();//现在线程thread1为中断状态
//        }
//}
