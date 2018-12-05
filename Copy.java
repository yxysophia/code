package CODE.JavaIo;

import java.io.*;

//一次拷一个字节
////拷贝图片
//public class Copy {
//    public static void main(String[] args) throws  Exception{
//        String sourceFilePath="C:"+File.separator+"Users"+File.separator+
//                "lenovo"+File.separator+"Desktop"+
//                File.separator+"pick.jpg";
//        String destFilePath="C:"+File.separator+"Users"+File.separator+
//                "lenovo"+File.separator+"Desktop"+
//                File.separator+"sophia.jpg";
//        copyFile(sourceFilePath,destFilePath);
//
//    }
//    public static boolean copyFile(String sourceFilePath,String destFilPath) throws Exception
//    {
//        //1.取得终端对象，终端是文件
//        File sourceFile=new File(sourceFilePath);
//        File destFile=new File(destFilPath);
//        if(!sourceFile.getParentFile().exists())
//        {
//            System.out.println("源文件父目录不存在");
//            sourceFile.getParentFile().mkdirs();
//            return false;
//        }
//        if(!sourceFile.exists())
//        {
//            System.out.println("拷贝源文件不存在");
//            return false;
//        }
//        if(!destFile.getParentFile().exists())
//        {
//            System.out.println("目标文件父目录不存在");
//            destFile.getParentFile().mkdirs();
//            return false;
//        }
//        //现在具备拷贝条件
//        //2.取得文件的输入输出流
//        InputStream in=new FileInputStream(sourceFile); //从源文件读取数据
//        OutputStream out=new FileOutputStream(destFile); //目标文件是写入数据
//
//        //3.读取或写入数据
//        long start=System.currentTimeMillis();
//        int len=0;
//        while((len=in.read())!=-1) //in.read()是一次读取一个字节，返回的是读取的一个字节数据，当返回-1读取完毕
//        {
//            out.write(len); //将读取到1字节数据写入目标文件
//        }
//        long end=System.currentTimeMillis();
//        System.out.println("拷贝耗时："+(end-start)+"毫秒"); //1642毫秒
//        //关闭流
//        in.close();
//        out.close();
//        return true;
//    }
//}

//利用缓冲区，


//拷贝图片
public class Copy {
    public static void main(String[] args) throws  Exception{
        String sourceFilePath="C:"+File.separator+"Users"+File.separator+
                "lenovo"+File.separator+"Desktop"+
                File.separator+"pick.jpg";
        String destFilePath="C:"+File.separator+"Users"+File.separator+
                "lenovo"+File.separator+"Desktop"+
                File.separator+"sophia.jpg";
        copyFile(sourceFilePath,destFilePath);

    }
    public static boolean copyFile(String sourceFilePath,String destFilPath) throws Exception
    {
        //1.取得终端对象，终端是文件
        File sourceFile=new File(sourceFilePath);
        File destFile=new File(destFilPath);
        if(!sourceFile.getParentFile().exists())
        {
            System.out.println("源文件父目录不存在");
            sourceFile.getParentFile().mkdirs();
            return false;
        }
        if(!sourceFile.exists())
        {
            System.out.println("拷贝源文件不存在");
            return false;
        }
        if(!destFile.getParentFile().exists())
        {
            System.out.println("目标文件父目录不存在");
            destFile.getParentFile().mkdirs();
            return false;
        }
        //现在具备拷贝条件
        //2.取得文件的输入输出流
        InputStream in=new FileInputStream(sourceFile); //从源文件读取数据
        OutputStream out=new FileOutputStream(destFile); //目标文件是写入数据

        //3.读取或写入数据
        long start=System.currentTimeMillis();
        int len=0;

        byte[] data=new byte[1024]; //缓冲区为1024字节
        while((len=in.read(data))!=-1) //in.read(data)将读取的数据放入data数组，返回的是实际读取字节数，当返回-1，读取完毕
        {
            out.write(data); //将data数组内容写入
        }

        long end=System.currentTimeMillis();
        System.out.println("拷贝耗时："+(end-start)+"毫秒"); //16毫秒
        //关闭流
        in.close();
        out.close();
        return true;
    }
}

