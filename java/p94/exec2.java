import java.util.Scanner;

class ss {
    int i;
    boolean single(int N) {
        boolean judge = true;
        if (N == 1 || N == 0)
            return false;
        for(i=2;i<N;i++) {
            if ( N % i == 0 )
                judge = false;
        }
    return judge;
    }

    void multi(int s, int e) {
        int i;
        for(i=s; i<=e; i++) {
            if (single(i) == true)
                System.out.println(i);
        }
    }
}

public class exec2 {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.println("请输入s");
        int s = Integer.parseInt(in.nextLine());
        System.out.println("请输入e");
        int e = Integer.parseInt(in.nextLine());

        ss si = new ss();
        si.single(s);
        System.out.println(s + "-" + e + "之间的素数为");
        si.multi(s, e);
    }
}
