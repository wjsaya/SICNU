import java.util.Scanner;

class p617
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int n = Integer.parseInt(input.next());
        int i, sum=1;
        //sum初始化为1，则跳去1*n这一步
        int bc;
        //被除
        if (n == 1)
            System.out.println("1不是完数");
        else
        {
            for(i=2; i<=(n/2); i++)
            {
                
                bc = n/i;
                if (bc * i == n)
                {
                    sum += i;
                    //sum +=被除和i
        //            System.out.println(i+"  <--i+bc--> "+ bc+" =sum--> "+ sum);
                }
            }
        
            if(sum == n)
                System.out.println(n+"是完数");
        }
    }


}
