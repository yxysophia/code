public class Int
{
    int value;
    public  static void main(String[] args)
    {
        //默认值
        Int i1=new Int();  //需要结合类来看
        System.out.println(i1.value);  //0 

        //int 的包装类是Integer
        int maxValue=Integer.MAX_VALUE+1;//整型最大值+1，会溢出
        int minValue=Integer.MIN_VALUE-1; //整型最小值-1，会溢出

        int maxValue=Integer.MAX_VALUE;
        int minValue=Integer.MIN_VALUE; 
        long max=maxValue+1;
        long min=minValue-1;
        //结果依然是溢出，是因为执行顺序是从右向左，右边是int类型相加，
        //这时已经溢出，那么max里存的就是溢出值。
        
        //解决方法：
        long maxValue=Integer.MAX_VALUE+1L;  //int 和long相加，int会自动提升成long
        long minValue=(long)(Integer.MIN_VALUE-1);  //强转为long
        System.out.println(maxValue);
        System.out.println(minValue);

        //int 和byte

        //整型常量在byte范围内
        byte a=120;  //byte取值范围是 -128-127
        System.out.println(a);  //120

        //整型常量不在byte范围内--》需要强转
        //byte b=130;// 错误(从int转换到byte可能会有损失)
        byte  b=(byte)130;  //强转为byte
        System.out.println(b); //-126 
        byte  c=(byte)300;
        System.out.println(c); // 44  取的是300的低吧8位即44

        //整型变量--》需要强转
        int num=12;
        //byte d=num;  //错误(从int转换到byte可能会有损失)
        byte d=(byte)num;
        System.out.println(d); //12

      
    }

}