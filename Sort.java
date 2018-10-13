public class Sort
{
    public static void main(String[] args)
    {
        int[] a={7,5,4,9,3,6,8,7};
        int len=a.length;
        QuickSort(a,0,len-1);
        for(int i=0;i<len;i++)
        {
            System.out.print(a[i]+" ");
        }

     }
   
     public static int sort(int[] a,int left,int right)
     {
         int begin=left;
         int end=right;
         int key=a[right]; //最右边为key
         while(begin<end)
         {
             while(begin<end&&a[begin]<=key)
             {
                 begin++;
             }
             while(begin<end&&a[end]>=key)
             {
                 end--;
             }
             if(begin<end)
             {
                 int c=a[begin];
                 a[begin]=a[end];
                 a[end]=c;    
               
             }
         }     
            int c=a[begin];
            a[begin]=a[right];
            a[right]=c;
            return begin;
     }
     public static void QuickSort(int[] a,int left,int right)
     {
         if(left>=right)
         {
             return ;
         }
         int div=sort(a,left,right);
         QuickSort(a,left,div-1);
         QuickSort(a,div+1,right);
     }
}