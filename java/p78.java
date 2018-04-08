import java.util.Scanner;
import java.lang.String;

public class p78 {

public static void exc1() {
    double avg, sum=0; 
    int i;
    Scanner in = new Scanner(System.in);
    String str = in.nextLine();
    String[] str2 = str.split(" ");
    for (i=0;i<=str2.length;i++) {
        sum += i;
        //System.out.println(str2[i]);
        //System.out.println(i + ":" + sum);
    }
    avg = (double)(sum * 1.0) / (double)(str2.length + 1.0);
    System.out.println(sum);
    System.out.println(str2.length * 1.0);
    System.out.println(avg);
}
    public static void main(String[] args) {
        exc1();



    }



}
