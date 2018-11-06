package CODE.泛型;

////删除一个有序链表的所有重复结点，重复结点不保留(1->2->3->3->4->4->5  删除后1—>2->5)
class Mylink
{
    private ListNode head;
    class ListNode
    {
        private int val;
        private ListNode next;
    }
    public void add(int val)
    {
        if(head==null)
        {
            head=new ListNode();
            head.val=val;
            head.next=null;
        }
        else
        {
            ListNode tail=head;
            while(tail.next!=null)
            {
                tail=tail.next;
            }
            ListNode newnode=new ListNode();
            newnode.val=val;
            newnode.next=null;
            tail.next=newnode;
            tail=newnode;
        }
    }
    public ListNode deleteDuplication(ListNode pHead) {
        //如果只有一个结点或者2和结点，直接返回
        if (pHead == null || pHead.next == null) {
            return pHead;
        }
        ///防止将头结点直接删除第一个结点，重新new一个头结点，这个头结点指向第一个结点，返回的是头结点.next
        ListNode Head = new ListNode();
        Head.next = pHead;
        ListNode prev = Head, cur = pHead, next = pHead.next;
        ////prev  cur   next
        while (next != null) {
            if (next!=null && cur.val == next.val ) {
                ///如果当前结点和下一个结点数据相等，当前结点和下一个结点分别向后移，直至找到当前结点和下一个结点不相等，将prev指向下一个结点
                ////比如 2 2  2  4  prev(Head)指向4
                while (next!=null&& cur.val == next.val ) {
                    cur = next;
                    next = next.next;
                }
                prev.next = next;
                cur = next;
                if (next != null)
                    next = next.next;
                else   //next为空，直接返回
                    return Head.next;
            } else {
                //不相等 prev  cur next 分别向后移
                prev = cur;
                cur = next;
                next = next.next;
            }
        }
        return Head.next;
    }

    public void print()
    {
        ListNode cur=head;
        while(cur!=null)
        {
            System.out.println(cur.val);
            cur=cur.next;
        }
    }
    public void print1()
    {
        deleteDuplication(head);
        print();
    }

}
public class link
{
    public static void main(String[] args) {
        Mylink l1=new Mylink();
        l1.add(1);
        l1.add(1);
        l1.add(1);
        l1.add(1);
        l1.print1();
    }

}