package CODE.JavaIo;


import java.io.File;
import java.io.IOException;

//创建目录
public class Create {
    public static void main(String[] args) {
        File file=new File("C:"+File.separator+"Users"+File.separator+
                "lenovo"+File.separator+"Desktop"+File.separator+"java"+
                File.separator+"IO"+File.separator+"IO.txt");
        if(!file.getParentFile().exists())
        {
            file.getParentFile().mkdirs(); //有多少目录，就创建多少父目录
        }
        else
        {
            System.out.println("父路径:"+file.getParent()+" 父文件:"+file.getParentFile());
            if(!file.exists())  //如果IO.txt不存在，即创建该文件
            {
                try {
                    file.createNewFile();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            else
            {
                System.out.println("文件已存在");
            }
        }
    }
}



//文件的创建、判断是否存在、删除文件
//public class Create {
//    public static void main(String[] args) {
//        //定义要操作的文件路径
//        //File file=new File("C:\\Users\\lenovo\\Desktop\\IO.txt");
//        File file=new File("C:"+File.separator+"Users"+File.separator+
//                "lenovo"+File.separator+"Desktop"+File.separator+"IO.txt");
//        System.out.println(file); //C:\Users\lenovo\Desktop\IO.txt
//        //判断文件是否存在，不存在则创建，存在则删除
//        if(!file.exists())
//        {
//            System.out.println("文件不存在");
//            try {
//                file.createNewFile();
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//        }
//        else
//            file.delete();
//    }
//}
//
