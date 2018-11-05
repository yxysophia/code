package CODE.高级开发之泛型;


import static CODE.泛型.Im.*;  //导入Im类里的所有静态方法和属性

///CODE.泛型.Im代码
//package CODE.泛型;
//
//public class Im
//{
//    public static int add(int a,int b)
//    {
//        return a+b;
//    }
//    public static int sub(int a,int b)
//    {
//        return a-b;
//    }
//}


public class ChangeEle
{
    public static void main(String[] args)
    {
        System.out.println(add(3,4)); // 静态导入后，直接调用静态方法
        System.out.println(sub(5,1));
    }
}

//可变参数
public class ChangeEle
{
    public static void main(String[] args)
    {
        System.out.println(add(new int[]{1,2,3})); //6
        System.out.println(add(new int[]{1,2,3,4,5}));  //15

        //用可变参数
        System.out.println(add1(1,2,3,4)); //10  可以传随意个数的整型
        System.out.println(add1(1,2,3,4,5,6));//21
        System.out.println(add1(new int[]{2,4,6})); //12  可以传数组
    }

    //形参是整数数组
    public static int add(int a[])
    {
        int result=0;
        for(int i=0;i<a.length;i++)
        {
            result+=a[i];
        }
        return result;
    }
    //形参是可变参数
    public  static int add1(int ... a)  //可变参数，本质上是整型数组
    {
        int result=0;
        for(int i=0;i<a.length;i++)
        {
            result+=a[i];
        }
        return result;
    }
    public  static void func(int data,String...str)
    {
        int[] a=new int[]{1,2,3};
        for(int val : a)  //只要在数组长度里，将数组a里元素赋给val
        {
            System.out.println(val);
        }
    }
}
