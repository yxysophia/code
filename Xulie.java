package CODE.JavaIo;


import java.io.*;


//实现Serializable接口 ，具有序列化功能
class Student implements Serializable
{
    private String name;  //姓名
    private transient int sno;   //学号将不会被序列化保存

    public Student(String name, int sno) {
        this.name = name;
        this.sno = sno;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", sno='" + sno + '\'' +
                '}';
    }
}
//public class Xulie {
//    public static void main(String[] args) throws Exception {
//        //1.取得终端对象
//        File file=new File("C:"+File.separator+"Users"+File.separator+
//                "lenovo"+File.separator+"Desktop"+
//                File.separator+"Test.txt");
//        //2.取得对象的输出流，对象序列化
//        Student s=new Student("pick",24);
//        ObjectOutputStream oos=new ObjectOutputStream(new FileOutputStream(file));
//        //3.对象的写入
//        oos.writeObject(s);
//        //4.关闭流
//        oos.close();
//    }
//}

public class Xulie {
    public static void main(String[] args) throws Exception {
        //1.取得终端对象
        File file=new File("C:"+File.separator+"Users"+File.separator+
                "lenovo"+File.separator+"Desktop"+
                File.separator+"Test.txt");
        //2.对象的输入流，对象反序列化
        ObjectInputStream ois=new ObjectInputStream(new FileInputStream(file));

        //3.对象反序列化输入
        Object obj=ois.readObject(); //Student向上转型
        System.out.println(obj); //Student{name='pick', sno='0'}
        //4.关闭流
        ois.close();

    }
}
