//Object可以接收任何类
class Person
{
    private String name;
    private int age;
    public Person(String name,int age)
    {
        this.name=name;
        this.age=age;
    }
    public String toString()
    {
        return this.name+" "+this.age;
    }
}
public class Ob
{
    public static void main(String[] args)
    {
        //使用对象输出时，默认是地址编码，如果是String,向上转型后，调用String的toString(),输出的是对象内容
        fun(new Person("pick",18)); //pick 18
        fun(new String("hello")); //hello
    }
    public static void fun(Object obj)
    {
        System.out.println(obj); //默认输出对象调用obj.toString();
    }
}

//对象比较
class Person
{
    private String name;
    private int age;
    public Person(String name,int age)
    {
        this.name=name;
        this.age=age;
    }
    public boolean equals(Object ob)
    {
        //判断obj是否是Person实例，因为Object可以接受所有类的实例
        if(!(ob instanceof Person))  //如果形参是null,涵盖在这个条件中，即null不是Person类
        {
            return false; //obj不是Person实例，直接返回错，两个对象不是一个类就没必要比较
        }
        if(this==ob) //是同一个对象
            return true;
        Person p=(Person)ob; //需要向下转型，变回Person类，因为obj里没有Person里的属性
        return ((this.name==p.name)&&(this.age==p.age));
    }
}
public class Ob
{
    public static void main(String[] args)
    {
       Person p1=new Person("pick",18);
       Person p2=new Person("pick",18); 
       System.out.println(p1.equals(null)); //false
       System.out.println(p1.equals(p2)); //true 
       System.out.println(p1.equals(p2)); //如果没有在Person中覆写equals，将输出false,因为除了equals默认比较的对象地址
    }
}

///Object可以接收引用类型

public class Ob
{
    public static void main(String[] args)
    {
        //Object接收数组类型
        Object ob=new int[]{1,2,3,4,5};  //Object接收引用数据类型
        int[] a=(int[]) ob;
        for(int num : a)
        {
            System.out.print(num+"、"); //1、2、3、4、5、
        }
    }
}
interface IA  //接口
{
    void func();//抽象方法，默认是public 和abstract
}
class AImpl implements IA
{
    public void func()
    {
        System.out.println("hello world");
    }
}
public class Ob
{
    public static void main(String[] args)
    {
        IA ia=new AImpl(); 
        Object ob=ia; //Object可以接收接口
        System.out.println(ob);//AImpl@15db9742
        IA a=(IA)ob; //将Object强转为IA
        a.func();//hello world
    }
}