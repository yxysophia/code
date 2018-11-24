package CODE.反射;

class A{}
interface IB {}
interface IC{}

class ABC extends A implements IB,IC{}

public class pack {
    public static void main(String[] args) throws ClassNotFoundException {
        Class<?> cls=Class.forName("CODE.反射.ABC");
        //获得包名称
        System.out.println(cls.getPackage());  //package CODE.反射

        //获得父类的Class对象
        Class<?> cls1=cls.getSuperclass();
        System.out.println(cls1);

        //获得实现的父接口
        Class<?>[] clsInters=cls.getInterfaces();
        for(Class clsInter : clsInters)
        {
            System.out.println(clsInter);//interface CODE.反射.IB   interface CODE.反射.IC
        }

        System.out.println();
    }
}
