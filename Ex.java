package Work.Exception;

class MuilException extends Exception
{
    public  MuilException(String str)
    {
        super(str);
    }
}
class DivException extends RuntimeException
{
    public DivException(String str)
    {
        super(str);
    }
}
public class Ex
{
    public static void main(String[] args)
    {
        try
        {
            System.out.println(muil(4,10));
        }
        catch (MuilException e) {
            e.printStackTrace();
        }
        System.out.println(div(4,2));

}
    public static int muil(int a,int b) throws MuilException   //受查异常必须处理异常
    {
        int ret=a*b;
        if(ret==100)
            throw new MuilException("两数相乘等于100");
        return ret;
    }
    public static int div(int a,int b)  //非受查异常可以不处理异常
    {
        int ret=a/b;
        if(ret==2)
            throw new DivException("两数相除等于2");
        return ret;
    }
}
