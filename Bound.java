package CODE.多线程;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

//Conditon实现有界队列
class BoundQueue<T>
{
    private Object[] items;
    private int counts=0;  //intems中元素个数
    private Lock lock=new ReentrantLock();
    private Condition fullCondition=lock.newCondition();
    private Condition emptyCondition=lock.newCondition();
    public BoundQueue(int size)
    {
        items=new Object[size];
    }

    //向数组里添加元素，如果数组满，进入等待状态
    public void add(T t,int addIndex) throws InterruptedException {
        try
        {
            lock.lock();
            //数组已满，添加线程需要进入等待状态
            while(counts==items.length)
            {
                fullCondition.await();
            }
            items[addIndex]=t;
            counts++;
            //元素添加完毕，需要唤醒清空队列
            emptyCondition.signal();
        }finally {
            lock.unlock();
        }

    }
    //删除元素方法，如果当前数组为空，移除线程进入等待状态直到数组不为空
    public T remove(int removeIndex) throws InterruptedException {
        try
        {
            lock.lock();
            while(counts==0)
            {
               emptyCondition.await();
            }
            Object x=items[removeIndex];
            counts--;
            //唤醒添加线程
            fullCondition.signal();
            return (T)x; //从大类型到小类型需要强转
        }finally {
            lock.unlock();
        }
    }

}
class MyThread implements Runnable
{
    private BoundQueue boundQueue;
    private int flag;
    public MyThread(int flag,BoundQueue boundQueue)
    {
        this.boundQueue=boundQueue;
        this.flag=flag;
    }
    public void run()
    {
        if(flag==1)
        {
            try {
                System.out.println(Thread.currentThread().getName()+"在添加元素");
                boundQueue.add("asb",0);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        else
        {
            try {
                boundQueue.remove(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
public class Bound {

}
