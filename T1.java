package CODE.泛型;

class MyClass<T>
{
    T data;
}

//public  class T1
//{
//    public static void main(String[] args)
//    {
//        //使用泛型类，在使用时定义类类型
//        MyClass<Integer> c1=new MyClass<>();
//        MyClass<String> c2=new MyClass<String>();
//
//    }
//}


///////Position用泛型类
class Position<T>
{
    private T x;
    private T y;

    public void setX(T x) {
        this.x = x;
    }

    public void setY(T y) {
        this.y = y;
    }

    public T getX() {
        return x;
    }

    public T getY() {
        return y;
    }
}

public  class T1
{
    public static void main(String[] args)
    {
        Position<Integer> p1=new Position<>();  //定义后类型参数T为String类
        p1.setX(10);
        p1.setY(20);
        int x1=p1.getX();  //没有强转，这时T已经是String类
        int y1=p1.getY();   //引入泛型后，避免了向下转型
        System.out.println(x1+"、"+y1);

        Position<String> p2=new Position<>();
        p2.setX("东经32");
        p2.setY("北纬50");
        String x2=p2.getX();
        String y2=p2.getY();
        System.out.println(x2+"、"+y2);

    }
}


//用Object
class Position
{
    private Object x;
    private Object y;

    public void setX(Object x) {
        this.x = x;
    }

    public void setY(Object y) {
        this.y = y;
    }

    public Object getX() {
        return x;
    }

    public Object getY() {
        return y;
    }
}
public  class T1
{
    public static void main(String[] args)
    {
        //假设位置是double型
        Position p1=new Position();
        p1.setX(2.2);  //自动装箱向上转型为Object
        p1.setY(3.4);
        double x1=(double)p1.getX();  //强转向下转为Double,然后自动拆箱为double
        double y1=(Double)p1.getY();
        System.out.println(x1+"、" + y1);

        //假设位置是String类型
        Position p2=new Position();
        p2.setX("东经32");  //向上转型为Object
        p2.setY("北纬50");
        String x2=(String)p2.getX();  //Object类向下转型为一个具体的类String
        String y2=(String)p2.getY();
        System.out.println(x2+"、"+y2); //东经32、北纬50

        Position p3=new Position();
        p3.setX(3.4);
        p3.setY("北纬50");
        String x3=(String)p3.getX();
        String y3=(String)p3.getY();
        System.out.println(x3+"、"+y3);

    }
}



///泛型类
class A<T>
{
    private  T a;
    private  T b;


    public <T> T print1(T t)  //泛型方法，泛型方法中泛型参数和泛型类的泛型参数没有关系
    {
        System.out.println(t);
        return t;
    }
    public void print2(T t) //普通方法
    {
        System.out.println(t);
    }
}
public class T1 {
    public static void main(String[] args)
    {
        A<String> a1=new A<String>();
        a1.print2("pick");  //普通方法
        int ret=a1.print1(10);  //返回值是int,自动拆箱

        //如果泛型方法 泛型参数是Integer,泛型类泛型参数是String，泛型类的泛型参数和泛型方法泛型方法无关
    }
}


///////泛型接口
interface IA<T>  //泛型接口
{
    public void func(T t);
}

//子类继续保持泛型
class A1Impl<T> implements  IA<T>
{
    public void func(T t)
    {
        System.out.println(t);
    }
}

//子类在定义时确定好类型
class A2Impl implements IA<Integer>
{
    public void func(Integer data)
    {
        System.out.println(data);
    }
}
public class T1 {
    public static void main(String[] args)
    {
       IA<String> a1=new A1Impl<>();  //子类继续保持泛型
       a1.func("hello");

       IA a2=new A2Impl();  //子类定义时确定泛型参数
       a2.func(10);
    }
}

