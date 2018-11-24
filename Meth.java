package CODE.反射;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

class Person
{
    private String name;
    private int age;

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "姓名："+name+"年龄"+age;
    }
}
public class Meth {
    public static void main(String[] args) throws IllegalAccessException, InstantiationException, NoSuchMethodException, InvocationTargetException {
        //拿到Person类的Class对象
        Class<?> cls=Person.class;

        //创建Person类的实例化对象
        Person per=(Person)cls.newInstance();
        //拿到setName的Method对象
        Method setMethod=cls.getMethod("setName", String.class);
        //通过invoke进行 调用
        setMethod.invoke(per,"hha");
        System.out.println(per);

    }
}
