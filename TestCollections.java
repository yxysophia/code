import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TestCollections {

    public static void main(String[] args) {
        List<String> list=new ArrayList<>();
        list.add("hello");
        //一次性向集合中添加元素
        Collections.addAll(list,"day","come","ok");
        System.out.println("原始顺序："+list);//原始顺序：[hello, day, come, ok]

        //将list乱序
        Collections.shuffle(list);
        System.out.println("乱序后结果:"+list); //乱序后结果:[day, ok, hello, come]

         //将list反转
        Collections.reverse(list);
        System.out.println("反转后结果："+list); //反转后结果：[ok, come, day, hello]

        //将list填充
        Collections.fill(list,"haha");
        System.out.println("填充后："+list); //填充后：[haha, haha, haha, haha]


        //将list变为线程安全的集合
        list=Collections.synchronizedList(list);

        //将集合变为不可变集合
        list=Collections.unmodifiableList(list);
        list.add("en");//UnsupportedOperationException 此时，集合不可修改
    }
}
