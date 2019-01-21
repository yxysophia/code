package CODE.比较器;

//实现Comparable接口实现TreeSet

import java.util.Comparator;
import java.util.Set;
import java.util.TreeSet;

//实现Comparable接口
class Person implements Comparable<Person>
{
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public int compareTo(Person o) {
        if(this.age>o.age)
            return 1;  //那么是升序
        else if(this.age<o.age)
            return -1;
         return this.name.compareTo(o.name);  //String类有自己的compareTo方法
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}
//public class Comparator1 {
//    public static void main(String[] args) {
//        Set<Person> set=new TreeSet<>();
//        Person p1=new Person("pick",20);
//        Person p2=new Person("bai",2);
//        set.add(p1);
//        set.add(p2);
//        System.out.println(set);  //[Person{name='bai', age=2}, Person{name='pick', age=20}]
//    }
//}

//利用比较器
class Person2
{
    private String name;
    private int age;

    public Person2(String name, int age) {
        this.name = name;
        this.age = age;
    }
    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}

//升序排
//jdk默认是升序，是基于:
//<    return -1
// =   return 0
// >  return 1
class AscSort implements Comparator<Person2>
{
    @Override
    public int compare(Person2 o1, Person2 o2) {
        if(o1.getAge()>o2.getAge())
            return 1;
        else if(o1.getAge()==o2.getAge())
            return 0;
        return -1;
    }
}

//降序排
//降序：<  return 1
//    = return 0
//   > return -1
class DescSort implements Comparator<Person2>
{
    @Override
    public int compare(Person2 o1, Person2 o2) {
        if(o1.getAge()>o2.getAge())
            return -1;
        else if(o1.getAge()==o2.getAge())
            return 0;
        return 1;
    }
}
public class Comparator1 {
    public static void main(String[] args) {
        Set<Person2> set=new TreeSet<>(new DescSort());  //降序排
        Person2 p1=new Person2("pick",20);
        Person2 p2=new Person2("bai",28);
        set.add(p1);
        set.add(p2);
        System.out.println(set); //[Person{name='bai', age=28}, Person{name='pick', age=20}]
    }
}
