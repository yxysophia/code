import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

//进队列 public boolean add()
//出队列 public E poll()
//注意：队列是一个接口，需要用子类实现

//如果Queue没有元素，返回null，而栈会有异常
public class TestQueue {
    public static void main(String[] args) {
        //Queue是接口
        Queue<String> queue=new LinkedList<>();

        //进队列
        queue.add("happy");
        queue.add("share");
        queue.add("insist");
        queue.add("amzing");
        //出队列
        System.out.println(queue.poll()); //happy
        //观察队头
        System.out.println(queue.peek()); //share

        //遍历队列
        while(!queue.isEmpty())
        {
            System.out.print(queue.poll()+"->"); //share->insist->amzing->null (null为下一个语句结果)
        }
        System.out.println(queue.peek());  //如果队列没有元素，将会返回null

        //遍历队列使用迭代器----迭代器遍历顺序和元素放入顺序一样，队列先进先出，可以使用迭代器
        Iterator<String> iterator=queue.iterator(); //取得队列的迭代器
        while(iterator.hasNext())
        {
            System.out.print(iterator.next()+"->"); //share->insist->amzing->
        }
    }
}
