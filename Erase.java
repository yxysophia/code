package CODE.泛型;

import java.lang.reflect.Field;

class MyErase<T,E extends Number>  // E 只能是Number及其子类
{
    private  T data1;
    private  E data2;
    public MyErase(T data1,E data2)
    {
        this.data1=data1;
        this.data2=data2;
    }
}
//类型擦除
public class Erase
{
    public static void main(String[] args)
    {
        MyErase<String,Integer> m1=new MyErase<>("pick",10);
        Class cl=m1.getClass();
        //getDeclaredFields()：获得某个类的所有声明的字段，即包括public、private和proteced，但是不包括父类的申明字段。
        Field[] field=cl.getDeclaredFields();
        for(Field data :field)
        {
            //getType返回声明字段的类型
            System.out.println(data.getType());  //class java.lang.Object  class java.lang.Number
            //由于会有类型擦除，T没有指定上限会被擦除为Object
            //class java.lang.Object

            //E  extends Number，指定上限为Number,类型擦除后成为Number
            //class java.lang.Number
        }
    }
}

class Me<T>
{
    private T data;
}
public class Erase
{
    public static void main(String[] args)
    {
        Me<String> m1=new Me<>();
        Me<Integer> m2=new Me<>();
        //打印两个在jvm中的Class，获得类型的类型类
        System.out.println(m1.getClass());  //class CODE.泛型.Me
        System.out.println(m2.getClass());  //class CODE.泛型.Me

    }
}

