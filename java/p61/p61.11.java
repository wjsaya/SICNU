/*
00      01      02      03      04
10      11      12      13
20      21      22
30      31
40
*/
class p6111
{
public static void main(String[] args)
        {
                int sum, i=1;
                int up;
                int ii = 10, jj=10;
                int [][]num;
                num = new int[ii][jj];
                
            for(sum=0 ; sum <= ii-1; sum++)
                {
                        for(up = 0; up <= sum; up++)
                        {
                                //System.out.print(i++);
                            num[sum - up][up] = i++;
                           }
                        // System.out.println();
                }
                
                
                for(sum = 0; sum<= ii-1; sum++)
                {
                        //System.out.println(num[0][3]);
                        for (up =0; up<=ii-1-sum;up++)
                        {
                                //System.out.print("sum=" + sum);
                                //System.out.println("up=" + up);
                            System.out.print(num[sum][up] + "\t");
                                }
                        System.out.println();
                }
        
        }
}



public class Main
{
        public static void main(String[] args)
        {
                int sum, i=1;
                int up;
                int ii = 10, jj=10;
                int [][]num;
                num = new int[ii][jj];
                
            for(sum=0 ; sum <= ii-1; sum++)
                        for(up = 0; up <= sum; up++)
                            num[sum - up][up] = i++;
                           
                
                
                for(sum = 0; sum<= ii-1; sum++)
                {
                        for (up =0; up<=ii-1-sum;up++)
                            System.out.print(num[sum][up] + "\t");
                        System.out.println();
     }}
} 
