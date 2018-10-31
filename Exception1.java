package CODE;

////try ...catch处理异常
public class Exception
{
    public static void main(String[] args)
    {
         System.out.println("1.计算前....");
         try  //try里放可能出现异常的语句
         {
             System.out.println("2.计算式及结果："+20/0);
         }
         catch(ArithmeticException e) //异常类 异常对象
         {
             //System.out.println("分母不能为0");  //出现异常解决方案，告诉用户分母不能为0
             e.printStackTrace();
         }
         System.out.println("3.计算完毕");
    }
}


/////finally是异常出口，一定会执行finally代码块
public class Exception
{
    public static int div(int a,int b)
    {
        System.out.println("1.计算前....");
        try  //try里放可能出现异常的语句
        {
            System.out.println("2.计算式及结果："+20/4);
            return 1;

        }
        catch(ArithmeticException e) //异常类 异常对象
        {
            e.printStackTrace();
            return 2;
        }
        finally
        {
            System.out.println("4.finally代码块");
            //return 3;
        }
    }

    public static void main(String[] args)
    {

        System.out.println("返回值"+div(10,0)); //返回值是3，也就是说一定会走finally代码块
    }
}


//public class Exception
{
    public static void main(String[] args)
    {
        System.out.println("1.计算前....");
        try  //try里放可能出现异常的语句
        {
            int a=Integer.parseInt(args[0]); //将字符串转为整型
            int b=Integer.parseInt(args[1]); //如果字符串中含有字母将会有异常
            System.out.println("2.计算式及结果：" + a/b);
        }
        catch(ArithmeticException e)   //分母为0
        {
            e.printStackTrace();
        }
        catch (NumberFormatException e) // 输入不是数字
        {
            e.printStackTrace();
        }
        catch (ArrayIndexOutOfBoundsException e)  //没有命令行参数
        {
            e.printStackTrace();
        }
        System.out.println("3.计算完毕");
    }
}

///////catch中直接用父类
public class Exception1
{
    public static void main(String[] args)
    {
        System.out.println("1.计算前....");
        try  //try里放可能出现异常的语句
        {
            int a=Integer.parseInt(args[0]); //将字符串转为整型
            int b=Integer.parseInt(args[1]); //如果字符串中含有字母将会有异常
            System.out.println("2.计算式及结果：" + a/b);
        }
        catch(Exception e)   //分母为0
        {
            e.printStackTrace();
        }

        System.out.println("3.计算完毕");
    }
}
