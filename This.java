abstract  class Role
{
    protected String name;
    private String sex;
    private int age;
    Role()
   {
       System.out.println("Role()");
   }
    Role(String name,String sex)
    {
        this.name=name;
        this.sex=sex;
    }
    Role(String name,String sex,int age)
    {
        this(name,sex);
        this.age=age;
    }
    //对成员变量的设置及获取
    public void SetName(String name)
    {
        this.name=name;
    }
    public String GetName()
    {
        return name;
    }
    public void SetSex(String sex)
    {
       this.sex=sex;
    }
    public String GetSex()
    {
        return sex;
    }
    public void SetAge(int age)
    {
        this.age=age;
    }
    public int GetAge()
    {
        return age;
    }
    abstract public void play();
    public void print()
    {
        System.out.println("父类");
    }
}
class Employee extends Role
{
    private int salary;
    private static int id;
    Employee()
    {
        System.out.println("Employee()");
    }
    Employee(String name,String sex,int age,int salary,int id)
    {
        super(name,sex,age);
        this.salary=salary;
        this.id=id;
    }
    public void print()
    {
        super.print();  //调用父类super
        
    public void play()
    {
        System.out.println(name+"的教师公编号是"+id+"、薪资是"+salary);
    }
    final public void sing()
    {
        System.out.println(name+"在唱歌");
    }
}
class Manager extends Employee
{
    final private String vehicle; //交通工具
    {
        vehicle="bus"; //final变量在声明时初始化或者在构造块、构造方法重初始化
    }
    public String GetVehicle()
    {
        return vehicle;
    }
}

public class This
{
    public static void main(String[] args){
    Employee e1=new Employee("张三","男",31,10000,1);
    e1.print();
    e1.play();
    e1.sing();
    Role r1=new Employee("李四","男",30,10000,2);
    r1.SetName("王二");
    r1.play();
    Manager m1=new Manager();
    System.out.println(m1.GetVehicle());
    }
}

