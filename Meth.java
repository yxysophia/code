package CODE.反射;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

class Person
{
    private String name;
    private int age;
    public void print(String name,int age)
    {
        this.name=name;
        this.age=age;
        System.out.println("name:"+this.name+" age:"+this.age);
    }
    private void print(String str)
    {
        System.out.println(str);
    }
}

public class Meth
{
    public static void main(String[] args) throws IllegalAccessException, InstantiationException, NoSuchMethodException, InvocationTargetException {
        Class<?> cls=Person.class;
        Person person=(Person)cls.newInstance();
        Method printMeth=cls.getMethod("print",String.class,int.class);
        printMeth.invoke(person,"pick",10); //name:pick age:10

        //Method对象调set
        Method printStr=cls.getDeclaredMethod("print", String.class); //取得本类本任意权限方法
        printStr.setAccessible(true);  //动态破坏权限，使私有权限可见
        printStr.invoke(person,"nice day"); //nice day
    }
}
//class Person
//{
//    private String name;
//    private int age;
//
//    public void setName(String name) {
//        this.name = name;
//    }
//
//    @Override
//    public String toString() {
//        return "姓名："+name+"年龄"+age;
//    }
//}
//public class Meth {
//    public static void main(String[] args) throws IllegalAccessException, InstantiationException, NoSuchMethodException, InvocationTargetException {
//        //拿到Person类的Class对象
//        Class<?> cls=Person.class;
//
//        //创建Person类的实例化对象
//        Person per=(Person)cls.newInstance();
//        //拿到setName的Method对象
//        Method setMethod=cls.getMethod("setName", String.class);
//        //通过invoke进行 调用
//        setMethod.invoke(per,"hha");
//        System.out.println(per);
//
//    }
//}
