package CODE.文档管理系统;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

//添加类
public class Add extends JFrame implements ActionListener {
    private JLabel lable1;  //标签1：文件名
    private JLabel lable2;  //标签2：作者
    private JLabel label3;  //标签3：文件大体内容

    private JTextField nameText; //文本框：输入文件名
    private JTextField authorText; //文本框：输入作者
    private JTextField contentText; //文本框：内容

    private JButton button;  //添加按钮

    public Add() {
        //设置添加窗口大小
        this.setSize(400, 200);
        this.setTitle("添加文档信息");
        this.setLayout(null);

        //放入文件名
        lable1 = new JLabel("文件名");
        lable1.setSize(50, 20);
        lable1.setLocation(100, 30);
        this.add(lable1);

        //放入出入文件名文本框
        nameText = new JTextField();
        nameText.setSize(100, 20);
        nameText.setLocation(145, 30);
        this.add(nameText);

        //放入作者标签
        lable2 = new JLabel("作者");
        lable2.setSize(50, 20);
        lable2.setLocation(115, 52);
        this.add(lable2);

        //放入输入作者文本框
        authorText = new JTextField();
        authorText.setSize(100, 20);
        authorText.setLocation(145, 52);
        this.add(authorText);

        //放入内容标签
        label3 = new JLabel("内容");
        label3.setSize(50, 20);
        label3.setLocation(115, 73);
        this.add(label3);

        //放入输入内容文本框
        contentText = new JTextField();
        contentText.setSize(100, 20);
        contentText.setLocation(145, 73);
        this.add(contentText);

        button = new JButton("添加");
        button.setSize(60, 20);
        button.setLocation(160, 110);
        button.addActionListener(this);
        this.add(button);


        this.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (isEmpty()) {
            JOptionPane.showMessageDialog(this, "文件名、作者或内容为空");
            clear();
            return ;
        }
        if (isError()) {
            JOptionPane.showMessageDialog(this, "文件名、或内容超出字符长度限制");
            clear();
            return ;
        }

        //添加信息
        StringBuffer info = new StringBuffer();
        info.append(nameText.getText().trim() + "、");
        info.append(authorText.getText().trim() + "、");
        info.append(contentText.getText().trim() );

        if (!addInfo(info.toString())) {
            JOptionPane.showMessageDialog(this, "添加失败,该文件已存在");
            clear();
        }
        else
        {
            JOptionPane.showMessageDialog(this, "添加成功");
            clear();
        }
    }

    //判断用户输入是否为空
    private boolean isEmpty() {
        if ("".equals(nameText.getText().trim()) || nameText.getText() == null) {
            return true;
        } else if ("".equals(authorText.getText().trim()) || authorText.getText() == null)
            return true;
        else if ("".equals(contentText.getText().trim()) || contentText.getText() == null)
            return true;
        return false;
    }

    private boolean isError() {
        //文件名长度不能超过10
        if (nameText.getText().length() > 10)
            return true;
        if (contentText.getText().length() > 20)
            return true;
        return false;
    }

    private void clear()
    {
        nameText.setText("");
        authorText.setText("");
        contentText.setText("");
    }

    //添加信息
    private boolean addInfo(String info) {
        String[] strs = info.split("、");
        //文件名存在，直接返回false
        if (nameExist(strs[0])) {
            return false;
        }
        //开始添加文件
        try {
            FileWriter fw=new FileWriter("d:\\info.txt",true);
            //创建一个文件的字符输出流，第二个参数表示是在文件尾进行追加
            BufferedWriter bw=new BufferedWriter(fw);
            //以上面创建的对象为参数创建一个缓冲字符输出流
            bw.newLine();
            bw.write(info);
            bw.close();;
            fw.close();
            //创建新的一行
        } catch (IOException e) {
            System.out.println("文件写错误");
        }
        return true;
    }

    /*
    判断文件名是否重复
     */
    private boolean nameExist(String nameText) {
        boolean result = false;
        try {
            FileReader fr = new FileReader("d:\\info.txt");
            //产生一个文件字符输入流对象
            BufferedReader br = new BufferedReader(fr);
            //以上一个对象作为参数来创建一个缓冲的字符输入流对象
            String[] str = br.readLine().split("、");
            while (str[0] != null) {
                if (str[0].equals(nameText)) //判断是否以str开头
                {
                    result = true;
                    break;
                }
                String n=br.readLine();
                if(n!=null)
                  str= n.split("、");
                else
                    break;
            }
            br.close();
            fr.close();
            //读取一行数据
        } catch (FileNotFoundException e) {
            System.out.println("文件未找到");
        } catch (IOException e) {
            System.out.println("文件读错误");
        }
        return result;
    }
}