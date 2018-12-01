package CODE.IO;

import java.io.*;

public class Stream {
    public static void main(String[] args) throws IOException {
        File file=new File("C:"+File.separator+"Users"+File.separator+"lenovo"+
                File.separator+"Desktop"+File.separator+"java.txt");
        if(!file.exists())
        {
            try {
                file.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        OutputStream out=null;
        try {
            out=new FileOutputStream(file,true);
            String msg="hello pick\r\n";
            out.write(msg.getBytes());
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }finally {
            out.close();
        }


    }
}
