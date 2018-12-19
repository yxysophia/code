package CODE.类集;

import java.util.Set;
import java.util.TreeSet;

////TreeSet
//TreeSet基于红黑树实现，不允许重复元素，有序存储,并且按照元素升序排序，不允许存放null。
public class TreeSet1 {
    public static void main(String[] args) {
        Set<String> set=new TreeSet<>();
        set.add("Z");
        set.add("B");
        set.add("C");
        //set.add(null);//NullPointerException
        System.out.println(set);//[B, C, Z]
    }
}
