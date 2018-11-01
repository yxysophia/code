package CODE;


////接口实现标准

////电脑有接口，而接口都是一样的，只是接口类别不同，那么就可以利用接口统一化，完成一些操作
//interface IUsb  //定义一个Usb接口
//{
//    void setUp(); //安装
//    void work();  //工作
//}
//class Computer   //电脑类
//{
//    public void plugin(IUsb usb)   //用接口实现标准化，通过向上转型
//    {
//        usb.setUp();
//        usb.work();
//    }
//}
//class printUsbImpl implements  IUsb
//{
//    public  void setUp()
//    {
//        System.out.println("安装打印机");
//    }
//    public void work()
//    {
//        System.out.println("打印机工作");
//    }
//}
//class uDiskImpl implements IUsb
//{
//    public  void setUp()
//    {
//        System.out.println("安装U盘");
//    }
//    public void work()
//    {
//        System.out.println("U盘工作");
//    }
//}
//public class InterStander
//{
//    public static void main(String[] args)
//    {
//        Computer computer=new Computer();
//        computer.plugin(new printUsbImpl()); //安装打印机  打印机工作
//        computer.plugin((new uDiskImpl()));  //安装U盘  U盘工作
//    }
//}


////停车场停车
interface Ivehicle  //定义一个车的接口
{
    void kind(); //车的类型  假设只有一个抽象方法
}
class Park
{
    public void whoPark(Ivehicle vehicle)
    {
        vehicle.kind();
    }
}
class AutiImple implements Ivehicle
{
    public void kind()
    {
        System.out.println("奥迪在停车");
    }
}
class BenzImpl implements  Ivehicle
{
    public void kind()
    {
        System.out.println("奔驰在停车");
    }
}
public class InterStander
{
    public static void main(String[] args)
    {
        Park park=new Park();
        park.whoPark(new AutiImple()); //奥迪在停车
        park.whoPark((new BenzImpl())); //奔驰在停车
    }
}