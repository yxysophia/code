package CODE.Socket聊天室;


import Work.Exception.Ex;

import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

//单线程服务端
public class SingleThreadServer {
    public static void main(String[] args) throws Exception {
        //1.建立基站类
        ServerSocket serverSocket=new ServerSocket(9999);
        //2.等待客户端连接
        System.out.println("等待客户端连接ing");
        Socket client=serverSocket.accept();  //阻塞监听客户端连接
        //3.连接成功后，获取客户端输入输出流
        System.out.println("有新的客户端连接，客户端端口号为："+client.getPort());

        //客户端输出流
        PrintStream clientOut=new PrintStream(client.getOutputStream(),true,"UTF-8");
        clientOut.println("hello i am server");

        //客户端输入流
        Scanner clientInput=new Scanner(client.getInputStream());
        if(clientInput.hasNext())
        {
            System.out.println("客户端端口号为"+client.getPort()+"say："+clientInput.nextLine());
        }

        //4.关闭流
        clientInput.close(); //关闭客户端输入流
        clientOut.close();  //关闭客户端输出流
        serverSocket.close(); //关闭基站

    }

}
