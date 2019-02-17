import java.util.concurrent.*;

class Mthread implements Runnable
{
    @Override
    public void run() {
        for(int i=0;i<10;i++)
        {
            System.out.println(Thread.currentThread().getName()+"、"+i);
        }
    }
}
class MCallThread implements Callable<String>
{
    @Override
    public String call() {
        for(int i=0;i<10;i++)
        {
            System.out.println(Thread.currentThread().getName()+"、"+i);
        }
        return Thread.currentThread().getName()+"执行完毕";
    }
}


//public class TestExecutor {
//    public static void main(String[] args) {
//       MCallThread mthread=new MCallThread();
//        ExecutorService executorService=new ThreadPoolExecutor(
//                3,5,2000,TimeUnit.MILLISECONDS,
//                new LinkedBlockingDeque<>());  //创建线程池
//        for(int i=0;i<4;i++)
//        {
//            Future<String> future=executorService.submit(mthread);
//            try {
//                System.out.println(future.get());
//            } catch (InterruptedException e) {
//                e.printStackTrace();
//            } catch (ExecutionException e) {
//                e.printStackTrace();
//            }
//        }
//        executorService.shutdown();
//    }
//}


//定时调度池

public class TestExecutor {
    public static void main(String[] args) {
        Mthread mthread = new Mthread();
        ScheduledExecutorService scheduledExecutorService =
                Executors.newScheduledThreadPool(3);
        scheduledExecutorService.scheduleAtFixedRate(mthread, 3, 2,TimeUnit.SECONDS);//3秒后开始执行
        scheduledExecutorService.shutdown();
    }
}

