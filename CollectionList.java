package CODE.类集;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class CollectionList {
    public static void main(String[] args) {
        List<String> list=new ArrayList<>();
        list.add("hello");
        list.add("pick");
        list.add("health");
        //可以添加重复数据
        list.add("pick");
        System.out.println(list.contains("pick")); //true
        list.remove("pick");
        list.set(0,"hai");
        for(int i=0;i<list.size();i++)
        {
            System.out.println(list.get(i));  //hai health pick
        }
    }
}
