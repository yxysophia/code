package CODE.java考试;


////10个人抱圈，从第一个人开始报数，如果报到3，次人出局，然后继续从1开始报数，直至圈里只有一个人
public class cycl
{
    public static void main(String[] args)
    {
        System.out.println(leftNum()); //留在场上的人的序号
    }
    public static int leftNum()
    {
        //场上的10个人从1开始排序，返回留在场上的序号
        int[] people={1,1,1,1,1,1,1,1,1,1};
        int leftnum=10; //一开始，留在场上有10个人
        int i=0;
        int flag=1;
        while(leftnum>1)
        {
            if(flag==3&&people[i]==1)
            {
                people[i]=0;  //报到3后，将这个位置置0
                flag=1;
                leftnum--;
            }
            else if(people[i]==1)
                flag++;
            if(i==9)
                i=0;
            else
                i++;
        }
        for(int j=0;j<10;j++)
        {
            if(people[j]==1)
                return j+1;
        }
        return -1;
    }
}
