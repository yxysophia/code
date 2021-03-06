package CODE.计算器页面;

import javax.swing.*;
import java.awt.*;

class Cal extends JFrame
{
    //声明在窗体中所有组件
    private JLabel lable1;  //定义标签
    private JLabel lable2;
    private JTextField text;  //文本框，计算器输入的框
    private JPanel panel1;    // 面板1，上面有6个按钮
    private JPanel panel2;    //面板2，上面有24个按钮
    private JButton[] bts1;  //包含6个按钮的数组
    private JButton[] bts2;  //包含24个按钮的数组

    public Cal()
    {
        this.setSize(350,550);  //设置窗体的大小
        this.setTitle("计算器"); //设置窗体的名称
        this.setLayout(null);  //将窗体的默认布局方式设置为无布局方式

        //创建控件
        lable1=new JLabel("≡");  //标签≡
        lable1.setSize(20,20);     //标签的宽和高
        lable1.setLocation(5,7); //相对于窗体左上角的位置
        this.add(lable1);          //将#放入窗体

        lable2=new JLabel("标准");
        lable2.setSize(50,20);
        lable2.setLocation(30,7);
        this.add(lable2);

        text=new JTextField();
        text.setSize(320,70);
        text.setLocation(5,50);
        this.add(text);

        //面板1
        panel1=new JPanel();  //面板1
        panel1.setSize(320, 30);  //面板的宽和高
        panel1.setLocation(5,130);
        //panel1.setBackground(Color.green);


        //将6个按钮放入面板1
        bts1=new JButton[6]; //数组里有6个按钮
        String[] str1={"M+","M-","M~","M^","",""};
        panel1.setLayout(new GridLayout(1,6,2,0));  //将空格名之面板1的布局方式设为网格布局，
        for(int i=0;i<6;i++)
        {
            bts1[i]=new JButton(str1[i]);
            panel1.add(bts1[i]);
        }
        this.add(panel1);

        //面板2
        panel2=new JPanel();
        panel2.setSize(320,325); //面板2的宽和高
        panel2.setLocation(5,170);
        //panel2.setBackground(Color.yellow);
        panel2.setLayout(new GridLayout(6,4,5,2));
        bts2=new JButton[24];  //24个按钮的数组.
        String[] str2={"%","√","x²","1/x","CE","C","ж","÷",
                       "7","8","9","×","4","5","6","-","1","2","3"
                        ,"+","±","0",".","="};
        for(int i=0;i<24;i++)
        {
            bts2[i]=new JButton(str2[i]);
            panel2.add(bts2[i]);
        }
        this.add(panel2);



        this.setVisible(true); //设置窗体可见
    }
}
public class Cual
{
    public static void main(String[] args)
    {
        Cal cal=new Cal();
    }
}
