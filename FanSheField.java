package CODE.反射;

import com.sun.corba.se.impl.orbutil.concurrent.Sync;

import java.lang.reflect.Field;

class Person2
{
    private String name;
    private int age;
    public int count=10;
}

class Student2 extends Person2
{
    public int num=1;
    private String sno; //课程号
}
public class FanSheField {
    public static void main(String[] args) throws IllegalAccessException, InstantiationException, NoSuchFieldException {
        Class<?> cls=Student2.class;
        Student2 student2=(Student2)cls.newInstance();
        System.out.println("getField取得本类和父类中public权限属性:");
        Field count=cls.getField("count");
        count.set(student2,1);  //设置值
        System.out.println("Field取得本类公有属性值: "+count+":"+count.get(student2));

        System.out.println("getDeclaredField取得本类任意权限属性");
        Field sno=cls.getDeclaredField("sno");
        sno.setAccessible(true);  //破坏私有权限
        sno.set(student2,"3");
        System.out.println("Field取得本类私有权限属性值: "+sno+":"+sno.get(student2));
        System.out.println("取得属性类型:"+sno.getType());

        System.out.println("getFields取得本类和父类所有公有权限属性");
        Field field1[]=cls.getFields();
        for(Field f1: field1)
        {
            System.out.println(f1);
        }

        System.out.println("getDeclaredFields取得本类所有权限属性");
        Field field2[]=cls.getDeclaredFields();
        for(Field f2:field2)
        {
            System.out.println(f2);
        }
    }
}
