package CODE;

class Node
{
    private Object data;
    private Node next;

    public Node(Object data) {
        this.data = data;
    }

    public Object getData() {
        return data;
    }

    public Node getNext() {
        return next;
    }

    public void setData(Object data) {
        this.data = data;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}
public class Link
{
    public static void main(String[] args)
    {
        Node head=new Node("火车头");
        Node first1=new Node("车厢1");
        Node first2=new Node("车厢2");
        Node tail=new Node("车尾");
        head.setNext(first1);
        first1.setNext(first2);
        first2.setNext(tail);
        print(head);
    }
    public static  void print(Node node)
    {
        if(node==null)
            return ;
        System.out.println(node.getData());
        node=node.getNext();
        print(node);
    }
}
