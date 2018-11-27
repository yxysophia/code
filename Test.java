package CODE.反射;

public class Test {
    public static void main(String[] args) throws Exception {
        EmpAction empAction=new EmpAction();
        String value="emp.name:pick|emp.job:cooker";
        empAction.setValue(value);
    }
}
