package CODE.集合类;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

class Person
{
    private String name;
    private int age;

    public Person(String name, int age) {
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

    @Override
    public boolean equals(Object obj) {
        if(obj==null)
            return false;
        if(this==obj)
            return true;
        Person p=(Person)obj; //向下转型
        return age==p.age&&name.equals(p.name);
    }
}

////自定义对象
public class Collection1 {
    public static void main(String[] args) {
        Person person1 = new Person("pick", 18);
        Person person2 = new Person("sophia", 18);
        List<Person> list = new ArrayList<>(); //ArrayList是list子类
        list.add(person1);
        list.add(person2);
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i)); //数组中每个元素是Person对象
        }
        System.out.println(list.contains(new Person("pick",18)));
    }
}


