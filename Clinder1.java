package Work.Interface;

////圆柱
interface  IA
{
    static  final double PI=3.14;
    double area();
}
interface  IB
{
    void setColour(String colour);
}
interface IC extends  IA,IB
{
    void volume();
}
class CylinderImpl implements IC
{
    private double radius; //圆柱半径
    private double height; //圆柱体的高
    private String colour;   //圆柱的颜色
    public double area()
    {
        return radius*radius*PI;
    }
    public CylinderImpl(double radius,double height)
    {
        this.radius=radius;
        this.height=height;
    }
    public void setColour(String colour)
    {
        this.colour = colour;
    }

    public void volume()
    {
        System.out.println("圆柱体体积是："+area()*height);
    }
}
public class Clinder1
{
    public static void main(String[] args)
    {
        IA a1=new CylinderImpl(2.2,3);
        a1.area();
        IB b1=(IB)a1;
        b1.setColour("red");
        IC c1=(IC)b1;
        c1.volume();
    }

}
