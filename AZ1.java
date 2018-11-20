package CODE.多线程;
//
////写2个线程，一个线程打印1-52，另一个线程A-Z，12A34B56C...5152Z
//
class Print2
{
    private int flag=1;
    public int counts=1;
    synchronized public  void printNum() {

        while (flag == 0) {
            //flag=0，应该打印字母
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.print(counts * 2 - 1);
        System.out.print(counts * 2);
        flag = 0;
        notify();

    }
    synchronized public void printChar() {

        while (flag == 1) {
            //此时应该打印数字
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.print((char) (counts - 1 + 'A'));
        flag = 1;
        notify();
        counts++;

    }
}

public class AZ1
{
    public static void main(String[] args)
    {
        Print2 print2=new Print2();
        //2个线程，每个线程打印26次
        new Thread(()->
        {
            for(int i=0;i<26;i++)
            {
                print2.printNum();
            }
        }).start();
        new Thread(()->
        {
            for(int i=0;i<26;i++)
            {
                print2.printChar();
            }
        }).start();
    }

}
//class Print2
//{
//    private int flag=1;
//    public int counts=1;
//    synchronized public  void printNum()
//    {
//        while(counts<27)
//        {
//            if(flag==0)
//            {
//                try {
//                    wait();
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//            }
//            //加上if判断是因为wait会释放锁，假如第26次，当打印数字的线程后，尽管唤醒等待的字母线程，
//            //但是打印数字线程比打印字母线程先进入循环
//            // 这时counts=26，会进入循环，这时counts=26,但是应该到打印字母，于是会wait,等待打印字母后，counts++，变为27，所以要再次判断
//            if(counts<27)
//            {
//                System.out.print(counts*2-1);
//                System.out.print(counts*2);
//                flag=0;
//                notify();
//            }
//            else
//                break;
//        }
//    }
//    synchronized public void printChar()
//    {
//        while(counts<27)
//        {
//            if(flag==1)
//            {
//                try {
//                    wait();
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//            }
//            System.out.print((char)(counts-1+'A'));
//            flag=1;
//            notify();
//            counts++;
//        }
//    }
//}
//public class AZ1
//{
//    public static void main(String[] args) throws InterruptedException {
//      Print2 print2=new Print2();
//      new Thread(()->{
//          print2.printNum();
//      }).start();
//      new Thread(()->
//      {
//          print2.printChar();
//      }).start();
//    }
//}
