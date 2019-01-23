package CODE.Socket聊天室;


import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

//多线程的服务器
//需要接收多个连接
public class MuliThreadServer {
    //用ConcurrentHashMap是为了保证线程安全,存储每个连接的客户端
    private static Map<String,Socket> clientMap=new ConcurrentHashMap<>();

    //具体执行与每个客户端的通信  内部类，
    private static class RealExcuteClient  implements Runnable
    {
        private Socket client;

        public RealExcuteClient(Socket client) {
            this.client = client;
        }

        @Override
        public void run() {
            String msgFromClient="";
            try {
                Scanner in=new Scanner(client.getInputStream());  //获取客户端输入流
                while(true)
                {
                    if(in.hasNext())
                    {
                        msgFromClient=in.nextLine();
                        //由于在Windows在\r\n是换行，所以需要消除自带的\r，用" "替换掉
                        Pattern pattern=Pattern.compile("\r"); //表示识别"\r"的格式
                        Matcher matcher=pattern.matcher(msgFromClient); //msgFromClient是否有\r
                        //若有
                        msgFromClient=matcher.replaceAll(" ");

                        //注册：将连接的客户端添加到Map集合中
                        if(msgFromClient.startsWith("userName"))
                        {
                            String name=msgFromClient.split(":")[1];
                            if(addClientToMap(name,client))
                                continue;
                            else
                                break; //该客户端注册失败
                        }

                        //Group代表群聊，comment是内容，Group:comment
                        if(msgFromClient.startsWith("Group")){
                            String comment=msgFromClient.split(":")[1];
                            groupChat(comment);
                            continue;
                        }

                        //private代表私聊，name代表私聊对象，comment代表私聊的内容  private:name-comment
                        if(msgFromClient.startsWith("Private"))
                        {
                            String name=msgFromClient.split(":")[1].split("-")[0];
                            String comment=msgFromClient.split(":")[1].split("-")[1];
                            privateChat(name,comment);
                                continue;
                        }

                        //用户下线，从Map集合中删除该信息   用户名：内容
                        if(msgFromClient.contains("再见，下次再聊"))
                        {
                            String name=msgFromClient.split(":")[0];
                            quitChat(name);
                            break;  //客户端自己会将连接关闭
                        }

                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            }

        }

        //注册
        public static  boolean addClientToMap(String name,Socket client)
        {
            //判断用户名是否已经存在
            if(clientMap.get(name)!=null || client.isClosed())
            {
                System.out.println("用户名已经存在或连接已关闭，注册失败");
                return false;
            }
            clientMap.put(name,client);
            System.out.println("客户端"+name+"已经进入嗨聊空间");
            System.out.println("客户端注册成功，"+"当前嗨聊空间人数为："+clientMap.size());
            try {
                PrintStream out=new PrintStream(client.getOutputStream());
                out.println(name+"注册成功");
            } catch (IOException e) {
                e.printStackTrace();
            }
            return true;
        }

        //群聊
        public static void groupChat(String comment)
        {
            //将Map集合变为Set集合
            Set<Map.Entry<String,Socket>> clientSet=clientMap.entrySet();
            for(Map.Entry<String,Socket> entry:clientSet)
            {
                //取得每一个客户端的socket
                Socket sigClient=entry.getValue();
                try {
                    PrintStream outToClient=new PrintStream(sigClient.getOutputStream());
                    outToClient.println(comment);
                } catch (IOException e) {
                    System.out.println("群聊异常，错误为："+e);
                }
            }
        }

        //私聊
        public static void privateChat(String name,String comment)
        {
            Socket privateClient=clientMap.get(name);  //获取对应的客户端socket
            if(privateClient==null)
                System.out.println("私聊失败，私聊对象不存在");
            else{
                try {
                    PrintStream privateOut=new PrintStream(privateClient.getOutputStream());
                    privateOut.println(comment);
                } catch (IOException e) {
                    System.out.println("私聊异常，错误为："+e);
                }
            }
        }

        //用户下线
        public static void quitChat(String name)
        {
            System.out.println(name+"下线");
            clientMap.remove(name);
            System.out.println("当前嗨聊空间人数为："+clientMap.size());
        }
    }

    public static void main(String[] args) {
        try {
            //建立基站
            ServerSocket serverSocket=new ServerSocket(9999);
            //线程池，也就是最多允许15个客户端连接服务器
            ExecutorService executorService= Executors.newFixedThreadPool(15);
            for(int i=0;i<15;i++)
            {
                System.out.println("等待客户端连接");
                //返回的是连接的客户端信息
                Socket client=serverSocket.accept();
                System.out.println("有新的客户端连接,客户端端口号为"+client.getPort());
                executorService.submit(new RealExcuteClient(client));
            }
            executorService.shutdown();
            serverSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
