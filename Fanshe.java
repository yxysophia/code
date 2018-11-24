package CODE.反射;


import sun.security.smartcardio.SunPCSC;

interface IFruit
{
    void eat();
}
class Banana implements IFruit
{
    @Override
    public void eat() {
        System.out.println("eat a banana~~~");
    }
}
class Apple implements IFruit
{
    @Override
    public void eat() {
        System.out.println("eat an aaple");
    }
}


//通过发射写简单工厂模式
class Factory
{
    public static IFruit getInstance(String className)
    {
        IFruit fruit=null;
        try {
            //取得任意子类反射对象 Class 是类  forName()是静态方法
            Class<?> cls=Class.forName(className);
            System.out.println(cls.getPackage().getName());
            //通过反射实例化对象
            //因为newInstance()返回的是 T，从高类型到低类型需要强转
            fruit=(IFruit)cls.newInstance();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return fruit;
    }
}

public class Fanshe {
    public static void main(String[] args) {
        IFruit fruit=Factory.getInstance("CODE.反射.Banana");
        fruit.eat();
    }

}
