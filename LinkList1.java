package CODE.类集;

import java.util.LinkedList;
import java.util.List;
import java.util.Vector;

public class LinkList1 {
    public static void main(String[] args) {
        List<String> list=new LinkedList<>();
        list.add("hai");
        list.add("pick");
        list.add("health");
        System.out.println(list);//[hai, pick, health]
        list.remove("pick");
        list.set(0,"hello");
        for(int i=0;i<list.size();i++)
        {
            System.out.println(list.get(i)); //hello health
        }
    }
}
