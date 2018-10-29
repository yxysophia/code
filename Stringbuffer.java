//字符串修改
public class Stringbuffer
{
    public static void main(String[] argds)
    {
        StringBuffer sb=new StringBuffer("hello"); //调用StringBuffer的构造方法将String转化为StringBuffer
        sb.append("world").append(123.4); //append可以接收任何类型
        System.out.println(sb);  //helloworld123.4 
    }
}

///String与StringBuffer的转化
public class Stringbuffer
{
    public static void main(String[] argds)
    {
        StringBuffer sb=new StringBuffer("hello"); 
        String str=sb.toString();
        System.out.println(sb);//hello 其实在这里默认调用了sb.toString()
        System.out.println(str); //hello
    }
}


///字符串的反转
public class Stringbuffer
{
    public static void main(String[] argds)
    {
        //字符串反转
        StringBuffer sb1=new StringBuffer("abcdef"); 
        sb1.reverse();
        System.out.println(sb1);//fedcba

        //删除指定范围数据
        StringBuffer sb2=new StringBuffer("hello dayworld");
        sb2.delete(6,9);  //左闭右开
        System.out.println(sb2);//hello world

        //插入数据
        StringBuffer sb3=new StringBuffer("abcdfg");
        sb3.insert(2,123);  //在下标为2的位置插入整型123
        System.out.println(sb3);//ab123cdfg
    }
}
