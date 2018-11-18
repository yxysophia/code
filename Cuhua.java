package CODE.多线程;

/*
锁粗化是将多次连接在一起的加锁解锁操作合并为一次操作。将多个连续的锁扩展为一个更大的锁。
比如下列的调用append方法，由于append是同步方法，
即每次调用都需要加锁解锁操作，但是编译器检测到有连续的加锁解锁就会在第一个append处加锁，在最后一个append解锁:
 */
public class Cuhua
{
    static StringBuffer str=new StringBuffer();
    public static void main(String[] args) {
        str.append("a");
        str.append("b");
        str.append("c");
        System.out.println(str); //abc
    }
}


/*
删除不必要的加锁操作。
根据代码逃逸技术，如果判断一段代码中，堆上的数据不会逃逸出当前线程，则认为此代码是线程安全的，无需加锁
 */
//public class Cuhua
//{
//    public static void main(String[] args) {
//        StringBuffer str=new StringBuffer();
//        str.append("a").append("b");
//        System.out.println(str);
//    }
//}


