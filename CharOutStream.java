package CODE.JavaIo;


import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

//字符输出流
public class CharOutStream {
    public static void main(String[] args) throws IOException {
        //取得File对象
        File file=new File("C:"+File.separator+"Users"+File.separator+
                "lenovo"+File.separator+"Desktop"+
                File.separator+"java"+File.separator+"IO.txt");
        //必须保证父目录存在
        if(!file.getParentFile().exists())
        {
            file.getParentFile().mkdirs();
        }
        //取得File对象的输出流
        //覆盖式写入
        //Writer wr=new FileWriter(file);
        //追加式写入
        Writer wr=new FileWriter(file,true);
        wr.write("哈喽 pick\r\n");
        //清除缓冲区，如果没有wr.close,需要清除缓冲区，才能将内容输出到文档IO.txt中
        wr.flush();

    }
}
