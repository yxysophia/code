package CODE.JavaIo;

import java.io.*;

public class Mem {
    public static void main(String[] args) throws IOException {
        String str="hello pick";
        //输入输出流：
        ByteArrayInputStream in=new ByteArrayInputStream(str.getBytes());//输入流，要输入的数据保存到内存中
        ByteArrayOutputStream out =new ByteArrayOutputStream();  //输出流

        //输入输出数据
        int len=0;
        //一次读取一个字节，将读取到的数据大写然后写入内存
        while((len=in.read())!=-1)
        {
            out.write(Character.toUpperCase(len));
        }
        System.out.println(out); //HELLO PICK
        out.close();
        in.close();
    }
}

