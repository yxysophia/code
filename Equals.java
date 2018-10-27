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
        return "姓名："+name+"/"+"年龄："+age ;
    }
    public boolean equals(Object obj)
    {
        //判断obj是否是Person实例，因为Object可以接受所有类的实例
        if(!(obj instanceof Person))
        {
            return false;  //obj不是Person实例，直接返回错，两个对象不是一个类就没必要比较
        }
        if(this==obj)  //是同一个对象
        {
            return true;
        }
        Person per=(Person)obj; //需要向下转型，变回Person类，因为obj里没有Person里的属性
        return (per.name.equals(this.name)) && (per.age==this.age);
    }
}
public class Equals
{
    public static void main(String[] agrs)
    {
        Person per1=new Person("pick",18);
        Person per2=new Person("pick",18);
        System.out.println(per1); //系统输出默认调用对象的toString
        System.out.println(per1.toString());   
        System.out.println(per1.equals(per2));
    }
}
