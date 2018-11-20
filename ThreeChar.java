package CODE.多线程;

//一串字符中第一次出现3次的字母（字符串中有数字、字母、空格)
public class ThreeChar {
    public static void main(String[] args) {
        {
            String str="Ha ah  111kl a";
            System.out.println(firstChar(str));
        }
    }

    public static char firstChar(String str)
    {
        //将所有字符存入哈希表中，
        char[] ch=str.toCharArray();
        int[] hash=new int[256];
        for(int i=0;i<ch.length;i++)
        {
            char c=ch[i];
            if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            {
                hash[c]++;
            }
            if(hash[c]==3)
            {
                return c;
            }
        }
        return '0';
    }
}
