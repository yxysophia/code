package CODE.Map1;



import java.util.Comparator;
import java.util.TreeMap;

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
public class TestTreeMap {
    public static void main(String[] args) {
        TreeMap<Person2,Integer> treeMap=new TreeMap<>(new DescSort());
        treeMap.put(new Person2("pick",18),1);
        treeMap.put(new Person2("sophia",20),2);
        treeMap.put(new Person2("pick",18),3);
        System.out.println(treeMap); //{Person{name='sophia', age=20}=2, Person{name='pick', age=18}=3}

    }
}
