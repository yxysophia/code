import java.util.Scanner;
interface Computer
{
    void printComuter();
}
class MacBook implements Computer
{
    public void printComuter()
    {
        System.out.println("this is macbook");
    }
}
class Surface implements Computer
{
    public void printComuter()
    {
        System.out.println("this is surface");
    }
}
class ComputerFactory
{
    public static Computer getComputer(String type)
    {
        if(type.equals("macbook"))
        {
            return new MacBook();
        }
        else if(type.equals("surface"))
        { 
            return new Surface();
        }
        return null;
    }
}
public class Factory
{
    public static void main(String[] args)
    {
        Scanner scanner =new Scanner(System.in);
        System.out.println("请输入电脑型号:");
        String type=scanner.nextLine();
        Computer computer =ComputerFactory.getComputer(type);
        computer.printComuter();
    }

}