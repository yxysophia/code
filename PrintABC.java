//编写一个程序，启动三个线程，三个线程的名称分别是A,B,C；
// 每个线程将自己的名字在屏幕上打印5遍，打印顺序是
//ABCABCABCABCABC

class PrintABCI
{
    private Integer flag=1;
    private Integer count=1;  //打印次数

    public synchronized void printA()
    {
        while(flag!=1 )
        {
            try {
                wait();  //等待打印B或C
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.print('A');
        flag=2;
        notifyAll();
    }
    public synchronized void printB()
    {
        while(flag!=2 )
        {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.print('B');
        flag=3;
        notifyAll();
    }

    public synchronized void printC()
    {
        while(flag!=3)
        {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.print('C');
        count++;
        flag=1;
        notifyAll();
    }
}
public class PrintABC {
    public static void main(String[] args) {
        PrintABCI print=new PrintABCI();
        new Thread(new Runnable()
        {
            @Override
            public void run() {
                for(int i=0;i<5;i++)
                print.printA();
            }
        }).start();

        new Thread((new Runnable() {
            @Override
            public void run() {
                for(int i=0;i<5;i++)
                print.printB();
            }
        })).start();

        new Thread(new Runnable() {
            @Override
            public void run() {
                for(int i=0;i<5;i++)
                print.printC();
            }
        }).start();
    }

}
