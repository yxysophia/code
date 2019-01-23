package CODE.Socket聊天室;

//多线程客户端  发送和读取是并行
//读和写是2个线程，但是是一个socket，通过构造

import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Scanner;

//关闭socket是写线程关闭，读线程只读
class ReadFromServer implements  Runnable
{
    //读线程
    private Socket client;
    public ReadFromServer(Socket client)
    {
        this.client=client;
    }

    @Override
    public void run() {
        //获取输入流来取得服务器发来的信息
        try {
            Scanner in=new Scanner(client.getInputStream());
            while(true)
            {
                if(client.isClosed())
                {
                    System.out.println("客户端已关闭");
                    in.close();
                    break;
                }
                else if(in.hasNext())
                {
                    String msgFromServer=in.nextLine();
                    System.out.println(msgFromServer);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

//写线程
class WriteToServer implements Runnable
{
    private Socket client;

    public WriteToServer(Socket client) {
        this.client = client;
    }

    @Override
    public void run() {
        //从键盘获取标准输入
        Scanner in=new Scanner(System.in);
        PrintStream clientOut= null;
        try {
            clientOut = new PrintStream(client.getOutputStream(),true,"UTF-8");
            while(true)
            {
                System.out.println("请输入向服务端发送的信息(请先注册您的信息[如：userName:1]");
                //获取向服务端发送的信息
                String msgToServer="";
                if(in.hasNext())
                {
                    msgToServer=in.nextLine();
                    //向服务端输出信息
                    clientOut.println(msgToServer);
                }

                if(msgToServer.contains("再见，下次再聊"))
                {
                    System.out.println("客户端"+client.getInetAddress()+"退出聊天室");
                    //客户端输出bye,关闭该客户端连接
                    clientOut.close();  //关闭输出流
                    in.close();
                    client.close();  //关闭socket，根据输入终止，
                    break;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
public class MultiThreadClient {
    public static void main(String[] args) {
        try {
            //1.建立连接
            Socket client=new Socket("127.0.0.1",9999);
            //2.启动读写线程，进行数据输入输出
            System.out.println("[注册:userName] [Group：内容] [Privte：私聊用户名-私聊内容] [用户名:内容（包含再见，下次再聊)]");
            Thread readThread=new Thread(new ReadFromServer(client));
            Thread writeThread=new Thread(new WriteToServer(client));
            readThread.start();
            writeThread.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
