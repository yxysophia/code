package CODE.迭代器;

import com.sun.org.apache.xml.internal.utils.ListingErrorHandler;

import java.util.*;

//public class Iterator1 {
//    public static void main(String[] args) {
//        List<String> list=new ArrayList<>();
//        list.add("pick");
//        list.add("happy");
//        //取得ArrayList的迭代器
//        ListIterator<String> listiterator=list.listIterator();
//        while(listiterator.hasNext())
//        {
//            System.out.println(listiterator.next());  //pick  happy
//        }
//
//        while (listiterator.hasPrevious())
//        {
//            System.out.println(listiterator.previous());//happy pick
//        }
//    }
//}

//Enumeration
//public class Iterator1 {
//    public static void main(String[] args) {
//        Vector<String> vector=new Vector<>();
//        vector.add("pick");
//        vector.add("happy");
//        //取得ArrayList的迭代器
//        Enumeration<String> enumeration=vector.elements();
//        while(enumeration.hasMoreElements())
//        {
//            System.out.println(enumeration.nextElement());  //pick  happy
//        }
//    }
//}

//ConcurrentModificationException异常
public class Iterator1 {
    public static void main(String[] args) {
        List<String> list=new ArrayList<>();
        Collections.addAll(list,"A","B","C","D","B","a");
        //此时modCount=6
        Iterator<String> iterator=list.iterator();
        //此时调用list.iterator()，取得集合迭代器，expectedModCount =modCount=6
        while(iterator.hasNext())
        {
            //下一次循环调next方法，会调用checkForComodification判断副本的expectedModCount 和集合的modCount是否相等，
            // 不相等抛异常
            String str=iterator.next();
            if(str.equals("B")) {
                list.remove("B"); //使用list.remove发生异常
                //调用list.remove(),modCount=7，然后进行下一次循环
                iterator.remove();
                continue;
            }
            System.out.println(str); // A C D a
        }
    }
}
