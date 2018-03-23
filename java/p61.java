import java.util.Scanner;

class p61
{
        
   public static void exercise_3()
   {
        System.out.println("-->第三题，输出100以内能同时被3,7整除的数");
        int i;
        for(i=1; i<=100; i++)
        {
            if ((i % 3 == 0) && (i % 7 == 0))
                System.out.println(i);
        }

   }
   
   public static void exercise_4()
   {
        System.out.println("-->第四题，输入n，求1! + 2! + 3! + ... +n!");
        System.out.println("请输入n");
        Scanner input = new Scanner(System.in);
        int j;
        int sum = 0, sum_each;
        int n = Integer.parseInt(input.next());

        sum_each = 1;

        for(j=1; j<=n; j++)
        {
            sum_each *= j;
            sum += sum_each;
//              System.out.println(j + "! =    " + sum_each);
        }
//                      System.out.println(sum_each + "  <--each||sum-->   " + sum);


        System.out.printf("1-%d的阶乘之和为：%d\n", n, sum);

   }
   
   public static void exercise_6()
   {
        System.out.println("-->第六题，输出所有三位数中的水仙花数");
        int i;
        int i_g, i_s, i_b;              //i_(个，十，百)
        for(i=100 ; i<1000 ; i++)
        {
            i_g = i % 10;
            i_s = i % 100 / 10;
            i_b = i % 1000 / 100;
            
            if ((i_g * i_g * i_g) + (i_s * i_s * i_s) + (i_b * i_b * i_b) == i)
                System.out.println(i);
                }
   }
   
   public static void exercise_7()
   {
        System.out.println("-->第七题，输入一个数，判断其是不是完全数");
        Scanner input = new Scanner(System.in);
        int n = Integer.parseInt(input.next());
        int i, sum=0;             
        int bc;                   //被除
            for(i=1; i<=(n/2); i++)
            {
                
                bc = n/i;
                if (bc * i == n)
                {
                    sum += i;   //sum +=被除和i
//                      System.out.println(i+"  <--i+bc--> "+ bc+" =sum--> "+ sum);
                }
            }
        
            if(sum == n)
                System.out.println(n + "是完全数");
            else
                System.out.println(n + "不是完全数");
   }
   
   public static void exercise_11(int sum)
   {
        int row, i=1;
        int line;
        int [][]num;
        num = new int[sum][sum];
        
        for(row=0 ; row <= sum-1; row++)
                    for(line = 0; line <= row; line++)
                        num[row - line][line] = i++;

        for(row = 0; row<= sum-1; row++)
        {
            for (line =0; line<=sum-1-row;line++)
                System.out.print(num[row][line] + "\t");
                 
            System.out.println();
        }
   }
 
 
   public static void main(String []args)
   {
                p61 now_func = new p61();    //创建对象
                System.out.println("请输入p61上要执行的题号（3, 4, 6, 7, 11之一）：");
                Scanner input = new Scanner(System.in);
        int sw = Integer.parseInt(input.next());
                switch(sw)
                {
                        case 3:
                                now_func.exercise_3();
                                break;
                        case 4:
                                now_func.exercise_4();
                                break;
                        case 6:
                                now_func.exercise_6();
                                break;
                        case 7:
                                now_func.exercise_7();
                                break;
                        case 11:
                                System.out.println("请输入待输出的图案的行列数，行=列，输入一个数字即可：");
                                sw = Integer.parseInt(input.next());
                                now_func.exercise_11(sw);
                                break;
                        default:
                                System.out.println("输入有误！！！请输入题号对应的数字(3, 4, 6, 7, 11)");
                }
   }
}



