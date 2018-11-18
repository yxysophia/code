package CODE.省市区;


import javax.swing.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

class Item1 extends JFrame implements ItemListener {

    JComboBox comboBox1;//定义下拉框（总共三个，省市区）
    JComboBox comboBox2;
    JComboBox comboBox3;
    String currentSelect1;//设置当前选项
    String currentSelect2;

    //第二个下拉框的内容
    String cities1[]={"西安市","商洛市"};  //陕西省对应2个市
    String cities2[]={"南昌市","九江市"};  //江西省对应2个市

    //第三个下拉框的内容
    String countries11[]={"未央区","雁塔区"};  //西安市对应的区
    String countries12[]={"镇安县","柞水县"};  //商洛市对应的县

    String countries21[]={"进贤县","安义县"};  //南昌市对应的县
    String countries22[]={"彭泽县","都昌县"};  //九江市对应的县

    public Item1()
    {
        this.setSize(600, 600);
        this.setLayout(null);
        //设置第一个下拉框--省
        comboBox1 = new JComboBox();
        comboBox1.setSize(120, 30);
        comboBox1.setLocation(30, 30);
        //将省份填入下拉框中
        String[] str1 = {"陕西省", "江西省"};
        for(int i=0;i<str1.length;i++)
        {
            comboBox1.addItem(str1[i]);
        }
        currentSelect1="陕西省";
        comboBox1.addItemListener(this);  //将选项添加到当前框
        this.add(comboBox1);

        //设置第二个下拉框--市
        comboBox2=new JComboBox();
        comboBox2.setSize(120, 30);
        comboBox2.setLocation(170, 30);
        //将市填入下拉框
        for(int i=0;i<cities1.length;i++)
        {
            comboBox2.addItem(cities1[i]);
        }
        currentSelect2="西安市";
        comboBox2.addItemListener(this);
        this.add(comboBox2);

        //设置第三个下拉框 ---县区
        comboBox3 = new JComboBox();
        comboBox3.setSize(120,30);
        comboBox3.setLocation(310,30);
        for(int i=0;i<countries11.length;i++)
        {
            comboBox3.addItem(countries11[i]);
        }
        //comboBox3.addItemListener(this);
        this.add(comboBox3);

        this.setVisible(true);
    }
    public void add(String[] str,JComboBox com)
    {
        for(int i=0;i<str.length;i++)
        {
            com.addItem(str[i]);
        }
    }
    @Override
    public void itemStateChanged(ItemEvent e)
    {
        //第二个选项的动作
        //第二个下拉框当前内容和所选省份不对应
        if(!currentSelect1.equals(comboBox1.getSelectedItem().toString()))
        {
            currentSelect1=comboBox1.getSelectedItem().toString();   //更新当前值
            comboBox2.removeAllItems(); //将第二个下拉框内容清空
            if(currentSelect1.equals("陕西省")){
                currentSelect2=cities1[0];
                //更新第二个下拉框
                add(cities1,comboBox2);
            }else if(currentSelect1.equals("江西省"))
            {
                currentSelect2=cities2[0];
                add(cities2,comboBox2);
            }
        }

        //第三个下拉框
        if(comboBox2.getSelectedItem()!=null)
        {

            currentSelect2=comboBox2.getSelectedItem().toString();
            comboBox3.removeAllItems();
            if(currentSelect2.equals("西安市"))
            {
                add(countries11,comboBox3);
            }
            else if(currentSelect2.equals("商洛市")){
                add(countries12,comboBox3);
            }else if(currentSelect2.equals("南昌市"))
            {
                add(countries21,comboBox3);
            }else
            {
                add(countries22,comboBox3);
            }
        }
    }
}
public class SQ
{
    public static void main(String[] args) {
        Item1 it=new Item1();
    }
}