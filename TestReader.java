import java.io.*;

public class TestReader {
    public static void main(String[] args) {
        File file=new File("C:"+File.separator+"Users"+
                File.separator+"lenovo"+File.separator+"Desktop"+File.separator+"java.txt");
        try {
            Writer writer=new FileWriter(file);

            writer.write("2.0");  //可以直接传入字符串
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            Reader reader=new FileReader(file);
            char[] chars=new char[1024];
            try {
                int len=reader.read(chars);
                System.out.println(new String(chars,0,len));
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }


    }
}
