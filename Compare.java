////////字符串比较

public class Compare
{
    public static void main(String[] args)
    {
        String str1="hEllo";
        String str2="hellO";
        System.out.println(str1.equals(str2));  //false  区分大小写
        System.out.println((str1.equalsIgnoreCase(str2)));  // true 不区分大小写
        System.out.println(str1.compareTo(str2)); //-32 因为str2的E小于str2的e,小了32，
        //如果比较到两个字符串有不相等字符的，就返回，不会再判断后面字符大小
    }
}

///字符串查找
public class Compare
{
    public static void main(String[] args)
    {
       String str1="hello world abcd world";
       System.out.println(str1.contains("abc")); //true
       System.out.println(str1.startsWith("world")); //false 不是以world开头
       System.out.println(str1.startsWith("world",6)); //true 从指定位置下标为6判断是否以world开头

       System.out.println(str1.indexOf("world")); //返回world第一次出现的位置 6
       System.out.println(str1.indexOf("world",8));  // 17 从下标为8开始判断world第一次出现的位置

       System.out.println(str1.lastIndexOf("world"));  // 17  //从后向前返回子串地再一次出现位置
       //从指定位置从后向前返回子串第一次出现位置
       System.out.println(str1.lastIndexOf("world",str1.length()-6)); // 6 向前判断str1.length()-6是空格 不符合标准就继续向前判断
       System.out.println(str1.lastIndexOf("world",str1.length()-5)); // 17  str1.lenght()-5是最后一个w位置,判断是world

       System.out.println(str1.endsWith("cd")); //false 判断是否以cd结尾  
       
    }
}

////字符串替换
public class Compare
{
    public static void main(String[] args)
    {
        String str="hello world hello";
        System.out.println(str.replaceAll("hello","hai"));  //hai world hai  将所有hello替换为hai
        System.out.println(str.replaceFirst("hello","hai")); //hai world hello 将第一个hello替换为hai 
    }
}

///字符串拆分
public class Compare
{
    public static void main(String[] args)
    {
        //全部拆分
       String str1="hello world,happy day";
       String[] result1=str1.split(" "); // 按空格拆分放到字符串数组中
       for(String num :result1)
       {
           System.out.print(num+"、"); //hello、world,happy、day、拆分成了3个元素
       }

        //部分拆分
       String[] result2 =str1.split(" ",2);
       for(String num :result2)
       {
           System.out.print(num+"、"); //hello、world,happy day、拆分成了2个元素
       }

        //拆分格式需要转义
        String ip="192.168.2.2";  //IP地址
        String[] result3=ip.split("\\.");  //如果发现拆分结果不是期望的，那就是拆分格式有误，可能需要转义
        for(String num : result3)
        {
            //System.out.print(num+"、"); // 192、168、2、2、
        }

        //多次拆分
        String info="jing 10 |ting 15";
        String[] result4=info.split("\\|");
        for(int i=0;i<result4.length;i++)
        {
            String[] result5=result4[i].split(" ");
            System.out.println(result5[0]+"是"+result5[1]+"岁"); //jing是10岁  ting是15岁
        }
    }
}

///字符串截取

public class Compare
{
    public static void main(String[] args)
    {
        String str="hello world hai day";
        System.out.println(str.substring(6));//world hai day
        System.out.println(str.substring(0,5)); //hello  左闭右开 
    }
}

///判断字符串是否为空
public class Compare
{
    public static void main(String[] args)
    {
        //去左右空格，大小写转换
        String str="  Hello 中国  ";
        System.out.println(str.trim()); //"Hello 中国"   只会去掉左右空格
        System.out.println(str.toUpperCase());  //  "  HELLO 中国  "  字母全部转大写，但是对汉字无影响
        System.out.println(str.toLowerCase());  //  "  heLLO 中国  "  字母全部转小写，但是对字母无影响

        //判空
        String str2="";
        System.out.println(str2.isEmpty()); 
        String str1=null;   
        //System.out.println(str1.empty());   如果直接这样判断会报错，但是str1确实是空的
        //所以对String类字符串判空推荐如下：
        if(str1==null||str1.isEmpty())
        {
            System.out.println("str1是空串");
        } 
    }
}

///首字母大写
public class Compare
{
    public static String firstUpper(String str)
    {
        if(str==null|| str.isEmpty())  //需要判断是否为空
            return null;
        return str.substring(0,1).toUpperCase()+str.substring(1);
    }
    public static void main(String[] args)
    {
        System.out.println(firstUpper("")); //null
        System.out.println(firstUpper(null));//null
        System.out.println(firstUpper("hello world")); //Hello world
        System.out.println(firstUpper("a")); //A
    }
}

