package CODE.反射;

import javax.management.ObjectName;
import java.lang.reflect.Method;

//公共程序类
public class BeanOperation {
    public static void setBeanVaule(Object actionObj,String msg) throws Exception {
        // emp.name:pick|emp.jon:cooker
        String[] tmp=msg.split("\\|");
        // tmp[0]:emp.name:pick
        //tmp[1]:emp.jon:cooker
        for(int i=0;i<tmp.length;i++)
        {
            //继续拆分
            String[] result=tmp[i].split(":");
            //emp.name   pick

            String attribute=result[0];//属性名称
            String value=result[1]; //属性内容 pick

            //将属性名称继续拆分  emp.name
            String realClassName=attribute.split("\\.")[0]; //类名称 emp
            String attrName=attribute.split("\\.")[1];  // name
            Object realObj=getRealObject(actionObj,realClassName);
            setObjectValue(realObj,value,attrName);
            System.out.println(realObj);
        }
    }
    //取得真实类
    public static Object getRealObject(Object actionObj,String realClassName) throws Exception {
        Object realObj=null;
        Class<?> cls=actionObj.getClass();
        String methodName="get"+upFirst(realClassName);
        Method method=cls.getMethod(methodName);
        realObj=method.invoke(actionObj);
        return realObj;
    }

    //将首字母大写
    public static String upFirst(String name)
    {
        return name.substring(0,1).toUpperCase()+name.substring(1);
    }
    public static void setObjectValue(Object realClass,String value,String attrName) throws Exception {
        Class<?> cls=realClass.getClass();
        String methodName="set"+upFirst(attrName);
        System.out.println(methodName);
        Method method=cls.getMethod(methodName,String.class);
        method.invoke(realClass,value);
    }
}
