package CODE.反射;

//工厂模式---反射

interface Study
{
    void need();
}
class Pen implements Study
{
   public void need()
   {
       System.out.println("需要一直笔");
   }
}
class Book implements Study
{
    public void need()
    {
        System.out.println("需要一个本子");
    }
}
class Pencil implements Study
{
    public void need()
    {
        System.out.println("需要一只铅笔");
    }
}
class Factory1
{
    public static Study getStudy(String className)
    {
        Study study=null;
        try {
            //cls是一个Class类对象  通过className取得具体Class对象
            Class<?> cls=Class.forName(className);
            //通过反射实例化对象
            //因为newInstance返回的是Object，所以需要强转称为一个类型
            study=(Study)cls.newInstance();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return study;
    }
}
public class FanSheFac {
    public static void main(String[] args)
    {
        Study study1=Factory1.getStudy("CODE.反射.Pen");
        study1.need();  //需要一直笔
        Study study2=Factory1.getStudy("CODE.反射.Pencil");
        study2.need();  //需要一只铅笔
    }
}

