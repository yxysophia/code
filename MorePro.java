package CODE.多线程;


////生成者消费者模型

import java.util.ArrayList;
import java.util.List;

class MoreGoods
{
    private String goodsName;  //商品名称
    private int counts;       //商品数量

    synchronized public void pro(String goodsName)  {
         //20ms生产一个商品
         try {
                Thread.sleep(20);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            counts++;
            this.goodsName=goodsName;
            System.out.println(Thread.currentThread().getName()+"生产"+this.goodsName+":"+counts);
            notifyAll(); //唤醒等待的消费者

    }
    synchronized public void Con()
    {
        //用循环是因为如果一消费者等待一会后，另一个消费者将唯一的产品消费，那么该消费者就需要再重新判断是否有资源消费
            while (counts <= 0) {
                try {
                    System.out.println("等一会来买，没有库存");
                    wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            //100ms消费一个
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        counts--;
        System.out.println(Thread.currentThread().getName() + "消费" + this.goodsName + ":" + counts);

    }
    public int getCounts() {
        return counts;
    }
}
class MoreTrade implements Runnable
{
    private MoreGoods goods;
    //生产者生产产品
    private int flag;

    public MoreTrade(MoreGoods goods, int flag) {
        this.goods = goods;
        this.flag = flag;
    }

    @Override
    public void run() {

        if (flag == 1) {
            while (goods.getCounts() < 200) {
                goods.pro("奥利奥饼干");
            }
        } else {
            while (true)
                goods.Con();

        }
    }
}
public class MorePro {
    public static void main(String[] args) {
        MoreGoods goods = new MoreGoods();
        List<Thread> list=new ArrayList<>();  //数组存的是生产消费线程，因为生产消费线程需要同时启动
        //5个生产者
        for(int i=0;i<5;i++)
        {
            Thread thread=new Thread(new MoreTrade(goods,1),"生产者"+i);
            list.add(thread);
        }
        //3个消费者
        for(int i=0;i<3;i++)
        {
            Thread thread=new Thread(new MoreTrade(goods,0),"消费者"+i);
            list.add(thread);
        }
        for(Thread thread:list) {
           thread.start();  //将所有线程都启动
        }
    }
}

