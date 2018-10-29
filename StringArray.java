/////字符数组与字符串的相互转化

public class StringArray
{
    public static void main(String[] args)
    {
        //将字符数组转为字符串
        char[] ch1=new char[]{'a','b','c','d','e','f','g'};
        String str1=new String(ch1);
        String str2=new String(ch1,1,3);  //从下标1开始数3个字符变为字符串
        System.out.println(str1); //abcdefg
        System.out.println(str2); //bcd

        //取得字符串中一个字符
        char ch=str1.charAt(3); //取得下标为3的字符
        System.out.println(ch);  //d

        //将字符串转为字符数组
        char[] ch2=str1.toCharArray();
        for(char num: ch2)
        {
            System.out.print(num+"、");  //a、b、c、d、e、f、g、
        }
    }
}

//////面试题：判断一个字符串是否全由数字组成

public class StringArray
{
    public boolean isChar(String str)
    {
        char[] ch=str.toCharArray();  //转为字符数组
        for(int i=0;i<ch.length;i++)
        {
            if(ch[i]<'0'||ch[i]>'9')
            {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args)
    {
       String str=new String("1234abc");
       StringArray strArray=new StringArray();
       if(strArray.isChar(str))
       {
           System.out.println("str是由数字组成");
       }
       else
       {
           System.out.println("str不是由数字组成");
       }
    }
}