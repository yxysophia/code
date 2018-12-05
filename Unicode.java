package CODE.JavaIo;


import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;

//乱码
public class Unicode {
    public static void main(String[] args) throws  Exception{
        //System.getProperties().list(System.out); //当前操作系统的默认编码格式：UTF-8
        File file=new File("C:"+File.separator+"Users"+
                File.separator+ "lenovo"+File.separator+"Desktop"+
                File.separator+"Test.txt");
        OutputStream out=new FileOutputStream(file);
        String str="哈喽 pick";
        out.write(str.getBytes("ISO8859-1"));
        //以ISO--8859-1格式写入，但是操作系统默认解码是UTF-8，会出现乱码
        out.close();
    }
}
