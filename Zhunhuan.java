package CODE.IO;


import java.io.*;
//将字节流转换为字符流
public class Zhunhuan {
    //取得终端对象:这里的终端是文件
    public static void main(String[] args)  throws Exception{
        File file=new File("C:"+File.separator+"Users"+
                File.separator+ "lenovo"+File.separator+"Desktop"+
                File.separator+"Test.txt");
        //取得终端输出流
        OutputStream out=new FileOutputStream(file);
        OutputStreamWriter wr=new OutputStreamWriter(out); //将字节输出流转换为字符输出流
        wr.write("hello pick"); //字符输入流的字符串写入
        wr.close(); //关闭流
    }
}
