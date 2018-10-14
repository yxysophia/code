class Person
{
    public String _name;
    public int _age;
    public String _sex;
    public void ete()
    {
        System.out.println(_name+"在吃饭");
    }
    public void handsome()
    {
        if(_sex=="女")
          {
               System.out.println(_name+"真漂亮");
          }
        else
        {
            System.out.println(_name+"真帅");
        }

    }
}
public class Object
{
    public static void main(String[] args)
    {
        Person p1=new Person();
        p1._name="pick";
        p1._sex="男";
        p1._age=11;
        p1.handsome();
        Person p2=new Person();
        p2._name="sophia";
        p2._sex="女";
        p2.handsome();
    }
}
