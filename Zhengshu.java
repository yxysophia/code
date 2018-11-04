package Work.Interface;

public class Zhengshu
{
    public static boolean isYinShu(int num)
    {
        int[] a=new int[1000];
        int j=0;
        for(int i=1;i<=num/2;i++)
        {
            if(num%i==0)
            {
                a[j]=i;
                j++;
            }
        }
        int sum=0;
        for(int i=0;i<j;i++)
        {
            sum+=a[i];
        }
        if(num==sum)
            return true;
        else
            return false;
    }

    public static void main(String[] args)
    {
        for(int i=1;i<1000;i++)
        {
            if(isYinShu((i)))
            {
                System.out.print(i+"、");  //6  28  496
            }
        }
    }
}
