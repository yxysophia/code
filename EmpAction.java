package CODE.反射;

public class EmpAction {
    private Emp emp=new Emp();
    public void setValue(String value) throws Exception {
        BeanOperation.setBeanVaule(this,value);
    }
    public Emp getEmp()
    {
        return emp;
    }
}
