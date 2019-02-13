
//入栈 public E push(E item)
//出栈 public synchronized E pop()
//观察栈顶元素 public synchronized E peek()

import java.util.Stack;

public class TestStack {
    public static void main(String[] args) {
        Stack<String> stack=new Stack<>();

        //进栈
        stack.push("happy");
        stack.push("share");
        stack.push("insist");
        stack.push("amazing");
        //出栈
        System.out.println(stack.pop()); //amazing

        //观察栈顶元素
        System.out.println(stack.peek());//insist

        //遍历栈
        while(!stack.isEmpty())
        {
            System.out.print(stack.pop()+"<-"); //insist<-share<-happy<-
        }
    }
}
