//////////简述下列程序运行结果
class A
{
    static int y=6;
    class Inner
    {
       static int y=3;  //错误 成员内部类不允许有static变量，静态变量和对象无关
        void show()
        {
            System.out.println(y);
        }
    }
}
public class In
{
    public static void main(String[] args)
    {
        A.Inner inner=new A().new Inner();
        inner.show();
    }
}
/////////上面程序运行结果是编译错误，内部类A.Inner中的静态声明非法

//////////简述下列程序运行结果
class A
{
    public A()
    {
        System.out.println("A");
    }
}
class B extends A
{
    public B()
    {
        System.out.println("B");
    }
}
public class In
{
    public static void main(String[] args)
    {
        B b=new B();  // A  B
    }
}

//////////////
class Father
{
    private String _name="zhangjun";
    class Child
    {
        public void inforFather()
        {
            System.out.println(_name);
        }
    }
}
public class In
{
    public static void main(String[] args)
    {
        Father.Child c=new Father().new Child();
        c.inforFather();  //zhnagjun 
    }
}