package CODE.Socket聊天室;


import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Scanner;

//单线程客户端
//1.建立连接
//2.进行数据输入输出
public class SingleTreadClient {
    public static void main(String[] args) {
        try {
            //1.建立连接
            Socket client=new Socket("127.0.0.1",9999);
            //2.进行数据输入输出
            //客户端首先进行从服务器的数据读
            Scanner clientInput=new Scanner(client.getInputStream());
            if(clientInput.hasNext())
            {
                System.out.println("服务器say:"+clientInput.nextLine());
            }

            //客户端进行数据输出,但是先从键盘获取标准输入
            System.out.println("请输入向服务器发送的消息");
            Scanner in=new Scanner(System.in);
            String str="";
            if(in.hasNext())
            {
                str=in.nextLine();
            }
            //向服务器输出
            PrintStream clientOut=new PrintStream(client.getOutputStream(),true,"UTF-8");
            clientOut.println(str);

            //3.关闭流
            clientInput.close();
            in.close();
            clientOut.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
