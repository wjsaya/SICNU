public class shuzu {
    public static void main(String[] atgs) {
        int[][] sz1;
        sz1 = new int[5][5];
        int i, j;
        for(i=0; i<5; i++)
            for(j=0; j<5; j++)
                sz1[i][j] = i;
        for(i=0; i<5; i++) {
            for(j=0; j<5; j++) 
                System.out.print(sz1[i][j]);
            System.out.println("");
        }   
    }

}
