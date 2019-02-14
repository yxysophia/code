package StreamDemo;


import java.util.ArrayList;
import java.util.DoubleSummaryStatistics;
import java.util.List;

class Order
{
    private String good;
    private Double price;
    private int count;

    public Order(String good, Double price, int count) {
        this.good = good;
        this.price = price;
        this.count = count;
    }

    public Double getPrice() {
        return price;
    }

    public int getCount() {
        return count;
    }
}

//public class TestOrder {
//    public static void main(String[] args) {
//        List<Order> orderList=new ArrayList<>();
//        orderList.add(new Order("芭比",100.7,10));
//        orderList.add(new Order("hello kity",204.6,6));
//        orderList.add(new Order("水晶鞋",502.1,1));
//        orderList.add(new Order("魔仙棒",66.8,3));
//
//        //方法一：用for-each 计算这些商品的总价
//        double total=0.0;
//        for(Order order:orderList)
//        {
//            total+=order.getCount()*order.getPrice();
//        }
//        System.out.println(total); //2937.1
//
//        //方法二：map:计算每一件商品的总价，reduce:将所有商品价格进行汇总
//        //ruduce(left,right)---->left=left+right  orElse(0)是指假如是空指针，将值赋为0
//        double total1=orderList.stream().mapToDouble(o->o.getCount()*o.getPrice()).reduce((sum,ele)->sum+ele).orElse(0);
//        System.out.println(total1); //2397.1
//    }
//

//将所有商品的单个总价进行统计分析
public class TestOrder {
    public static void main(String[] args) {
        List<Order> orderList=new ArrayList<>();
        orderList.add(new Order("芭比",100.7,10));
        orderList.add(new Order("hello kity",204.6,6));
        orderList.add(new Order("水晶鞋",502.1,1));
        orderList.add(new Order("魔仙棒",66.8,3));

        //进行统计分析
        DoubleSummaryStatistics summaryStatistics=orderList.stream().mapToDouble(o->o.getPrice()*o.getCount()).summaryStatistics();
        //商品种类个数
        System.out.println(summaryStatistics.getCount()); //4
        //所有商品中总价最大的
        System.out.println(summaryStatistics.getMax()); //1227.6
        //所有商品的平均总价
        System.out.println(summaryStatistics.getAverage());//734.275

    }
}