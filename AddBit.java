package CODE.链表;


class Mylink3 {
    public ListNode head;

    class ListNode {
        private int val;
        private ListNode next;
    }

    public void add(int val) {
        if (head == null) {
            head = new ListNode();
            head.val = val;
            head.next = null;
        } else {
            ListNode tail = head;
            while (tail.next != null) {
                tail = tail.next;
            }
            ListNode newnode = new ListNode();
            newnode.val = val;
            newnode.next = null;
            tail.next = newnode;
            tail = newnode;
        }
    }

    public void print() {
        ListNode cur = head;
        while (cur != null) {
            System.out.println(cur.val);
            cur = cur.next;
        }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode cur1 = l1;
        ListNode cur2 = l2;
        //l1存的是0
        if (cur1.val == 0 && cur1.next == null)
            return l2;
        //l2存的是0
        if (cur2.val == 0 && cur2.next == null)
            return l1;
        int[] bit = new int[100]; //存储2个链表每位相加和
        int i = 0;
        int flag = 0;   //进位值
        while (cur1 != null && cur2 != null) {
            int sum = 0;
            sum = cur1.val + cur2.val + flag;
            if (sum > 9)  //这时需要进位
            {
                bit[i] = sum % 10;
                flag = 1;
            } else {
                bit[i] = sum;
                flag = 0;
            }
            cur1 = cur1.next;
            cur2 = cur2.next;
            i++;
        }
        //cue1!=null,即cur2=null,将链表1的值放在数组里，但要考虑之前的进位，
        // 如链表1:1   链表2 ：9 9  1+9为10，需要进位
        while (cur1 != null) {
            int sum = cur1.val + flag;
            if (sum > 9) {
                bit[i] = sum % 10;
                flag = 1;
            } else {
                bit[i] = sum;
                flag = 0;
            }
            i++;
            cur1 = cur1.next;
        }
        while (cur2 != null) {
            int sum = cur2.val + flag;
            if (sum > 9) {
                bit[i] = sum % 10;
                flag = 1;
            } else {
                bit[i] = sum;
                flag = 0;
            }
            i++;
            cur2 = cur2.next;
        }
        //包含cur1=null且cur2=null或者cur1=null或者cur2=null需要进位的情况
        if (flag == 1) {
            bit[i] = 1;
            i++;
        }
        int counts = i;
        i = 0;
        //将bit数组里元素尾插到一个新链表
        ListNode newnode = null;
        ListNode cur = newnode;
        while (counts > 0) {
            ListNode node = new ListNode();
            node.val=bit[i];
            node.next = null;
            if (newnode == null)  //第一次插入
            {
                newnode = cur = node;
            } else {
                cur.next = node;
                cur = node;
            }
            i++;
            counts--;
        }
        return newnode;
    }

}
public class AddBit
{
    public static void main(String[] args) {
        Mylink3 l1 = new Mylink3();
        l1.add(9);


        Mylink3 l2 = new Mylink3();
        l2.add(1);
        l2.add(9);
        l2.add(9);
        l2.add(9);
        l2.add(9);
        l2.add(9);
        l2.add(9);
        l2.add(9);
        l2.add(9);
        l2.add(9);
        l1.addTwoNumbers(l1.head,l2.head);


    }

}
