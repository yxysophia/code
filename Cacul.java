package Work.Interface;

interface Compute
{
    int compute(int m,int n);
}
class AddImpl implements Compute
{
    public int compute(int n,int m)
    {
        return n+m;
    }
}
class SubImpl implements Compute
{
    public int compute(int n,int m)
    {
        return n-m;
    }
}
class Muti implements  Compute
{
    public int compute(int n,int m)
    {
        return n*m;
    }
}
class Div implements Compute
{
    public int compute(int n,int m)
    {
        if(m==0)
        {
            System.out.println("分母不能为0");
            System.exit(0);
        }
        return n/m;
    }
}
class UseCompute
{
    private Compute com;
    public void useCom(Compute com, int one, int two)
    {
        this.com=com;
        System.out.println(com.compute(one,two));
    }
}
public class Cacul
{
    public static void main(String[] args)
    {
        UseCompute use=new UseCompute();
        use.useCom(new AddImpl(),10,2);
        use.useCom(new SubImpl(),10,2);
        use.useCom(new Muti(),10,2);
        use.useCom(new Div(),10,0);
    }


}
