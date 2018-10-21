////super用于构造方法
// class Person
// {
//     private String name;
//     public Person(String name)
//     {
//         this.name=name;
//     }
    
// }
// class Student extends Person
// {
//     private int num;
//     public Student(String name,int num)
//     {
//         super(name); //调父类有参构造，必须写super(参数)
//         this.num=num;
//     }
//     // public Student(int num)  //调父类无参构造，可以不写super
//     // {
//     //     this.num=num;
//     // }
// }
// public class Final
// {
//     public static void main(String[] args)
//     {
//         Student s1=new Student(1);
//     }
// }

////super用于普通方法
// class Person
// {
//     private String name;
//     public void func()
//     {
//         System.out.println("person::func()");
//     }
// }
// class Student extends Person
// {
//     private int num;
//     public void func()
//     {
//         super.func();
//         System.out.println("Student::func()");
//     }
// }
// public class Final
// {
//     public static void main(String[] args)
//     {
//         Student s=new Student(); //person::func()  Student::func()
//         s.func();
//     }
// }

/////super用于属性
// class Person
// {
//     public String name="dad";  
// }
// class Student extends Person
// {
//     private String name="son";
//     public void show()
//     {
//         System.out.println(super.name);  //父类属性
//         System.out.println(this.name); //子类的属性
//     }
// }
// public class Final
// {
//     public static void main(String[] args)
//     {
//         Student s=new Student(); //person::func()  Student::func()
//         s.show();
//     }
// }

///final

// class A
// {
//     private int num;
// }
// public class Final
// {
//     public static void main(String[] args)
//     {
//        final A a1 = new A(); 
//         //a1的值不能改，即a1只能指向一个对象，但是对象的内容可以改
//        A a2=new A();
//        a1=a2;  //错误
//     }
// }

public class Final
{
    public static void main(String[] args)
    {
        byte b1=1,b2=2,b3,b6,b8;
        final byte b4=4,b5=6,b7=9;  //final定义变量值和类型都不能变
        b3=b1+b2; // byte 和byte类型相加，两个数类型都转为int,且结果也是int,从int到byte需要强转，所以该语句错误
        b6=b4+b5; // final byte 和final byte相加类型不会变，结果也是byte，所以该语句正确
        b8=b1+b4; //  byte 和final byte相加，结果是 int ,从int到byte需要强转，所以该语句错误
        b7=b2+b5;  // b7是final修饰，只不可以改，所以该语句错误
        System.out.println(b6); //10
    }
}

