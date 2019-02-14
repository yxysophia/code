package StreamDemo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.function.Consumer;

public class TestCollection {
    public static void main(String[] args) {
        List<String> list=new ArrayList<>();
        Collections.addAll(list,"hello","happy","haha");
        //JDK1.8中可以使用lambda表达式和方法引用
        list.forEach((s)-> System.out.println(s));  //lambda表达式
        list.forEach(System.out::println);  //方法引用

        //匿名内部类--类在方法中
        list.forEach(new Consumer<String>() {
            @Override
            public void accept(String s) {
                System.out.println(s);
            }
        });
    }
}
