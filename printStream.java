package CODE.JavaIo;


import java.io.*;

//设计一个简单的打印流
class PrintUtil
{
    private OutputStream out;
    //类外部传入输出流
    public PrintUtil(OutputStream out)
    {
        this.out=out;
    }
    //核心方法
    public void print(String str)
    {
        try {
            out.write(str.getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void println(String str)
    {
        print(str+"\r\n");
    }
    public void print(int n)
    {
        print(String.valueOf(n));
    }
    public void println(int n)
    {
        println(String.valueOf(n));
    }
    public void print(double d)
    {
        print(String.valueOf(d));
    }
    public void println(double d)
    {
        println(String.valueOf(d));
    }
    public void close()
    {
        try {
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
//public class printStream {
//    public static void main(String[] args) throws Exception {
//        File file=new File("C:"+File.separator+"Users"+
//                File.separator+ "lenovo"+File.separator+"Desktop"+
//                File.separator+"Test.txt");
//        OutputStream out=new FileOutputStream(file);
//        PrintUtil printUtil=new PrintUtil(out);
//        printUtil.print("姓名:");
//        printUtil.println("pick");
//        printUtil.print("年龄");
//        printUtil.println(18);
//        printUtil.close();
//    }
//}

//////系统提供的字节打印流
//public class printStream {
//    public static void main(String[] args) throws Exception {
//        File file=new File("C:"+File.separator+"Users"+
//                File.separator+ "lenovo"+File.separator+"Desktop"+
//                File.separator+"Test.txt");
//        OutputStream out=new FileOutputStream(file);
//        PrintStream printUtil=new PrintStream(out);
//        printUtil.print("姓名:");
//        printUtil.println("pick");
//        printUtil.print("年龄");
//        printUtil.println(18);
//        printUtil.close();
//    }
//}

////格式化输出

//////系统提供的字节打印流
//public class printStream {
//    public static void main(String[] args) throws Exception {
//        File file=new File("C:"+File.separator+"Users"+
//                File.separator+ "lenovo"+File.separator+"Desktop"+
//                File.separator+"Test.txt");
//        OutputStream out=new FileOutputStream(file);
//        PrintStream printUtil=new PrintStream(out);
//        printUtil.printf("姓名：%s 年龄：%d","pick",18);
//    }
//}

////String的格式化输出
public class printStream {
    public static void main(String[] args) throws Exception {
       String str=String.format("姓名：%s 年龄:%d","pick",18);
        System.out.println(str);
    }
}
