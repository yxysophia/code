package CODE.反射;

public class Loader {
    public static void main(String[] args) {
        Class<?> cls=Loader.class;
        System.out.println(cls.getClassLoader()); //sun.misc.Launcher$AppClassLoader@18b4aac2
        System.out.println(cls.getClassLoader().getParent());//sun.misc.Launcher$ExtClassLoader@4554617c
        System.out.println(cls.getClassLoader().getParent().getParent()); //null
    }
}
