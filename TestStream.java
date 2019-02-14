package StreamDemo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

//public class TestStream {
//    public static void main(String[] args) {
//        List<String> list=new ArrayList<>();
//        Collections.addAll(list,"ha","hahaba","hai","hello");
//        //注意：对stream进行操作方法的返回值不是流的是终结方法
//
//        //1.计算list中以ha开头的字符串次数
//        System.out.println(list.stream().filter(s->s.startsWith("ha")).count()); // 3  最后一次性计算次数
//        //2.将以ha开头的字符串进行收集
//        List<String> newList=list.stream().filter(s->s.startsWith("ha")).collect(Collectors.toList());
//        System.out.println(newList); //[ha, hahaba, hai]
//
//        //3.判断list是否全部以ha开头
//        System.out.println(list.stream().allMatch(s->s.startsWith("ha")));  //false
//
//        //4.判断list中是否有元素以ha开头
//        System.out.println(list.stream().anyMatch(s->s.startsWith("ha")));  //true
//
//    }
//}


public class TestStream {
    public static void main(String[] args) {
        List<String> list=new ArrayList<>();
        Collections.addAll(list,"1.ha","2.hahaba","3.hai","4.hello",
                "5.amazing","6.come","7.run");

        //1.跳过0个，取4个数据，然后进行收集
        System.out.println(list.stream().skip(0).limit(4).collect(Collectors.toList()));
        //[1.ha, 2.hahaba, 3.hai, 4.hello]

        //2.跳过5个，取4个数据，然后进行收集
        System.out.println(list.stream().skip(5).limit(4).collect(Collectors.toList()));
        //[6.come, 7.run]

        //先将元素里包含ha筛选出来然后跳过一个，取两个元素进行收集
        System.out.println(list.stream().filter(s->s.contains("ha")).skip(1).limit(2).
                collect(Collectors.toList())); //[2.hahaba, 3.hai]

        //先将元素跳过1个取10个元素出来进行筛选收集
        System.out.println(list.stream().skip(2).limit(10).filter(s->s.contains("ha")).collect(Collectors.toList()));
        //[3.hai]
    }
}
