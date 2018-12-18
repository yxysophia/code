package CODE.类集;

import java.util.ArrayList;
import java.util.List;

//集合与简单Java类
class Student
{
    private int sno; //序号
    private String name; //姓名

    public Student(int sno, String name) {
        this.sno = sno;
        this.name = name;
    }
    //覆写equals方法
    public boolean equals(Object obj)
    {
        if(obj==null)
            return false;
        if(this==obj)
        {
            return true;
        }
        if(!(obj instanceof Student))
            return false;
        Student st=(Student)obj; //向下转型
        return sno==st.sno && name.equals(st.name);
    }

    @Override
    public String toString() {
        return "学号："+sno+" 姓名："+name;
    }
}
public class ListArray1 {
    public static void main(String[] args) {
        List<Student> list=new ArrayList<>();//ArrayList是list子类
        list.add(new Student(1,"a"));
        list.add(new Student(2,"b"));
        list.add(new Student(3,"c"));
        list.add(new Student(2,"b"));
        // 集合类中contains()、remove()方法需要equals()支持 ,所以需要覆写equals()方法
        System.out.println(list.contains(new Student(2,"b"))); //true
        list.remove(new Student(2,"b"));
        for(int i=0;i<list.size();i++)
        {
            System.out.println(list.get(i)); //学号：1 姓名：a    学号：3 姓名：c  学号：2 姓名：b
        }

    }
}
