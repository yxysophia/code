//静态代码块在加载类的时候用到
//构造块和构造函数在对象产生时，构造块优先于构造函数
class HelloA
{
    public HelloA()
    {
        System.out.println("父类构造方法");       
    }
    {
        System.out.println("父类构造块");
    }
    static
    {
        System.out.println("父类静态代码块");
    }

}
public class HelloB extends HelloA
{
    public HelloB()
    {
        System.out.println("子类构造方法");
    }
    {
        System.out.println("子类构造块");
    }
    static
    {
        System.out.println("子类静态块");
    }
    public static void main(String[] args)
    {
        System.out.println("--stat---");
        HelloB b1=new HelloB();  //调用构造块和构造函数
        HelloB b2=new HelloB();
        System.out.println("--end--");
    }
}