package CODE;

/////子类继承父类和实现抽象类
//interface  IA  //IA是一个接口，为了区别类在接口前加I
//{
////    abstract public void func1(); //抽象方法
////    static final int a=10;     //全局常量，必须在声明时初始化，因为用final声明
//      void func1(); //  默认为抽象方法
//      int a=10;     //默认全局常量，
//}
//interface  IB
//{
//   void func2();  //抽象方法
//}
//abstract class C
//{
//    abstract public void func3();
//}
//class ABCImpl extends C implements IA,IB  //继承了抽象类，2个接口
//{
//    public void func3()
//    {
//        System.out.println("子类实现抽象类C");
//    }
//    public void func2()
//    {
//
//        System.out.println("子类实现接口IB");
//    }
//    public void func1()
//    {
//        System.out.println("子类实现接口IA");
//    }
//}
//
//
//public class Interface1
//{
//    public static void main(String[] args)
//    {
//        IA a1=new ABCImpl(); //向上转型，为父接口实例化对象
//        a1.func1();  //调用子类覆写的func1()  ->子类实现接口IA
//        IB b1=(IB)a1;  //父接口之间的相互转化,a1是通过子类AImpl new出来的
//        b1.func2();  //调用子类覆写的func2()  ->子类实现接口IB
//        C c1=(C)b1;
//        c1.func3(); // 父接口和父类之间的相互专户 ->子类实现抽象类C
//    }
//}


/////抽象类实现（interface)接口
interface  IA
{
    void func1();
}
abstract class AImpl implements  IA  //AImpl是抽象类，抽象类可以不覆写接口中的抽象方法
{
    abstract public void func2(); //抽象方法，而且abstract不可省略，否则是普通方法
}
class A extends AImpl
{
    public void func1()
    {
        System.out.println("抽象类interface接口");
    }
    public void func2()
    {
        System.out.println("子类实现抽象类抽象方法");
    }
}
public class Interface1
{
    public static void main(String[] args)
    {
        IA a=new A();
        a.func1(); //抽象类interface接口
        //A是接口IA和抽象类AImpl的共同子类
        AImpl ai=(AImpl)a;
        ai.func2(); //子类实现抽象类抽象方法
    }
}