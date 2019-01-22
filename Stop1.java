package CODE.线程复习;

//线程停止
class IStop implements Runnable
{
    public void run()
    {
        int i=0;
        while(true)
        {
            try {
                Thread.sleep(1000);
                boolean bool=Thread.currentThread().isInterrupted();
                if(bool)
                {
                    System.out.println("非阻塞情况下线程为中断状态");
                    break;
                }
                System.out.println("第"+i+"次进入for循环");
                i++;
            } catch (InterruptedException e) {
                //sleep遇到中断状态，会将状态状态置为false
                boolean bool=Thread.currentThread().isInterrupted();
                System.out.println(bool);
                return ;
            }

        }
    }
}
public class Stop1 {
    public static void main(String[] args) throws InterruptedException {
        Runnable runnable=new IStop();
        Thread thread=new Thread(runnable);
        thread.start();
        Thread.sleep(5000);
        thread.interrupt();  //线程状态变为中断
    }
}
