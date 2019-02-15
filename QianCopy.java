
class Teacher {
    private String name;
    private String position;

    public Teacher(String name, String position) {
        this.name = name;
        this.position = position;
    }

    @Override
    public String toString() {
        return "QianCopy{" +
                "name='" + name + '\'' +
                ", position='" + position + '\'' +
                '}';
    }

    public void setName(String name) {
        this.name = name;
    }
}

class Student implements  Cloneable
{
    private String name;
    private Integer age;
    private Teacher teacher;

    public Student(String name, Integer age, Teacher teacher) {
        this.name = name;
        this.age = age;
        this.teacher = teacher;
    }

    @Override
    protected Student clone() throws CloneNotSupportedException {
        Student student=null;
        student=(Student)super.clone();
        return student;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", teacher=" + teacher +
                '}';
    }
}

public class QianCopy
{
    public static void main(String[] args) throws CloneNotSupportedException {
        Teacher teacher=new Teacher("ali","manager");
        Student student=new Student("sophia",10,teacher);
        System.out.println("这是原student");
        System.out.println(student);
        System.out.println("这是cloneStudent");
        Student cloneStudent=student.clone();
        System.out.println(cloneStudent);

        System.out.println("修改techer姓名");
        teacher.setName("Jack");//修改teacher的名称，student里的teacher姓名会改变
        System.out.println("这是修改后原student");
        System.out.println(student);
        System.out.println("这是修改后cloneStudent");
        System.out.println(cloneStudent);
    }
}