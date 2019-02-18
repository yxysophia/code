import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.PrintStream;

//内部流
//字节内存流  ByteArrayInputStream ByteArrayOutputStream
//字节内存流  CharArrayReader      CharArrayWriter
public class TestArrayReader {
    public static void main(String[] args) {
        String msg="hello day";
        ByteArrayInputStream bI=new ByteArrayInputStream(msg.getBytes());  //向内存流输入的数据
        ByteArrayOutputStream bO=new ByteArrayOutputStream(); //输出到内存
        PrintStream printStream=new PrintStream(bO);
        int len=0;
        while((len=bI.read())!=-1)
        {
            bO.write(Character.toUpperCase(len));
        }

        //直接将内存输出流输出
        System.out.println(bO);
        try {
            bI.close();
            bO.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
