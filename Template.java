// public class Work2
// {
//     public static void fib(int n)
//     {
//         int prev=1;
//         int pprev=1;
//         int result=1;
//         if(n==1||n==2)
//         {
//             System.out.print(1+" ");
//         }
//         System.out.print(1+" ");
//         System.out.print(1+" ");
//         for(int i=3;i<=n;i++)
//         {
//             result=prev+pprev;
//             System.out.print(result+" ");
//             pprev=prev;
//             prev=result;
//         }
//     }
//     public static void main(String[] args)
//     {
//         fib(5);
//     }
// }
//作业1
// class Test
// {
//     public int a;
//     public char c;
//     public long l;
// }
// public class Work2
// {
//     public static void main(String[] args)
//     {
//         Test t1=new Test();
//         // System.out.println(t1.a);  //0 
//         // System.out.println(t1.c);  //空格
//         // System.out.println(t1.l);  // 0
//         System.out.println(t1.a+"p"+t1.c+"i"); //0p i  说明t1.c是空格
//     }
// }
class Test
{
    public int a;
    public Test()
    {
        System.out.println("Hello Constructor");
    }
    public Test(String s)
    {
        this();
        System.out.println(s);
    }
}
public class Work2
{
    public static void main(String[] args)
    {
        Test t=new Test("张三");
    }
}