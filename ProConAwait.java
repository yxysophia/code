package LockPack;


import java.util.concurrent.*;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

class Goods
{
    private Integer maxCount;  //商品最大值
    private Integer count=0;
    private ReentrantLock lock=new ReentrantLock();
    private Condition proConditon =lock.newCondition();  //生产者等待队列
    private Condition conCondition =lock.newCondition();  //消费者等待队列

    public Goods(Integer macCount) {
        this.maxCount = macCount;
    }

    public void Pro(String goodsName) {
        lock.lock();
        try {
            {
                while (count == maxCount) {
                    try {
                        System.out.println("生产者生产大最大最，稍后生产");
                        proConditon.await(); //  生产者队列等待
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                count++;
                System.out.println(Thread.currentThread().getName() + "生产" + goodsName + ":" + count);
                conCondition.signalAll();
            }
        }finally {
            lock.unlock();
        }
    }

    public void Con()
    {
        lock.lock();
        try{
            while(count==0)
            {
                System.out.println("没有商品，稍后来消费");
                try {
                    conCondition.await();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            try {
                Thread.sleep(20);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            count--;
            System.out.println(Thread.currentThread().getName()+"消费:"+count);
            proConditon.signal();
        }finally {
            lock.unlock();
        }
    }
}

class ILock implements Runnable
{
    private  Goods goods;
    private int flag=1;

    public ILock(Goods goods, int flag) {
        this.goods = goods;
        this.flag = flag;
    }


    @Override
    public void run() {
        if(flag==1)
        {
            while(true)
            goods.Pro("奥利奥");
        }
        else
        {
            while(true)
            goods.Con();
        }
    }
}
public class ProConAwait {
    public static void main(String[] args) {
        Goods goods=new Goods(50);
        ILock proiLock=new ILock(goods,1);
        ILock conLock=new ILock(goods,2);
        new Thread(proiLock,"生产者1").start();
        new Thread(proiLock,"生产者2").start();
        new Thread(proiLock,"生产者3").start();
        new Thread(conLock,"消费者1").start();
        new Thread(conLock,"消费者2").start();
    }
}
