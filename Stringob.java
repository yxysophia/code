/////字符串比较
public class Stringob
{
    public static void main(String[] args)
    {
        String str=null;  //假设有由用户输入为空
        //System.out.println(str.equals("hello"));  //报错：NullPointerException
        System.out.println("hello".equals(str));  //推荐使用此种比较方法，将特定字符串"hello"写在前边
    }
}
//////对象池
public class Stringob
{
    public static void main(String[] args)
    {
        String str1="hello";
        String str2="hello";
        String str3="hello";
        System.out.println(str1==str2);  //true
        System.out.println(str2==str3);  //true
        //"hello"是直接赋值，已经在对象池，所以str2和str3也指向str1指向的内容
        String str4=new String("hello");
        System.out.println(str1==str4); //false

        ///手动入池
        String str5=new String("hello").intern(); //手动入池
        System.out.println(str5==str1); //true  因为str5入池
    }
}
////////面试题：String两种实例化区别：
//1. 直接赋值：只会开辟一块堆内存空间，并且该字符串对象可以自动保存在对象池中以供下次使用。
//2. 构造方法：会开辟两块堆内存空间，其中一块成为垃圾空间，不会自动保存在对象池中，可以使用intern()方法手工入池。
//(比如：String str=new String("hello")),"hello"成为垃圾空间，新new的空间str指向。
public class Stringob
{
    public static void main(String[] args)
    {
        String str="hello";
        str = str + " world";
        str+="!!!";
        System.out.println(str);  //hello world!!!  字符串内容不可变，但引用可变
    }
}