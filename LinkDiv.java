package CODE.链表;

import java.util.ArrayList;

//class Node
//{
//    private Object data;
//    private Node next;
//
//    public Node(Object data) {
//        this.data = data;
//    }
//
//    public Object getData() {
//        return data;
//    }
//
//    public Node getNext() {
//        return next;
//    }
//
//    public void setData(Object data) {
//        this.data = data;
//    }
//
//    public void setNext(Node next) {
//        this.next = next;
//    }
//}
class Mylink
{
    private Node head;
    class Node
    {
        private int val;
        private Node next;
    }
    public void add(int val)
    {
        if(head==null)
        {
            head=new Node();
            head.val=val;
            head.next=null;
        }
         else
        {
            Node tail=head;
            while(tail.next!=null)
            {
                tail=tail.next;
            }
            Node newnode=new Node();
            newnode.val=val;
            newnode.next=null;
            tail.next=newnode;
            tail=newnode;
        }
    }
    public void print()
    {
        Node cur=head;
        while(cur!=null)
        {
            System.out.println(cur.val);
            cur=cur.next;
        }
    }
    ////以给定值x为标准，将链表分为2个部分，所有小于x的结点排在大于或等于x结点前，不能改变原有数据的顺序
    public Node partition(Node pHead, int x) {
        //将原链表分为两个集合

        ArrayList<Integer> l1=new ArrayList<>();  //动态整型数组
        ArrayList<Integer> l2=new ArrayList<>();
        Node cur=pHead;
        while(cur!=null)
        {
            if(cur.val<x)
                l1.add(cur.val);  //小的元素方l1集合
            else
                l2.add(cur.val);  //大的元素方l2集合
            cur=cur.next;
        }
        int length1=l1.size();
        int length2=l2.size();
        int flag=0;
        if(length1!=0)
        {
            pHead.val=l1.get(0);
        }
        else {
            pHead.val = l2.get(0);
            flag = 1;
        }

        cur=pHead.next;

        for(int i=1;i<length1;i++)
        {
            cur.val=l1.get(i);
            cur=cur.next;
        }
        int i=0;
        if(flag==1)
        {
            i =1;
        }
        for(;i<length2;i++)
        {
            cur.val=l2.get(i);
            cur=cur.next;
        }
        return pHead;
    }
    public void print1()
    {
        partition(head,3);
        print();
    }
}
public class LinkDiv
{
    public static void main(String[] args)
  {
          Mylink l=new Mylink();
          l.add(3);
          l.add(3);
          l.add(3);
          l.print1();
//        Node head=new Node("世界");
//        Node first1=new Node("pick");
//        Node first2=new Node(1019);
//        Node tail=new Node("happy");
//        head.setNext(first1);  //在主类中进行链表的链接和插入
//        first1.setNext(first2);
//        first2.setNext(tail);
//        print(head);
    }

}
