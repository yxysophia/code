package CODE.多线程;

//编些一个程序，启动三个线程，三个线程的名字分别是A,B,C，每个线程将自己的名字在屏幕上打印5遍，
// 打印顺序分别是ABCABC
class Print3
{
    private int flag=1;
    synchronized public void printA()
    {
        while(flag!=1)
        {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println(Thread.currentThread().getName());
        flag=2;
        notifyAll();
    }
    synchronized public void printB()
    {
        while(flag!=2)
        {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println(Thread.currentThread().getName());
        flag=3;
        notifyAll();
    }
    synchronized public void printC()
    {
        while(flag!=3)
        {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println(Thread.currentThread().getName());
        flag=1;
        notifyAll();
    }
}

public class ABC1
{
    public static void main(String[] args) {
        Print3 print3=new Print3();
        new Thread(()->
        {
            for(int i=0;i<5;i++)
            print3.printA();
        }).start();
        new Thread(()->
        {
            for(int i=0;i<5;i++)
                print3.printB();
        }).start();
        new Thread(()->
        {
            for(int i=0;i<5;i++)
                print3.printC();
        }).start();
    }
}
