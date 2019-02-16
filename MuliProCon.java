//多个生产者消费者

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.locks.Lock;

class MuGoods
{
    private String goodsName;
    private Integer count=0;

    public MuGoods(String goodsName) {
        this.goodsName = goodsName;
    }

    public Integer getCount() {
        return count;
    }

    synchronized public void Pro()  //生产者
    {
        //用循环，
        while (count>10)
        {
            System.out.println("库存还有 ，稍后生产");
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        try {
            Thread.sleep(20);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        count++;
        System.out.println(Thread.currentThread().getName()+"生产产品，库存"+count);
        notifyAll();
    }
    synchronized public void Con()  //消费者
    {
        while(count<=0)
        {
            try {
                System.out.println("没有商品，稍等一会儿"+count);
                wait();
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
        System.out.println(Thread.currentThread().getName()+"在消费产品，还剩"+count);
        notifyAll();
    }

}

class IMuProCon implements Runnable
{
    private  MuGoods goods;
    private Boolean flag;
    public IMuProCon(MuGoods goods) {
        this.goods = goods;
    }

    public IMuProCon(MuGoods goods, Boolean flag) {
        this.goods = goods;
        this.flag = flag;
    }

    @Override
    public void run() {
        while (true)
        {
            if(flag)
            {
                goods.Pro();
            }else
            {
                goods.Con();
            }
        }


    }
}
public class MuliProCon {
    public static void main(String[] args) {
        MuGoods muGoods=new MuGoods("安慕希");
        IMuProCon p=new IMuProCon(muGoods,true);
        IMuProCon c=new IMuProCon(muGoods,false);
        List<Thread> threadList=new ArrayList<>();
        for(int i=0;i<5;i++)
        {
            Thread proThread=new Thread(p,"生产者"+i);
            threadList.add(proThread);
        }
        for(int i=0;i<10;i++)
        {
            Thread conThread=new Thread(c,"消费者"+i);
            threadList.add(conThread);
        }

        for(int i=0;i<threadList.size();i++) {
            threadList.get(i).start();
        }
    }
}
