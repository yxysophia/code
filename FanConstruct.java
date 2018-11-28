package CODE.反射;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

////反射与构造
class Student
{
    private String name;
    private int sno;

    public Student()
    {
    }
    private Student(String  name, int sno) {
        this.name = name;
        this.sno = sno;
    }
    public String toString()
    {
        return "姓名:"+name+"学号"+sno;
    }
}
public class FanConstruct {
    public static void main(String[] args) throws NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException {
        Class<?> cls=Student.class;
        Constructor<?> constructor=cls.getDeclaredConstructor(String.class,int.class);
        constructor.setAccessible(true);
        //Constructor类提供的newInstance()方法实例化对象 ，参数是要设置的值
        //可以通过Constructor类提供的setAccessible使动态破坏权限，设置为true后，private权限可以在外部使用
        //但是也是在在本次JVM进程有效，重新启动后依然是private权限
        System.out.println(constructor.newInstance("pick",10)); //姓名:pick学号10
    }
}
