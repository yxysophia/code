//简单定义int包住类
class IntDemo
{
    private int num;
    public IntDemo(int num)
    {
        this.num=num;
    }
    public int value()
    {
        return this.num;
    }
}
public class Demo
{
    public static void main(String[] args)
    {
        Object ob=new IntDemo(10); //子类对象向上转型
        IntDemo a=(IntDemo)ob;  //向下转型，
        System.out.println(a.value()); //取出里面的基本数据类型操作
    }
}
//拆箱和装箱
public class Demo
{
    public static void main(String[] args)
    {
        Integer a=new Integer(10); //装箱
        int data=a.intValue();  //拆箱
        System.out.println(data); //10
    }
}

public class Demo
{
    public static void main(String[] args)
    {
        Integer a=10;
        System.out.println(a*3);//30
    }
}

//包装类的==和equals
public class Demo
{
    public static void main(String[] args)
    {
        Integer a1=new Integer(10);
        Integer a2=new Integer(10);
        System.out.println(a1==a2);  //false 因为==比较地址
        System.out.println(a1.equals(a2)); //true  比较对象内容

        Integer a3=20;
        Integer a4=20;
        Integer a5=170;
        Integer a6=170;
        System.out.println(a3==a4); //ture 因为对于直接赋值，如果值在-127-128之间，会入池
        System.out.println(a5==a6); //false   值没有在-127-128之间，不会入池，会在堆上产生
    }
}

//字符串好包装类的转换
public class Demo
{
    public static void main(String[] args)
    {
       String str1="123";
       int a=Integer.parseInt(str1) ;
       System.out.println(a); //123

       //字符串字母
       String str2="123abc";
       //int a2=Integer.parseInt(str2); //会报错:NumberFormatException.forInputString(NumberFormatException.
      
       boolean bo=Boolean.parseBoolean(str2);
       System.out.println(bo); //false，因为对于Boolean来说不是true,就是false
    }
}

////将基本数据类型转为字符串
public class Demo
{
    public static void main(String[] args)
    {
       String str1=String.valueOf(100); //将int转为String
       String str2=String.valueOf(10.3); //double 转为String
       String str3=""+'a';   //将字符转为字符串 
       System.out.println(str1); //100
       System.out.println(str2); //10.3
       System.out.println(str3); //a
    }
}