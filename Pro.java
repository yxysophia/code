package CODE.生产者消费模型;


////生产者消费者模型
class Goods
{
    private String goodsName;
    private Integer counts;  //商品数量

    //生产者
    public synchronized void set(String goodsName)
    {
        if(counts>0)
        {
            System.out.println("库存中还有此商品,一会儿再生产");
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        else
        {
            this.goodsName=goodsName;
            this.counts++;
            System.out.println("生产者生产"+toString());
        }
        notify(); //唤醒消费者

    }
    public String getGoodsName()
    {
        return goodsName;
    }
    @Override
    public String toString()
    {
       return "goodname:"+this.goodsName+ " counts:"+this.counts;
    }
    public synchronized  void get() {
        if (counts == 0) {
            System.out.println("商品售罄，等会儿来买");
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        counts--;
        System.out.println("消费者消费" + toString());
        notify();//唤醒生产者
    }
}
class Produer implements Runnable
{
    private Goods goods;
    public Produer(Goods goods)
    {
        this.goods=goods;
    }
    public void run()
    {
        goods.set(goods.getGoodsName());
    }
}
public class Pro {
    public static void main(String[] args) {
        Goods goods=new Goods();
    }
}
