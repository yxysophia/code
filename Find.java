package CODE.文档管理系统;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

//查找类
public class Find extends JFrame implements ActionListener
{
    private JLabel lable1;  //文件名标签
    private JTextField nameText;  //输入文件名文本框
    private JButton button;       //查询按钮
    public Find()
    {
        //设置添加窗口大小
        this.setSize(400, 200);
        this.setTitle("查询文档信息");
        this.setLayout(null);

        //放入文件名
        lable1 = new JLabel("文件名");
        lable1.setSize(50, 20);
        lable1.setLocation(110, 50);
        this.add(lable1);

        //放入输入文件名文本框
        nameText = new JTextField();
        nameText.setSize(100, 20);
        nameText.setLocation(155, 50);
        this.add(nameText);

        //查询按钮
        button = new JButton("查询");
        button.setSize(60, 20);
        button.setLocation(160, 100);
        button.addActionListener(this);
        this.add(button);

        this.setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        //判断文件名为空
        if (isEmpty()) {
            JOptionPane.showMessageDialog(this, "文件名为空");
            clear();
            return ;
        }

        //判断文件名长度
        if (isError()) {
            JOptionPane.showMessageDialog(this, "文件名超出字符长度限制");
            clear();
            return ;
        }
        String[] result=(FindInfor(nameText.getText()));
        if(result!=null)
           JOptionPane.showMessageDialog(this, "文件名:"+result[0]+" 作者:"+result[1]+" 内容："+result[2]);
        else
            JOptionPane.showMessageDialog(this, "文件名不存在");
        clear();

    }
    private boolean isEmpty() {
        if ("".equals(nameText.getText().trim()) || nameText.getText() == null) {
            return true;
        }
        return false;
    }
    private void clear()
    {
        nameText.setText("");
    }
    private boolean isError()
    {
        //文件名长度不能超过10
        if (nameText.getText().length() > 10)
            return true;
        return false;
    }

    //查找文件名
    private String[] FindInfor(String nameText)
    {
        try {
            FileReader fr = new FileReader("d:\\info.txt");
            //产生一个文件字符输入流对象
            BufferedReader br = new BufferedReader(fr);
            //以上一个对象作为参数来创建一个缓冲的字符输入流对象
            String[] str = br.readLine().split("、");
            while (str[0] != null) {
                if (str[0].equals(nameText)) //判断是否以str开头
                {
                    return str;
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
        return null;
    }
}
