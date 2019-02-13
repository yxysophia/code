import java.io.*;
import java.util.Properties;

////读取文件属性信息
//public class Testproperties {
//    public static void main(String[] args) {
//        Properties properties=new Properties();
//
//        //通过文件属性读取内容
//
//        //加载属性文件中的内容--load
//        //第一种方法：文件路径用绝对路径
//        File file=new File("D:\\VScode\\code\\src\\CODE\\栈队列\\src\\Test.properties");
//        try {
//            FileReader fileReader=new FileReader(file);
//            properties.load(fileReader);
//        } catch (Exception e) {
//            e.printStackTrace();
//        }
//
//        //第二种方法：文件路径用classpath路径---加载classpath中的文件，因为properties文件被加载后在class文件中
//        InputStream inputStream=Testproperties.class.getClassLoader().getResourceAsStream("Test.properties");
//        try {
//            properties.load(inputStream);
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//
//
//        //读取属性信息--getProperty
//        System.out.println(properties.getProperty("1"));//happy day!
//        System.out.println(properties.getProperty("5","believe")); //5 没有，默认为believe
//        //在getProperty里设置的value不会对properties对象产生影响
//
//        System.out.println(properties);
//        //{3=everything will be ok!, 2=come on!, 1=happy day!}
//    }
//}


//保存属性信息写到属性文件
public class Testproperties {
    public static void main(String[] args) {
        Properties properties=new Properties();
        properties.setProperty("1","hello sun");
        properties.setProperty("2","hello tree");
        File file=new File("D:\\VScode\\code\\src\\CODE\\栈队列\\src\\Test2.properties");
        try {
            FileWriter fileWriter=new FileWriter(file);
            properties.store(fileWriter,"将信息写入属性文件");
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println(properties);//{2=hello tree, 1=hello sun}
    }
}

