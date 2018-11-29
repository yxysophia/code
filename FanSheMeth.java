package CODE.反射;

import java.lang.reflect.Method;

class Person1
{
    public void print1(){}
    private void print2(){}
    public void print3(String str){}
}
class Student1 extends Person1
{
    public void print2(int m){
    }
    private void print3(int a){}
}
public class FanSheMeth {
    public static void main(String[] args) throws IllegalAccessException, InstantiationException, NoSuchMethodException {
        Class<?> cls=Student1.class;

        Student1 student1=(Student1)cls.newInstance(); //通过反射取得实例化对象
        Method method1[]=cls.getDeclaredMethods();
        Method method2[]=cls.getMethods();
        Method method3=cls.getMethod("print3",String.class);
        Method method4=cls.getDeclaredMethod("print3", int.class);
        System.out.println("getDeclaredMethods取得本类中所有权限方法：");
        for(Method me1:method1)
        {
            System.out.println(me1);
        }
        System.out.println("getMethods取得本类和父类中所有public权限方法");
        for(Method me2:method2)
        {
            System.out.println(me2);
        }
        System.out.println("getMethod取得本类和父类所有public权限指定方法:");
        System.out.println(method3);
        System.out.println("getDeclaredMethod取得本类中public权限指定方法");
        System.out.println(method4);
    }

}
