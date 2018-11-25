package CODE.链表;

class Mylink2 {
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
        ListNode head1 = l1;
        ListNode head2 = l2;
        //l1存的是0
        if (head1.val == 0 && head1.next == null)
            return l2;
        //l2存的是0
        if (head2.val == 0 && head2.next == null)
            return l1;
        //接下来2个数字都不为0
        long num1 = 0;
        long flag = 1;
        while (head1 != null) {
            num1 += head1.val * flag;
            flag *= 10;
            head1 = head1.next;
        }
        long num2 = 0;
        flag = 1L;
        while (head2 != null) {
            num2 += head2.val * flag;
            flag *= 10;
            head2 = head2.next;
        }
        long sum = num1 + num2;
        //获取到sum的每一位（从低位到高位）
        int[] bit = new int[32];
        int i = 0;
        while (sum > 0) {
            bit[i] =(int) (sum % 10);
            sum = sum / 10;
            i++;
        }
        int counts = i; //一共有counts位
        i = 0;
        //将每一位进行尾插
        ListNode newnode = null;
        ListNode cur = newnode;
        while (counts > 0) {
            ListNode node = new ListNode();
            node.val = bit[i];
            node.next = null;
            i++;

            if (newnode == null) {
                newnode = node;
                cur = newnode;
            } else {
                cur.next = node;
                cur = node;
            }
            counts--;
        }
        if (cur != null)
            cur.next = null;
        return newnode;
    }

}
public class Add
{
    public static void main(String[] args) {
        Mylink2 l1 = new Mylink2();
        l1.add(9);


        Mylink2 l2 = new Mylink2();
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
