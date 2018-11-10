package CODE.链表;

import java.util.ArrayList;


class Mylink1
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
    public Node swapPairs(Node head)
    {
        //空节点或只有一个结点直接返回
        if(head==null||head.next==null)
            return head;
        //定义三个变量
        Node cur=head;
        Node next1=head.next;
        Node next2=next1.next;
        //只有2个结点，将2个结点交换并且将head指向原本的next
        if(next2==null)
        {
            next1.next=cur;
            cur.next=null;
            head=next1;
            return head;
        }
        ////现在至少有三个结点，比如1 2 3 需要将head指向2,否则head一直指向1，那么新链表里没有2结点
        head=next1;
        ///// 1  2     3      4
        /////cur next1 next2
        /////将2.next=1;
        ///// 2      1      3       4
        /////      prev    cur     next1  此时2.next=1,1.next=3,但是需要将1指向4
        ///// 2   1      3      4  null
        //////          prev        cur(next2)
        while(next1!=null)
        {
            next2=next1.next;
            next1.next=cur;
            Node prev=cur;  //因此此时cur.next

            cur=next2; //因此此时cue和next1已经交换，需要交换是next2后面结点
            if(cur==null)
            {
                prev.next=null;
                return head;
            }

            next1=cur.next;
            if(next1==null)   //在这里需要判断是因为 1 2 3 ，2指向1，next1=null,1直接指向3，如果是1 2 3 4  ，next1=4,1指向4
            {
                prev.next=next2;
            }
            else
              prev.next=next1;
        }
        return head;
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

    public void print2()
    {
        swapPairs(head);
        print();
    }
}
public class Swap
{
    public static void main(String[] args) {
        Mylink1 l = new Mylink1();
        l.add(1);
        l.add(2);
       l.add(3);
//        l.add(4);
        l.print2();
    }

}
