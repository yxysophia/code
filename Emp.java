package CODE.反射;

public class Emp {
    private String name;
    private String job;

    public String getName() {
        return name;
    }

    public String getJob() {
        return job;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setJob(String job) {
        this.job = job;
    }

    @Override
    public String toString() {
        if(job==null)
        {
            return "姓名:"+name;
        }
        return "工作:"+job;
    }
}
