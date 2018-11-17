package CODE.多线程;

//编些一个程序，启动三个线程，三个线程的名字分别是A,B,C，每个线程将自己的名字在屏幕上打印5遍，打印顺序分别是ABCABC



class Print1 {
    private int counts = 1;

    public synchronized void printA() {
        while (counts < 17) {
            //第2位和第三位
            while (counts % 3 == 2 || counts % 3 == 0) {
                try {
                    wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            System.out.println(Thread.currentThread().getName() + ":" + "A");
            counts++;
            notifyAll();
        }
    }

    public synchronized void printB() {
        while (counts < 17) {
            while (counts % 3 == 1 || counts % 3 == 0) {
                try {
                    wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            System.out.println(Thread.currentThread().getName() + ":" + "B");
            counts++;
            notifyAll();
        }
    }

    public synchronized void printC() {

        while(counts<17)
        {
            while (counts % 3 == 2 || counts % 3 == 1) {
                try {
                    wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            System.out.println(Thread.currentThread().getName() + ":" + "C");
            counts++;
            notifyAll();
        }
    }

}
class AThread implements Runnable
{
    private Print1 print1;

    public AThread(Print1 print1) {
        this.print1 = print1;
    }
    @Override
    public void run()
    {
        print1.printA();
    }
}
class BThread implements Runnable
{
    private Print1 print1;

    public BThread(Print1 print1) {
        this.print1 = print1;
    }
    @Override
    public void run()
    {
        print1.printB();
    }
}
class CThread implements Runnable
{
    private Print1 print1;

    public CThread(Print1 print1) {
        this.print1 = print1;
    }
    @Override
    public void run()
    {
        print1.printC();
    }
}
public class ABC
{
    public static void main(String[] args)
    {
        Print1 print1=new Print1();
        new Thread(new AThread(print1),"线程A").start();
        new Thread(new BThread(print1),"线程B").start();
        new Thread(new CThread(print1),"线程C").start();

    }
}
