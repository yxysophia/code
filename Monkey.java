package Work.Exception;

////猴子吃桃递归
public class Monkey
{
    public static void main(String[] args)
    {
        System.out.println(peachNum(1));
    }
    public static int peachNum(int day)
    {
        if(day==10)
            return 1;
        return (peachNum(day+1)+1)*2;
    }
}

////猴子吃桃非递归
public class Monkey
{
    public static void main(String[] args)
    {
        int peach=1;
        for(int day=9;day>0;day--)
        {
            peach=(peach+1)*2;
        }
        System.out.println(peach);
    }
}
