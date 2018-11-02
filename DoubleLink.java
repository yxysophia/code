package CODE;


import javafx.beans.binding.ObjectBinding;
import jdk.nashorn.internal.ir.UnaryNode;
import org.omg.CORBA.OBJ_ADAPTER;

import javax.management.ObjectName;

////双向链表
interface Ilink
{
    boolean add(Object data); //添加
    boolean remove(Object data);  //删除数据为data的结点
    void printLink();  //遍历该链表
    int size();  //结点个数
    Object set(int index ,Object newdata);// 把索引index所在位置元素替换为newdata,返回原来数据
    int contains(Object data);//判断data是否在链表中
    Object get(int index);//根据下标返回结点内容
    void clear();//销毁
    Object[] toArray();//将链表转为数组
}
class LinkImpl implements Ilink
{
    private Node head;//头结点
    private Node tail; //尾结点
    private int size; //结点个数

    private class Node  //定义为内部类是一种封装
            //将每个结点定义为私有内部类，目的内部类和外部类可以访问彼此的私有属性，而且客户端不知道每个结点具体情况，
    {
        Node prev;
        private Object data;
        Node next;
        public Node(Node prev, Object data,Node next)  //结点的构造方法
        {
            this.prev=prev;
            this.data=data;
            this.next=next;
        }
    }
    public boolean add(Object data)
    {
        //利用尾插
        Node prev=this.tail;
        Node newnode=new Node(this.tail,data,null);
        if(this.head==null)  //第一次插入时头为为空，将头尾都指向newnode
            this.head=newnode;
        else
        {
            prev.next=newnode;
        }
        this.tail=newnode;
        this.size++;
        return true;
    }
    public boolean remove(Object data)
    {
        if(data==null)   //很有可能这个节点数据为null,但是对于数据不是null的节点，比较用的是equals,所以需要分开判断
        {
            for (Node tmp = head; tmp != null; tmp = tmp.next)
            {
                if(tmp.data==null)  //找到该节点
                {
                    if(Unlink(tmp))  //删除该节点
                        return true;
                }
            }
            return false;
        }
        else {
            for (Node tmp = head; tmp != null; tmp = tmp.next) {
                if (data.equals(tmp.data)) {
                    if (Unlink(tmp))
                        return true;
                }
            }
            return false;
        }
    }
    public Object set(int index, Object newdata)  //替换数据
    {
        if(isIndex(index))  //首先下标是合法的
        {
            Node tmp=getNode(index);
            Object olddata=tmp.data;
            tmp.data=newdata;
            return olddata;
        }
        return null;
    }
    public int contains(Object data)
    {
        if(data==null)
        {
            int i=0;
            for(Node tmp=head;tmp!=null;tmp=tmp.next) {
                if (tmp.data == null)
                    return i;
                else
                    i++;
            }
        }
        else
        {
            int i=0;
            for(Node tmp=head;tmp!=null;tmp=tmp.next)
            {
                if(data.equals(tmp.data))
                    return i;
                else
                    i++;
            }
        }
        return -1;
    }
    private boolean Unlink(Node node)//删除node结点
    {
        Node prev=node.prev;
        Node next=node.next;
        if(prev==null)
        {
            this.head=next;
            //head.prev=null;  //不能有该语句，如果next为空
        }
        else
        {
            prev.next=next;
            node.prev=null;  //相当于清除该节点的prev
        }
        if(next==null)  //删除尾结点
        {
            this.tail=prev;
        }
        else
        {
            next.prev=prev;
            node.next=null;  //相当于清除该节点的next
        }
        node.data=null; //将该节点数据置空
        this.size--;
        return true;
    }
    public  Object get(int index)  //返回索引为index的数据
    {
        if(isIndex(index))
        {
            Node tmp=getNode(index);
            return tmp.data;
        }
        System.out.println("下标不合法");
        return null;
    }
    public void printLink()  //遍历链表
    {
        for(Node tmp=head;tmp!=null;tmp=tmp.next)
        {
            System.out.println(tmp.data);
        }


    }
    public void clear()  //销毁链表
    {
        for(Node tmp=head;tmp!=null;)
        {
            Node next=tmp.next;
            tmp.next=null;
            tmp.prev=null;
            tmp.data=null;
            tmp=null;
            tmp=next;
            size--;
        }
        head=tail=null;
    }
    public int size()
    {
        return size;
    }
    public Object[] toArray()  //将链表转为数组
    {
        if(size!=0)
        {
            Object[] linkArray=new Object[this.size];
            int index=0;
            for(Node tmp=head;tmp!=null;tmp=tmp.next)
            {
                linkArray[index]=tmp.data;
                index++;
            }
            return linkArray;
        }

        return null;
    }
    private boolean isIndex(int index)  //判断下标是否合法
    {
        return index>=0 && index<size;
    }
    private Node getNode(int index)  //返回下标所在的结点
    {
        if(index<size/2)  //元素的一半，从head向尾找
        {
            Node start=head;
            for(int i=0;i<index;i++)
            {
                start=start.next;
            }
            return start;
        }
        else
        {
            Node end=tail;
            for(int i=size-1;i>index;i--)
            {
                end=end.prev;
            }
            return end;
        }
    }
}
class factory   //一个工厂专门生产对象，这样在客户端就不用new对象
{
    public static LinkImpl getLink()
    {
        return new LinkImpl();
    }
}
public class DoubleLink
{
    public static void main(String[] args)
    {
        Ilink l=factory.getLink();
        l.add("pick");
        l.add("hello");
        l.add(null);
        System.out.println(l.set(2,19));
        l.printLink();
        System.out.println("*************"+l.size());
        l.remove("pick");
        l.remove(null);
        l.printLink();
        System.out.println(l.get(1));
        System.out.println("*************");
        l.clear();
        l.printLink();
        System.out.println(l.size());
    }
}
