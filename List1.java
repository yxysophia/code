package CODE.集合类;

import java.util.ArrayList;
import java.util.List;

//list中存放JDK内置对象
public class List1 {
    public static void main(String[] args) {
        List<String> list=new ArrayList<>();
        list.add("pick");
        list.add("sophia");
        list.add("happy");
        list.set(2,"good");
        for(int i=0;i<list.size();i++)
        {
            System.out.println(list.get(i));
        }
        System.out.println(list.contains("pick"));
        System.out.println(list.remove(1)); //返回的是删除元素
    }
}
