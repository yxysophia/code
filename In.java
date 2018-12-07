package CODE.JavaIo;


////System对输入的支持：

import com.sun.corba.se.impl.orbutil.concurrent.Sync;

import java.io.*;
import java.util.Scanner;

//public class In {
//    public static void main(String[] args) throws IOException {
//        InputStream in=System.in;
//        System.out.println("请输入...");
//        byte[] data=new byte[1024];
//        int len=in.read(data);
//        System.out.println(new String(data,0,len));
//        in.close();
//    }
//}

//public class In {
//    public static void main(String[] args) throws IOException {
//        System.out.println("请输入...");
//        InputStream in=System.in;  //标准输入
//        ByteArrayOutputStream out =new ByteArrayOutputStream(); //内存字节输出流
//        byte data[]=new byte[10];
//        int len=0;
//        while((len=in.read(data))!=-1)
//        {
//            out.write(data,0,len); //将data里数写入内存保存
//            //需要判断用户输入完毕
//            if (len < data.length)
//                break ;
//        }
//        System.out.println(new String(out.toByteArray()));
//        in.close();
//        out.close();
//    }
//}

//////Scanner类的输入
//public class In {
//    public static void main(String[] args) throws IOException {
//        Scanner scanner=new Scanner(System.in);  //标准输入
//        System.out.println("请输入...");
//        if(scanner.hasNext())
//        {
//            System.out.println("输入内容："+scanner.next());
//        }
//        scanner.close();
//    }
//}

////Scanner类接受指定类型
//public class In {
//    public static void main(String[] args) throws IOException {
//        Scanner scanner=new Scanner(System.in);  //标准输入
//        System.out.println("请输入...");
//        if(scanner.hasNextDouble()) //有输入，并且输入的数据是double
//        {
//            System.out.println("输入double型数据："+scanner.nextDouble());
//        }
//        scanner.close();
//    }
//}

////正则表达式
//public class In {
//    public static void main(String[] args) throws IOException {
//        Scanner scanner=new Scanner(System.in);  //标准输入
//        System.out.println("请输入...");
//        if(scanner.hasNext("\\d{4}-\\d{2}-\\d{2}")) //有输入，并且输入的数据是double
//        {
//            String birthday=scanner.next();
//            System.out.println("输入的生日为："+birthday);
//        }
//        else
//        {
//            System.out.println("输入生日格式错误");
//        }
//        scanner.close();
//    }
//}

//Scanner接受文件输入流
public class In {
    public static void main(String[] args) throws IOException {
        File file=new File("C:"+File.separator+"Users"+File.separator+
                "lenovo"+File.separator+"Desktop"+
                File.separator+"Test.txt");
        InputStream in=new FileInputStream(file);
        Scanner scanner=new Scanner(file);
        scanner.useDelimiter("\n");  //按照"\n"分隔
        while(scanner.hasNext())
        {
            System.out.println(scanner.next());
        }
        in.close();
        scanner.close();
    }
}