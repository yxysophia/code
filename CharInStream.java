package CODE.JavaIo;


import java.io.*;

//字符输入流
public class CharInStream {
    public static void main(String[] args) throws IOException {
        //取得File对象
        File file=new File("C:"+File.separator+"Users"+File.separator+
                "lenovo"+File.separator+"Desktop"+
                File.separator+"java"+File.separator+"IO.txt");
        //从文件读数据，必须保证文件存在
        if(file.exists())
        {
            //获取File对象的输入流
            Reader re=new FileReader(file);
            char[] cbuf=new char[1024]; //最大每次可以读取的最大数量
            int len=re.read(cbuf);  //将读取的数据存放到字符数组cbuf中，返回实际读取大小
            System.out.println(new String(cbuf,0,len)); //将字符数组转化成字符串，并且大小的实际读取大小
            re.close();//关闭流
        }
    }
}
