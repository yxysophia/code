package CODE.Java新特性;


/////方法引用  方法引用一般和函数式接口一起使用


/////引用类中静态方法 --> 类名称 :: 静态方法名称
////引用类中静态方法：接口中抽象方法是引用的类的静态方法别名，调用这个抽象方法相当于调用类的静态方法
@FunctionalInterface //函数式编程接口 接口里只有一个抽象方法
interface  IString<T,E>
{
    E switchPara(T t);  //将给定类型转换成字符串
}
public class Method
{
    public static void main(String[] args)
    {
        ////valueOf是String类的静态方法，将特定类型转换成字符串
        IString<Integer,String> s=String ::valueOf; //引用类中静态方法，引用的是String类的静态方法valueOf
        int num=10;
        String str=s.switchPara(num); //swichPare是valueOf的别名，相当于调用的是String.valueOf（num)方法
        System.out.println(str); //10
    }
}


////////引用某个对象的方法---->实例化对象 :: 普通方法
/////引用某个对象的方法：接口中抽象方法是这个对象的方法的别名，调用这个抽象方法相当于调用该对象的方法
interface  IString<T>
{
    T lower();
}
public class Method
{
    public static void main(String[] args)
    {
        //"PICK"是字符串对象 "PICK".toLowerCase()将字符串转为小写
        IString<String> s="PICK"::toLowerCase; //引用字符串对象方法，引用的是toLowerCase方法
        String str=s.lower();  //接口里的lower抽象方法是toLowerCase方法的别名，相当于调用的是”PICk".toLowerCase()方法
        System.out.println(str); //pick
    }
}


/////引用类中的普通方法----> 类名称 :: 普通方法名
////引用类中的普通方法：接口中抽象方法是该类普通方法的别名，调用这个抽象方法相当于调用的这个类的普通方法
@FunctionalInterface
interface  IString<T,E>
{
     T compare(E t1,E t2);
}
public class Method
{
    public static void main(String[] args)
    {
        IString<Integer,String> s=String :: compareTo; //  引用的是String类的compareTo方法
        Integer ret=s.compare("范","杨");  //接口里的comare抽象方法是compareTo方法的别名，相当于调用的是"范".compareTo("杨")
        System.out.println(ret); // 7067
    }
}


//////引用类的构造方法----> 类名称 :: new
////引用类的构造方法：如果接口中抽象方法是实例化一个对象，引用类的构造方法后，那么调用接口的create方法相当于调用类的构造
class person
{
    private  String name;
    public person(String name)
    {
        this.name=name;
    }

    @Override
    public String toString() {
        return "name:"+name;
    }
}
@FunctionalInterface
interface  IString<P,T>
{
    P createPerson(T t);  //实例化一个person对象
}
public class Method
{
    public static void main(String[] args)
    {
        IString<person,String> s=person :: new; //  引用的是person类的构造方法
        person p=s.createPerson("pick");  //createPerson成为person类构造方法的别名，相当于调用的person类的构造方法
        System.out.println(p); // name:pick
    }
}