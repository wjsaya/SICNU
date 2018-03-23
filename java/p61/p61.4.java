import java.util.Scanner;

class p614
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int j;
        int sum = 0, sum_each;
        int n = Integer.parseInt(input.next());

        sum_each = 1;

        for(j=1; j<=n; j++)
        {
            sum_each *= j;
            sum += sum_each;
        //    System.out.println(j + "! =    " + sum_each);
        }
        //System.out.println(sum_each + "  <--each||sum-->   " + sum);


        System.out.println(sum);


    }


}
