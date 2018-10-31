package CODE;
////饿汉模式
class Person
{
    private  String name;
    private static final  Person person =new Person(); //实例化一个静态全局常量对象，
    // 因为这个对象实例化出来不会再被改变，所以声明为final ,static final 是全局常量
    private  Person() //构造方法私有化
    {}
    public  static Person getPerson()
    {
        return person;
    }
}
public class Singleton
{
    public static void main(String[] args)
    {

        Person person1=Person.getPerson();
        Person person2=Person.getPerson();
        Person person3=Person.getPerson();
        System.out.println(person1); //CODE.Person@4554617c
        System.out.println(person2); //CODE.Person@4554617c
        System.out.println(person3); //CODE.Person@4554617c
        //可以发现三个对象的地址是一样的，事实上只实例化了一个对象，三个引用指向同一块堆内部
    }
}


///懒汉模式
class Person
{
    private  Person() //构造方法私有化
    {}
    private static  Person person; //该成员变量默认值为null
    public  static Person getPerson()
    {
        if(person==null)
        {
            person=new Person();
        }
        return person;
    }
}
public class Singleton
{
    public static void main(String[] args)
    {

        Person person1=Person.getPerson();
        Person person2=Person.getPerson();
        Person person3=Person.getPerson();
        System.out.println(person1); //CODE.Person@4554617c
        System.out.println(person2); //CODE.Person@4554617c
        System.out.println(person3); //CODE.Person@4554617c
        //可以发现三个对象的地址是一样的，事实上只实例化了一个对象，三个引用指向同一块堆内部
    }
}


////多例模式
class Sex
{
    private String sex;
    public static final int MALE_FLAG=1;
    public static final int FEMALE_FLAG=2;
    private static final Sex male=new Sex("男");
    private static final Sex femal=new Sex("女");
    private Sex(String sex)
    {
        this.sex=sex;
    }
    public static Sex getSex(int flag)  //定义一个falg，告诉要什么类型对象
    {
       switch(flag)
       {
           case MALE_FLAG:
               return male;
           case FEMALE_FLAG:
               return femal;
               default:
                   return null;
       }
    }
    public String toString()
    {
        return this.sex;
    }
}
public class Singleton
{
    public static void main(String[] args)
    {

        Sex male=Sex.getSex(Sex.MALE_FLAG);
        Sex female=Sex.getSex(Sex.FEMALE_FLAG);
        System.out.println(male);  //男
        System.out.println(female); //女
    }
}













