package LockPack;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.*;

class Mutex implements Lock
{
    private Sync sync=new Sync();
    public static  class Sync extends AbstractQueuedSynchronizer
    {
        @Override
        protected boolean tryAcquire(int arg) {  //独占式获取同步状态
            if(arg!=1)
            {
                throw  new RuntimeException("信号量不为1");
            }
            if(compareAndSetState(0,1))  //期望没人获取锁，将值改为1即当前线程获取锁
            {
                setExclusiveOwnerThread(Thread.currentThread());
                return true;
            }
            return false;
        }

        @Override
        protected boolean tryRelease(int arg) {
            if(arg!=1)
            {
                throw  new IllegalMonitorStateException();
            }
            setExclusiveOwnerThread(null);
            setState(0);
            return true;

        }

        @Override
        protected boolean isHeldExclusively() {
            return getState()==1;
        }
    }
    @Override
    public void lock() {
        sync.acquire(1);

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
    public boolean tryLock(long time, TimeUnit unit) throws InterruptedException {
        return false;
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
public class TestLock {

    public static void main(String[] args) {
       Mutex mutex=new Mutex();
        for(int i=0;i<10;i++)
        {
            new Thread(()->{
                mutex.lock();
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }finally {
                    mutex.unlock();
                }
            }).start();
        }
    }
}
