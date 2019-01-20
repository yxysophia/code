package CODE.Map1;

import CODE.JavaIo.In;

import java.util.*;

//HashMap
public class HashMap1 {
    public static void main(String[] args) {
        HashMap<Integer, String> map = new HashMap<>();
        map.put(2, "sophia");
        map.put(1, "pick");
        map.put(null, null);
        map.put(null, "happy");
        System.out.println(map); //{null=happy, 1=pick, 2=sophia}

        //通过key获取value
        System.out.println("key=1 value=" + map.get(1));
        System.out.println("key=null value=" + map.get(null)); //不允许重复，将值覆盖

        //获取key
        Set<Integer> set = map.keySet();
        System.out.println("所有的key:" + set); //所有的key:[null, 1, 2]

        //获取value
        Collection<String> list = map.values();
        System.out.println("所有的value"+list); //所有的value[happy, pick, sophia]

        //遍历map
        Set<Map.Entry<Integer, String>> entrySet = map.entrySet();
        //方法一：取得entrySet的迭代器
        Iterator<Map.Entry<Integer,String>> iterator=entrySet.iterator();
        while(iterator.hasNext())
        {
            Map.Entry<Integer,String> entry=iterator.next();
            System.out.println(entry.getValue()+"="+entry.getKey()); //happy=null  pick=1  sophia=2
        }
        //方法2：for-each输出
        for (Map.Entry<Integer, String> entry : entrySet)
        {
            System.out.println(entry.getKey()+"->"+entry.getValue()); //null->happy   1->pick  2->sophia
        }

          //方法3：for循环输出
        for(Integer key:map.keySet())
        {
            System.out.println(key+"="+map.get(key));  //null=happy  1=pick 2=sophia
        }
    }
}
