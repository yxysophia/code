package Work.Interface;

interface InterfaceA {
    String S = "good ";
    void f();
}

abstract class ClassA {
    abstract void g();
}

class ClassB extends ClassA implements InterfaceA {
    void g() {
        System.out.print(S);
    }

    public void f() {
        System.out.print(" "+ S);
    }
}
public class Inter {
    public static void main(String[] args) {
        ClassA a = new ClassB();
        InterfaceA b = new ClassB();
        a.g();
        System.out.println("*****");
        b.f();
    }
}

