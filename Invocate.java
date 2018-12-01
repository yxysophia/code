package CODE.反射;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

interface IFruit1
{
    void eat();
}
class RealFruit implements IFruit1
{
    public void eat()
    {
        System.out.println("eat fruit");
    }
}

//动态代理类
class ProxyFruit implements InvocationHandler
{
    //绑定任意接口的对象，使用Object描述
    private Object target;

    //取得真实对象的绑定处理，同时返回代理对象
    //返回一个代理对象（这个对象是根据接口定义动态创建生成的代理对象）
    public Object bind(Object target)
    {
        this.target=target;
        return Proxy.newProxyInstance(target.getClass().getClassLoader(),target.getClass().getInterfaces(),this ) ;
//        return Proxy.newProxyInstance(target.getClass().getClassLoader(),
//                target.getClass().getInterfaces(),this);
    }
    public void Before()
    {
        System.out.println("核心业务处理之前");
    }
    public void After()
    {
        System.out.println("核心业务处理之后");
    }
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable
    {
        Object ret=null;
        this.Before();
        ret=method.invoke(this.target);
        this.After();
        return ret;
    }
}


public class Invocate{
    public static void main(String[] args) {
        IFruit iFruit=(IFruit) new ProxyFruit().bind(new RealFruit()) ;
        iFruit.eat();

    }
}
