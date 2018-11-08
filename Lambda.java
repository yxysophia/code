package CODE.Java新特性;

////Lambda表达式

////实现体有一行语句（return 可以省）
@FunctionalInterface   //接口只能有一个抽象方法
interface  IB
{
    void add(int a,int b );

}

//public class Lambda
//{
//    public static void main(String[] args)
//    {
//        // ( )代表方法的参数列表() ,->后面内容代表方法的方法体
//        IB b2=(int a,int b)-> System.out.println("使用lambda表达式:"+(a+b));
//        b2.add(3,4);
//    }
//}


//实现体有多行语句
@FunctionalInterface
interface IC
{
    boolean Compare(int a,int b);
}

public class Lambda
{
    public static void main(String[] args)
    {
        //形参名称可以不同
       IC c=(int m,int n)->{
           {
               if(m>n)
                   return true;
               return false;   //此时return 不可省
           }
       };
        System.out.println(c.Compare(10,3));  //true
    }
}
