class Test
{
    public Test()
    {
         System.out.println("Test构造方法");
    }
    {
         System.out.println("Test构造块");
    }
    //非主类静态代码块
    static
    {
        System.out.println("Test非主类静态代码块");
    }     
}
public class Codeblock
{
    public static void main(String[] args)
    {
        new Test();  //构造两个Test匿名对象
        new Test();   
    }
}
//主类中静态代码块
// public class Codeblock
// {
//     public Codeblock()
//     {
//         System.out.println("主类构造方法");
//     }
//     static   //静态代码块 
//     {
//         System.out.println("主类静态代码块");
//     }
//     {
//         System.out.println("主类构造块");
//     }
//     public static void main(String[] args)
//     {
//         System.out.println("--main start--");
//         new Codeblock();  //匿名对象  会调构造方法和构造块
//         new Codeblock();  //匿名对象
//         System.out.println("--main end--");
//     }
// }