package CODE.JavaIo;

import java.io.File;

//查看文件夹测试工具所有文件
public class File1 {
    public static void main(String[] args) {
        File file=new File("C:"+File.separator+"Users"+File.separator+
                "lenovo"+File.separator+"Desktop"+File.separator+"测试工具");
        ListAllFile(file);
    }
    public static void ListAllFile(File file)
    {
        //如果file是文件则打印
        if(file.isFile())
        {
            System.out.println(file);
            return ;
        }
        //现在是文件夹
        //files里存的是文件夹里内容，包括文件夹和文件
        File files[]=file.listFiles();
        if(files!=null)  //如果这个文件夹什么都没有，需要判断
        {
            for(File file1:files)
            {
                ListAllFile(file1);
            }
        }

    }
}


//查看文件夹测试工具内容
//public class File1 {
//    public static void main(String[] args) {
//        File file=new File("C:"+File.separator+"Users"+File.separator+
//                "lenovo"+File.separator+"Desktop"+File.separator+"测试工具");
//        if(file.exists()&&file.isDirectory())//是文件夹且存在
//        {
//            File files[]=file.listFiles();
//            for(File file2:files)
//            {
//                System.out.println(file2);
//            }
//        }
//    }
//}


///取得文件信息
//public class File1 {
//    public static void main(String[] args) {
//        File file=new File("C:"+File.separator+"Users"+File.separator+
//                "lenovo"+File.separator+"Desktop"+File.separator+"java"+
//                File.separator+"IO"+File.separator+"IO.txt");
//        if(file.exists()&&file.isFile())
//        {
//            System.out.println(file.length());  //取得文件大小 9字节
//            System.out.println(new Date(file.lastModified())); //2018-12-01
//        }
//    }
//}
