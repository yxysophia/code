package CODE.java考试;

////快乐数
/////方法1  如果num=1，结束循环是快乐数，如果无限循环，则不是快乐数，但是无限循环，出现的num会重复
////比如判断数字20是否为快乐数，num变化：20 4 16 37 58 89 145 42 20，到这里，20出现2次，那么就又会循环之前的操作，
///所以可以将num存在一个数组里，num再次出现，那么这个数肯定不是快乐数。
//public class happy
//{
//    public static void main(String[] args)
//    {
//        System.out.println(isHappy(20));
//    }
//    public static boolean isHappy(int num)
//    {
//        int[] a=new int[20]; //将下一个数据存在数组里，长度为20足够
//        int i=0;
//        a[i]=num;
//        i++;
//        int flag=num;
//        while(num!=1)
//        {
//            flag=getNext(num);
//            System.out.println(flag);
//            for(int j=0;j<20;j++)
//            {
//                if(flag==a[j])  //出现过，即无限循环则直接return
//                   return false;
//            }
//            a[i]=flag;
//            i++;
//            num=flag;
//        }
//        return true;
//    }
//    public static int getNext(int num)
//    {
//        int result=0;
//        while(num>0)
//        {
//            result=result+(num%10)*(num%10);
//            num=num/10;
//        }
//        return result;
//    }
//}



////方法2：找规律
//20: 4 16 37 58 89 145 42 20....
//11: 2 4 16 37 58 89 145 42 20 4...
//121：6 36 45 41 17 50 25 29 85 89 145 42 20...
////从上面3个数据，可以发现一个数据不是快乐数，num在变化过程中肯定会出现一个数字89，
//所以只要num出现89，就直接返回false
public class happy
{
    public static void main(String[] args)
    {
        System.out.println(isHappy(11));
    }
    public static boolean isHappy(int num)
    {

        while(num!=1)
        {
            num=getNext(num);
            if(num==89)
                return false;
        }
        return true;
    }
    public static int getNext(int num)
    {
        int result=0;
        while(num>0)
        {
            result=result+(num%10)*(num%10);
            num=num/10;
        }
        return result;
    }
}

