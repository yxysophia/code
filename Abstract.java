///抽象类
// abstract class Person   //抽象类
// {
//     private String name;
//     public Person()
//     {
//         System.out.println("抽象父类构造");
//     }
//     abstract public void fun1(); //抽象方法
//     //abstract public void func2();  //两个抽象方法必须全覆写
// }
// class Student extends Person
// {
//     public Student()
//     {
//         System.out.println("子类构造");
//     }
//     public void fun1()
//     {
//         System.out.println("子类继承抽象类");
//     }
// }
// public class  Abstract
// {
//     public static void main(String[] args)
//     {
//         Person p=new Student(); //向上转型
//         p.fun1();  //调用的子类中被覆写的fun1();
//     }
// }

/////面试题
// abstract class Person   //抽象类
// {
//     public Person() //3.调用父类构造
//     {
//         this.fun1(); //4.调用fun1,发现父类中fun1为抽象类，就调子类中覆写的fun1
//     }
//     abstract public void fun1(); //抽象方法
   
// }
// class Student extends Person
// {
//     private int num=100; //7.调子类构造时初始化属性变为100
//     public Student(int num)  //2.调用子类构造
//     {
//         this.num=num; //赋值后num变为30
//     }
//     public void fun1() //5.此时还没有调子类构造，属性是在调构造函数时初始化，所以此时还没有初始化属性
//     {
//         System.out.println(this.num); // 6.没有初始化，属性默认值为0
//     }
// }
// public class  Abstract
// {
//     public static void main(String[] args)
//     {
//         new Student(30);//1.实例化子类对象  结果为0
//         new Student(30).fun1();  //结果为0 30 ，因为先调了父类构造，所以有0
//     }
// }


////抽象类中允许不定义任何的抽象方法，但是此时抽象类依然无法直接创建实例化对象。
// abstract class Person
// {
//     public void fun1();
// }
// public class Abstract
// {
//     public static void main(String[]args)
//     {
//         new Person();  //错误
//     }
// }

// ////抽象内部类

// abstract class Person
// {
//     public abstract void fun1();
//     abstract class  B
//     {
//         public abstract void fun2();
//     }  
// }
// class Student extends Person
// {
//     public void fun1()  //对父类直接抽象方法覆写
//     {

//     }
//     class C extends B
//     {
//         public void fun2()
//         {

//         }
//     }
// }
// public class Abstract
// {
//     public static void main(String[]args)
//     {
//         new Student();  
//     }
// }
import java.util.Scanner;

abstract class CaffeineBerverage  //父类是咖啡因饮料
{
    //模板方法 声明为final:只允许子类使用，不允许覆写
    final void prepareRecipe()
    {
        boilWater();
        brew();
        if(customerWantsCondiments())
        {
             addCondiments();
        }
        pourInCup();
    }
    public void boilWater()  //烧水
    {
        System.out.println("将水煮沸");
    }
    public void pourInCup()  
    {
        System.out.println("将饮料调入杯中");
    }
    ////钩子方法
    boolean customerWantsCondiments() //顾客是否想要添加东西
    {
        return true;
    }
    abstract public void brew();//处理饮料的方式
    abstract public void addCondiments(); //向饮料里加东西
}
class Coffee extends CaffeineBerverage  //咖啡
{
    public void  brew()
    {
        System.out.println("冲泡咖啡");
    }
    public void addCondiments()
    {
        System.out.println("加糖和奶");
    }
    boolean customerWantsCondiments()  //重写
    {
        System.out.println("请问您想要加糖或奶吗？ y/n");
        String result=getUserInfo();
        if(result.equals("y"))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    private String getUserInfo()
    {
        Scanner scanner=new Scanner(System.in);
        String str=scanner.nextLine();
        return str;
    }
}

class Tea extends CaffeineBerverage
{
    public void brew()
    {
        System.out.println("浸泡茶叶");
    }
    public void addCondiments()
    {
        System.out.println("加柠檬");
    }
}

public class Abstract
{
    public static void main(String[] args)
    {
        CaffeineBerverage coffee=new Coffee();
        coffee.prepareRecipe();
        CaffeineBerverage tea=new Tea();
        tea.prepareRecipe();
    }
}