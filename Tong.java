package CODE.泛型;

class Message<T>
{
    private T message;

    public T getMessage()
    {
        return message;
    }
    public void setMessage(T message)
    {
        this.message=message;
    }
}

////?通配符
public class Tong
{
    public static void main(String[] args)
    {
        Message<String> m1=new Message<>();
        m1.setMessage("pick");
        func(m1);

        Message<Integer> m2=new Message<>();
        m2.setMessage(10);
        func(m2);

    }
    public static void func(Message<?> m)
    {
        //此时使用通配符"?"描述的是它可以接收任意类型，但是由于不确定类型，所以无法修改
        //m.setMessage("world"); //错误，不能修改数据
        System.out.println(m.getMessage());
    }
}
public class Tong
{
    public static void main(String[] args)
    {
        Message<String> m1=new Message<>();
        m1.setMessage("pick");
        func(m1);

        Message<Integer> m2=new Message<>();
        m2.setMessage(10);
        //func(m2);  //这里会出错，如果func形参指定类型，就要重载一个形参为Integer的func

    }
    public static void func(Message<String> m)
    {
        System.out.println(m.getMessage());
    }
}

////通配符----？ extends 类

class Mess<T extends Number>  //T只能是Number及其子类
{
    private  T mess;
    public void setMess(T mess)
    {
        this.mess=mess;
    }
    public T getMess()
    {
        return this.mess;
    }
}

public class Tong
{
    public static void main(String[] args)
    {
        //Mess<String> m1=new Mess<String>();  //错误，因为String不是Number的子类
        Mess<Integer> m2=new Mess<>();
        m2.setMess(10);  //自动装箱
        func(m2);

        Mess<Double> m3=new Mess<>();
        m3.setMess(19.3);
        func(m3);
    }
    public static void func(Mess<? extends Number> m)
    {
        //此时？继承了Number类，但依旧不知道具体类型，即无法修改数据
        //m.setMess(10);//错误
        System.out.println(m.getMess());
    }
}

class Met<T>
{
    private T met;
    public void setMet(T met)
    {
        this.met=met;
    }
    public T getMet()
    {
        return this.met;
    }
}

public class Tong
{
    public static void main(String[] args)
    {
       Met<String> m1=new Met<>();
       m1.setMet("pick");
       func(m1);  //接收String类

    }
    public static void func(Met<? super String> m)
    {
        m.setMet("world");  //可以设置属性：子类到父类是自动转型
        System.out.println(m.getMet());
    }
}