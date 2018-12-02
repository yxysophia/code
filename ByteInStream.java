package CODE.JavaIo;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class ByteInStream {
    public static void main(String[] args) throws IOException {
        //取得File对象
        File file=new File("C:"+File.separator+"Users"+File.separator+
                "lenovo"+File.separator+"Desktop"+
                File.separator+"java"+File.separator+"IO.txt");
        //从文件读数据，必须保证文件存在而且是文件即不能是文件夹
        if(file.exists()&&file.isFile()) {
            //取得file对象的输入流
            InputStream in = new FileInputStream(file);
            byte[] b = new byte[1024]; //每次可以读取的最大数量
            int len=in.read(b);  //将读取的数据放在字节数组b中，返回实际读取数据大小
            System.out.println(new String(b,0,len)); //将字节数组b转换成String,并且长度是实际读取数据大小
            in.close(); //关闭流
        }
    }
}
