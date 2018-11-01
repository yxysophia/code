package CODE;

/////代理模式

interface ICloths
{
    void buyCloths();  //核心功能是买衣服
}
class RealClothsImpl implements ICloths  //真实业务
{
    public void buyCloths()
    {
        System.out.println("买一件风衣");
    }
}
class ProClothsImpl implements ICloths  //代理业务
{
    private ICloths cloths;
    public ProClothsImpl(ICloths cloths)  //向上转型
    {
        this.cloths=cloths;
    }
    public void beforeBuy()
    {
        System.out.println("生产风衣");
    }
    public void afterBuy()
    {
        System.out.println("生产风衣售后团队");
    }
    public void buyCloths()
    {
        this.beforeBuy();   //业务办理前操作
        this.cloths.buyCloths();  //调用真实业务办理
        this.afterBuy();   //业务办理后操作
    }
}
class Factory   //工厂生产对象
{
    public static ICloths getInfor()
    {
        return new ProClothsImpl(new RealClothsImpl()); //proClothsImpl辅助真实业务
    }
}
public class RealFact
{
    public static void main(String[] args)
    {
        ICloths cloths=Factory.getInfor();
        cloths.buyCloths();
    }
}