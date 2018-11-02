package CODE;


/////////throws
public class Throw1
{
    public static void main(String[] args)
    {
        //主方法中调用用throws声明的方法，必须进行异常处理
        try
        {
            calu(10,0);
        }
        catch (Exception e)  //处理异常
        {
            e.printStackTrace();
        }
        System.out.println("********");  //会打印
    }
    public  static  int calu(int a,int b) throws Exception  //将异常抛给调用处
    {
        int result= a/b;
        System.out.println("#####"); //产生异常后，异常后面的语句不再执行
        return result;
    }
}

//////主方法抛异常
public class Throw1
{
    public static void main(String[] args) throws Exception  //将异常抛给JVM
    {
        calu(10,0);
        System.out.println("********");  //不会打印
    }
    public  static  int calu(int a,int b) throws Exception  //将异常抛给调用处
    {
        int result= a/b;
        System.out.println("#####"); //产生异常后，异常后面的语句不再执行
        return result;
    }
}

///////数值转换异常
public class Throw1
{
    public static void main(String[] args) throws Exception  //将异常抛给JVM
    {
      String str="123abc";
      Integer a=Integer.parseInt(str);
      //字符串中如果含有字母转化成整型会有数值转化异常
    }

}

/////throw
class MyException extends Exception
{
      public MyException(String str)
      {
          super(str);
      }
}
public class Throw1
{
    public static void main(String[] args) throws Exception  //将异常抛给JVM
    {
        try
        {
            int num=300;
            if(num>200)
              throw new MyException("微信红包至多200元");
        }
        catch (MyException e)
        {
            e.printStackTrace();
        }
    }
}

//1. 在进行除法计算操作之前打印一行语句"******".
// 2.如果在除法计算过程中出现错误，则应该将异常返回给调用处。
// 3. 不管最终是否有异常产生，都要求打印一行计算结果信息。
public class Throw1
{
    public static void main(String[] args)
    {
        try
        {
            System.out.println(cual(10,0));
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
    public static int cual(int a,int b)
    {
        int result=0;
        System.out.println("******");
        try {
            result=a/b;
        }catch (Exception e)
        {
            throw  e;
        }finally {
            System.out.println(result);
        }
        return result;
    }
}


public class Throw1
{
    public static void main(String[] args)
    {
        try
        {
            System.out.println(cual(10,0));
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
    public static int cual(int a,int b) throws Exception
    {
        int result=0;
        System.out.println("******");
        try {
            result=a/b;
        }finally {
            System.out.println(result);
        }
        return result;
  }
}


///assert
public class Throw1
{
    public static void main(String[] args)
    {
        int num=10;
        assert num==55 :"num应该为55";
        System.out.println(num);
    }
}

