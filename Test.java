//protected 属性在同一包的子类可以访问
class A
{
    protected static int  age=10;
}

public class Test extends A
{
    public static void main(String[] args)
    {
       System.out.println(age);  //子类访问父类的protected权限 ，另外静态方法访问属性时，属性必须是static
    }
}