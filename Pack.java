//包的定义：
package www.code;
import www.code.me.Message;  //包的导入

public class Pack extends Message 
{
    public static void main(String[] args)
    {
        Message message =new Message();
        message.func(); //Message类
        System.out.println(new Pack().age); //10  在不同包的子类中访问protected权限
    }
}