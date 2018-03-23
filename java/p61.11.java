class p6111
{
    public static void main(String[] args)
    {
       int sum, i=1;
       int up;
       int [][]num;
       num = new int[5][5];

       for(sum=0; sum<=4; sum++)
        {
            for(up=0; up<=sum; up++)
            {
                num[up][sum - up] = i++;
            }
        }

        for(sum = 0;sum<=4;sum++)
        //sum-up为列号
        //up为行号
        {
        }
    }
}


00      01      02      03      04
10      11      12      13
20      21      22
30      31
40
