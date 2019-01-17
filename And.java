
// &&  &

// public class And
// {
//     public static void main(String[] args)
//     {
//         if(1<2 | (10/0==0))
//         {
//             System.out.println("| 一个条件返回true后，其余条件不判断");  
//         }
//         else
//         {
//             System.out.println("| 一个条件返回true后，其余条件也要判断");//抛异常，证明|是即使有条件返回true，其余条件也会判断
//         }
//     }
// }

// public class And
// {
//     public static void main(String[] args)
//     {
//         if(1<2 || (10/0==0))
//         {
//             System.out.println("|| 一个条件返回true后，其余条件不判断");  //证明|| 只要有条件返回true，其余条件不会判断
//         }
//         else
//         {
//             System.out.println("|| 一个条件返回true后，其余条件也要判断");  
//         }
//     }
// }


// public class And
// {
//     public static void main(String[] args)
//     {
//         if(1>2 & (10/0==0))
//         {
//             System.out.println("& 一个条件返回false后，其余条件不判断");   
//         }
//         else
//         {
//             System.out.println("& 一个条件返回false后，其余条件也要判断");
            //会抛异常，即使1>2返回false,但是也会将后面条件进行判断，即 & 会判断所有条件
//         }
//     }
// }

public class And
{
    public static void main(String[] args)
    {
        if(1>2 && (10/0==0))
        {
            System.out.println("&& 一个条件返回false后，其余条件不判断");  
        }
        else
        {
            System.out.println("&& 一个条件返回false后，其余条件也要判断"); 
            //证明&&只要有一个条件返回false,就不会判断其他条件
        }
    }
}