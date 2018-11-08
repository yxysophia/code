package CODE.Java新特性;

interface IA
{
    void func1(); //抽象方法
    default void func2()
    {
        System.out.println("接口中default方法");
    }
    static void func3()
    {
        System.out.println("接口中static方法");
    }

}

class AImpl implements IA
{
    public void func1()
    {
        System.out.println("func()");
    }
}
public class Interf
{
    public static void main(String[] args)
    {
        IA a1=new AImpl();
        //接口的抽象方法
        a1.func1(); //func()
        //接口的default普通方法，通过对象调用
        a1.func2();  //接口中default方法
        //接口的static普通方法，通过接口名调用
        IA.func3(); //接口中static方法
    }
}
