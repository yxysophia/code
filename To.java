package Work.Exception;

class Person
{
    private String name;
    private int age;
    private int salary;
    public Person(String name,int age)
    {
        this.name = name;
        this.age = age;
    }

    public Person(String name, int age, int salary) {
        this(name,age);
        this.salary = salary;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public int getSalary() {
        return salary;
    }
    public String toString()
    {
        return name+"-"+age+"-"+salary ;
    }
    public boolean equals(Person p)
    {
        return this.name==p.name&&this.age==p.age&&this.salary==p.salary;
    }
}
public class To
{
    public static void main(String[] args)
    {
        Person p1=new Person("张三",19,10000);
        System.out.println(p1);
        Person p2=new Person("张三",19,10000);
        System.out.println(p1.equals(p2));
    }
}
