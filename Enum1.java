package CODE.Java新特性;

////Color用枚举类
enum Color  //Color是一个枚举类
{
    RED,  //枚举对象
    GREEN,
    BLUE
}
public class Enum1
{
    public static void main(String[] args)
    {
        System.out.println(Color.BLUE);  //是对象，而不是对象地址
    }
}

////Color用多例模式
class Color
{
    private String colour;
    public static final int RED_FLAG=1; //需要定义为static final ,否则在静态get方法的case里无法使用
    public static final int GREEN_FLAG=3;
    public static final int BLUE_FLAG=5;
    private static final Color Red=new Color("red");
    private static final Color Green=new Color("green");
    private static final Color Blue=new Color("blue");
    private Color(String colour)
    {
        this.colour=colour;
    }
    public static Color getColor(int flag)
    {
        switch(flag)
        {
            case RED_FLAG:
                return Red;
            case  GREEN_FLAG:
                return Green;
            case BLUE_FLAG:
                return Blue;
                default:
                    return null;
        }
    }
    public String toString()
    {
        return this.colour;
    }
    public class Enum1 {
        public static void main(String[] args) {
            Color color = Color.getColor(Color.RED_FLAG);
            System.out.println(color);  //red
        }
    }

}

////Enum类的name()和ordinal()
enum Color  //Color是一个枚举类
{
    RED,  //枚举对象
    GREEN,
    BLUE
}
public class Enum1
{
    public static void main(String[] args)
    {
        Color color=Color.GREEN;
        System.out.println("对象:"+color.name()+ " 下标："+color.ordinal()); //对象:GREEN 下标：1
    }
}


////取得所有枚举类对象
enum Color  //Color是一个枚举类
{
    RED,  //枚举对象
    GREEN,
    BLUE
}
public class Enum1
{
    public static void main(String[] args)
    {
       for(Color tmp:Color.values())  //取得所有的枚举对象
       {
           System.out.println(tmp); //RED GREEN BLUE //覆写了toString
       }
    }
}

////枚举中定义其他结构
enum Color  //Color是一个枚举类
{
    RED("red"), GREEN("green"), BLUE("blue"); //枚举类对象声明放首行
    private  String clour;
    private Color(String clour)  //构造私有化
    {
        this.clour=clour;
    }
    public String toString()
    {
        return this.clour;
    }
}
public class Enum1
{
    public static void main(String[] args)
    {
        Color color=Color.GREEN;
        System.out.println(color);  //green,如果没有在枚举类覆写，输出的是Enum覆写的oString 为GREEN
    }
}


////枚举类实现接口
interface IColor  //接口
{
    String func();  //抽象方法
}
enum Color  implements  IColor//枚举类实现接口
{
    RED("red"), GREEN("green"), BLUE("blue"); //枚举对象
    private  String clour;
    private Color(String clour)  //构造私有化
    {
        this.clour=clour;
    }
    public String func()  //覆写抽象方法
    {
        return this.clour;
    }
}
public class Enum1
{
    public static void main(String[] args)
    {
        IColor ic=Color.BLUE;  //枚举类实现了接口后，每个枚举对象变为接口对象
        System.out.println(ic.func());  //blue
    }
}


//////switch支持枚举
enum Sex
{
    MALE,FEMALE
}
public class Enum1
{
    public static void main(String[] args)
    {
        switch(Sex.MALE)  //switch支持枚举对象，但是用处不大，因为已经知道对象
        {
            case FEMALE:
                System.out.println("beautiful");
                break;
            case MALE:
                System.out.println("handsome");
        }
    }
}

/////枚举应用
enum Sex
{
    MALE,FEMALE
}
class Person
{
    private String name;
    private Sex sex;  //注意是枚举对象，类型是枚举类
    public Person(String name,Sex sex)
    {
        this.name=name;
        this.sex=sex;
    }
}

public class Enum1
{
    public static void main(String[] args)
    {
       Person p=new Person("pick",Sex.MALE);
    }
}