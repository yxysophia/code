import java.io.*;

//深拷贝
class Teacher1 implements Serializable {
    private String name;
    private String position;

    public Teacher1(String name, String position) {
        this.name = name;
        this.position = position;
    }

    @Override
    public String toString() {
        return "QianCopy{" +
                "name='" + name + '\'' +
                ", position='" + position + '\'' +
                '}';
    }

    public void setName(String name) {
        this.name = name;
    }
}

class Student1 implements  Cloneable,Serializable
{
    private String name;
    private Integer age;
    private Teacher1 teacher;

    public Student1(String name, Integer age, Teacher1 teacher) {
        this.name = name;
        this.age = age;
        this.teacher = teacher;
    }

    public Student1 cloneSer () throws Exception {
        Student1 student=null;
        //在内存中创建一个字节数组缓冲区，所有发送到输出流的数据保存在该字节数组中
        //默认创建一个大小为32的缓冲区
        ByteArrayOutputStream byOut=new ByteArrayOutputStream();
        //对象的序列化输出
        ObjectOutputStream outputStream=new ObjectOutputStream(byOut);//通过字节数组的方式进行传输
        outputStream.writeObject(this);  //将当前student对象写入字节数组中

        //在内存中创建一个字节数组缓冲区，从输入流读取的数据保存在该字节数组缓冲区
        ByteArrayInputStream byIn=new ByteArrayInputStream(byOut.toByteArray()); //接收字节数组作为参数进行创建
        ObjectInputStream inputStream=new ObjectInputStream(byIn);
        student=(Student1)inputStream.readObject(); //从字节数组中读取
        return student;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", teacher=" + teacher +
                '}';
    }
}
public class ShenCopy {
    public static void main(String[] args) throws Exception {
        Teacher1 teacher=new Teacher1("ali","manager");
        Student1 student=new Student1("sophia",10,teacher);
        System.out.println("这是原student");
        System.out.println(student);
        System.out.println("这时cloneStudent");
        Student1 cloneStudent=student.cloneSer();
        System.out.println(cloneStudent);

        System.out.println("将teacher姓名进行修改");
        teacher.setName("Jack");
        System.out.println("这是修改后原student");
        System.out.println(student);
        System.out.println("这是修改后cloneStudent");
        System.out.println(cloneStudent);
    }
}
