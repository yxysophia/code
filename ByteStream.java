package CODE.JavaIo;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;


//AutoCloseable自动关闭
class Message implements AutoCloseable
{
    @Override
   public void close()
   {
       System.out.println("AutoCloseable自动关闭");
   }
}
public class ByteStream {
    public static void main(String[] args) {
        try(Message message=new Message())  //必须在try中定义对象
        {
            //取得File对象
            File file=new File("C:"+File.separator+"Users"+File.separator+
                    "lenovo"+File.separator+"Desktop"+
                    File.separator+"java"+File.separator+"IO.txt");
            //文件输出时，如果文件不存在，会自动生成，但是必须保证父目录存在，如果父目录不存在，必须创建
            if(!file.getParentFile().exists())
            {
                System.out.println("父目录不存在");
                file.getParentFile().mkdirs();
            }
            //取得file对象的输出流
            OutputStream out=new FileOutputStream(file,true);  //追加式写入
            String msg="hello pick\r\n";
            //进行数据的写入
            out.write(msg.getBytes(),6,6); //将字符串转换成字节数组
            out.close();
        }catch (IOException e)
        {
            e.printStackTrace();
        }


    }
}


//部分内容写入
//public class ByteStream {
//    public static void main(String[] args) throws  IOException{
//        //取得File对象
//        File file=new File("C:"+File.separator+"Users"+File.separator+
//                "lenovo"+File.separator+"Desktop"+
//                File.separator+"java"+File.separator+"IO.txt");
//        //文件输出时，如果文件不存在，会自动生成，但是必须保证父目录存在，如果父目录不存在，必须创建
//        if(!file.getParentFile().exists())
//        {
//            System.out.println("父目录不存在");
//            file.getParentFile().mkdirs();
//        }
//        //取得file对象的输出流
//        OutputStream out=new FileOutputStream(file,true);  //追加式写入
//        String msg="hello pick\r\n";
//        //进行数据的写入
//        out.write(msg.getBytes(),6,6); //将字符串转换成字节数组
//        //关闭流
//        out.close();
//    }
//}


////追加式写入
//public class ByteStream {
//    public static void main(String[] args) throws  IOException{
//        //取得File对象
//        File file=new File("C:"+File.separator+"Users"+File.separator+
//                "lenovo"+File.separator+"Desktop"+
//                File.separator+"java"+File.separator+"IO.txt");
//        //文件输出时，如果文件不存在，会自动生成，但是必须保证父目录存在，如果父目录不存在，必须创建
//        if(!file.getParentFile().exists())
//        {
//            System.out.println("父目录不存在");
//            file.getParentFile().mkdirs();
//        }
//        //取得file对象的输出流
//        OutputStream out=new FileOutputStream(file,true);  //追加式写入
//        String msg="hello pick\r\n";
//        //进行数据的写入
//        out.write(msg.getBytes()); //将字符串转换成字节数组
//        //关闭流
//        out.close();
//    }
//}



//覆盖式写入
//public class ByteStream {
//    public static void main(String[] args) throws  IOException{
//        //取得File对象
//        File file=new File("C:"+File.separator+"Users"+File.separator+
//                "lenovo"+File.separator+"Desktop"+
//                File.separator+"java"+File.separator+"IO.txt");
//       //文件输出时，如果文件不存在，会自动生成，但是必须保证父目录存在，如果父目录不存在，必须创建
//        if(!file.getParentFile().exists())
//        {
//            System.out.println("父目录不存在");
//            file.getParentFile().mkdirs();
//        }
//        //取得file对象的输出流
//        OutputStream out=new FileOutputStream(file);  //覆盖式写入
//        String msg="hello pick";
//        //进行数据的写入
//        out.write(msg.getBytes()); //将字符串转换成字节数组
//        //关闭流
//        out.close();
//    }
//}
