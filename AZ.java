package CODE.多线程;


//写2个线程，一个线程打印1-52，另一个线程A-Z，12A34B56C...5152Z

import javax.print.attribute.standard.ReferenceUriSchemesSupported;

class Print {
    private int counts=1;
    private int num = 1;
    private Character ch = 'A';

    public synchronized void printNum() {
        while(num<=52)
        {
            if (counts % 3 == 0) {
                try {
                    wait(); //等待字母打印
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            System.out.print(num);
            num++;
            counts++;
            notify();
        }

    }
    public synchronized void printCh()
    {
        while(ch<='Z')
        {
            if(counts%3!=0)
            {
                try {
                    wait(); //等待数字打印
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            System.out.print(ch);
            ch++;
            counts++;
            notify();
        }
    }
}
class numThreaad implements Runnable
{
    private Print print;

    public numThreaad(Print print) {
        this.print = print;
    }

    @Override
    public void run()
    {
        print.printNum();
    }

}
class chThread implements Runnable
{
    private Print print;

    public chThread(Print print) {
        this.print = print;
    }

    @Override
    public void run()
    {
        print.printCh();
    }
}
public class AZ
{
    public static void main(String[] args)
    {
        Print print = new Print();
        new Thread(new numThreaad(print)).start();
        new Thread(new chThread(print)).start();
    }
}
