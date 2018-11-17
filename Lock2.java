package CODE.多线程;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.AbstractQueuedSynchronizer;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

class Mutex implements Lock
{
    private Sync sync=new Sync();  //实例化一个对象为了调静态内部类的方法
    static class Sync extends AbstractQueuedSynchronizer
    {
        /*
        获取锁成功返回true,否则返回false
         */
        @Override
        protected boolean tryAcquire(int arg) //独占式获取同步状态
        {
            if(arg!=1)
            {
                throw new RuntimeException("信号量不为1，无法获取锁");
            }
            if(compareAndSetState(0,1))  //预期值是0，即没有线程获取锁，更新值为1
            {
                //此时线程成功获取同步状态
                setExclusiveOwnerThread(Thread.currentThread()); //将该线程设置为当前锁的持有者
                return true;
            }
            return false;
        }
        /*
        释放锁
         */
        @Override
        protected boolean tryRelease(int arg) {
            if(arg!=1) //只有当该线程持有该锁，才有释放锁
            {
                throw new IllegalMonitorStateException();
            }
            setExclusiveOwnerThread(null); //将锁持有者设为空
            setState(0); //没有线程获取锁
            return true;
        }
        /*
        判断该线程是否持有该锁
         */
        @Override
        protected boolean isHeldExclusively() {
          return getState()==1;
        }
    }


    //接口需要覆写的方法
    @Override
    public boolean tryLock(long time, TimeUnit unit) throws InterruptedException {
        return false;
    }


    @Override
    public void lock() {
        sync.acquire(1);  //获取锁

    }

    @Override
    public void lockInterruptibly() throws InterruptedException {
        sync.acquireInterruptibly(1);
    }

    @Override
    public boolean tryLock() {
        return sync.tryAcquire(1);
    }

    @Override
    public void unlock() {
        sync.release(1);
    }

    @Override
    public Condition newCondition() {
        return null;
    }
}
public class Lock2
{
    private static Mutex mutex = new Mutex();
    public static void main(String[] args){
        for (int i = 0; i < 10;i++){
            Thread thread = new Thread(()-> {
                mutex.lock();
                try {
                    Thread.sleep(3000);
                }catch (Exception e) {
                    e.printStackTrace();
                }finally {
                    mutex.unlock();
                }
            });
            thread.start();
        }
    }
}
