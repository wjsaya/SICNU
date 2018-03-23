class p616
{
    public static void main(String[] args)
    {
        int i;
        int i_g, i_s, i_b;
        //i_(个，十，百)
        for(i=100 ; i<1000 ; i++)
        {
            i_g = i % 10;
            i_s = i % 100 / 10;
            i_b = i % 1000 / 100;
            
            if ((i_g * i_g * i_g) + (i_s * i_s * i_s) + (i_b * i_b * i_b) == i)
                System.out.println(i);


        }
    }


}
