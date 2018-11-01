package CODE;


import com.sun.xml.internal.bind.v2.model.core.ID;

////传统在主方法中子类为接口实例化对象
//interface IDrinkI
//{
//    void drinkKind();
//}
//class CoffeeImpl implements IDrinkI
//{
//    public void drinkKind()
//    {
//        System.out.println("煮咖啡");
//    }
//}
//class TeaImpl implements IDrinkI
//{
//    public void drinkKind()
//    {
//        System.out.println("泡茶");
//    }
//}
//public class Factory1
//{
//    public static void main(String[] args)
//    {
//        IDrinkI drink1=new CoffeeImpl();
//        drink1.drinkKind();
//        IDrinkI drink2=new TeaImpl();
//        drink2.drinkKind();
//    }
//}


/////简单工厂模式
interface IDrinkI
{
    void drinkKind();
}
class Factory
{
    //Factory是为了生产对象，没必要实例化一个工厂对象，所以声明为static，在外用类来调用该方法
    public static IDrinkI getInfor(String drinkName)
    {
        System.out.println("请问您需要什么饮料");
        System.out.println(drinkName);
        if("coffee".equals(drinkName))
        {
            return  new CoffeeImpl();
        }
        else if("tea".equals(drinkName))
        {
            return new TeaImpl();
        }
        return null;
    }
    //此时，根据用户需求只需要修改Factory这个工厂类即可
}
class CoffeeImpl implements IDrinkI
{
    public void drinkKind()
    {
        System.out.println("煮咖啡");
    }
}
class TeaImpl implements IDrinkI
{
    public void drinkKind()
    {
        System.out.println("泡茶");
    }
}
public class Factory1
{
    public static void main(String[] args)
    {
        if(args.length==0)
        {
            System.out.println("没有命令行参数，程序退出");
            System.exit(1) ; // 退出程序
        }
        IDrinkI drink1=Factory.getInfor(args[0]);
        drink1.drinkKind();
    }
}