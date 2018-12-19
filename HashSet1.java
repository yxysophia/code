package CODE.类集;


import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

//hashset ---无序存储,可以存放null,不允许重复元素
public class HashSet1 {
    public static void main(String[] args) {
        Set<String> set=new HashSet<>();
        set.add("pick");
        set.add("hello");
        set.add("hello");
        set.add(null);
        System.out.println(set);//[null, pick, hello]
    }
}
