package CODE.多线程;

////生成者消费者模型

class Goods
{
    private String goodsName;  //商品名称
    private int counts;       //商品数量

    synchronized public void pro(String goodsName)
    {
        //产品数量大于0，等待消费者消费
        if(counts>0)
        {
            try {
                System.out.println("等一会生产，还有库存");
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        counts++;
        this.goodsName=goodsName;
        System.out.println(Thread.currentThread().getName()+"生产"+this.goodsName+":"+counts);
        notify(); //生产结束后，唤醒等待的消费者
    }
    synchronized public void Con()
    {
        //产品数量为0，等待生产者生产
        if(counts==0)
        {
            try {
                System.out.println("等一会来买，没有库存");
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        counts--;
        System.out.println(Thread.currentThread().getName()+"消费"+this.goodsName+":"+counts);
        notify(); //唤醒等待的生产者
    }

}
class Trade implements Runnable
{
    private Goods goods;
    //生产者生产产品
    private int flag;

    public Trade(Goods goods, int flag) {
        this.goods = goods;
        this.flag = flag;
    }

    @Override
    public void run()
    {
        if(flag==1)
        {
            goods.pro("奥利奥饼干");
        }
        else
        {
            goods.Con();
        }
    }
}
public class ProCon {
    public static void main(String[] args)
    {
        Goods goods=new Goods();
        new Thread(new Trade(goods,1),"生产者1").start();
        new Thread(new Trade(goods,0),"消费者1").start();
    }
}
