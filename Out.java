package CODE.JavaIo;

import java.io.*;

//System对IO的支持
//public class Out {
//    public static void main(String[] args) throws IOException {
//        OutputStream out=System.out;  //System.out是PrintStream对象
//        String str="hello pick";
//        out.write(str.getBytes());  //会在显示器终端显示
//    }
//}


////out和err区别
public class Out {
    public static void main(String[] args)  {
        OutputStream out=System.out;  //System.out是PrintStream对象
        File file =new File("Text.txt");
        try {
            InputStream in=new FileInputStream(file);
        } catch (FileNotFoundException e) {
            System.out.println(e);
            System.err.println(e);
        }
    }
}

