package CODE.Java新特性;

/////注解


class Student
{
    @Override
    public String toString()  //希望覆写toString,但是并没有报错
    {
        return "学生好好学习";
    }
}
public class Annotation
{
    public static void main(String[] args)
    {
        Student s=new Student();
        System.out.println(s); //CODE.Java新特性.Student@4554617c  输出的对象地址，并美有覆写成功
    }
}

////@Deprecated
class Student
{
    private String name;
    @Deprecated
    public Student() //声明该方法不建议使用，但是使用也不会报错
    {}
    public Student(String name)
    {
        this.name=name;
    }
    @Deprecated
    public void print()
    {
        System.out.println(this.name);
    }
}
public class Annotation
{
    public static void main(String[] args)
    {
        Student s1=new Student(); //表示该构造方法不建议使用，但是使用也不会报错

        Student s2=new Student("pick");


    }
}



///@SuppressWarings  压制警告
        public class Annotation
        {
            public static void main(String[] args)
            {

        @SuppressWarnings( "unused" )  //加上压制警告，就不会有警告
        int a;  //变量a没有使用，会有警告
    }
}