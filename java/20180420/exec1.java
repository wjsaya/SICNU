import java.util.*;

class calu {
    int[] caca(int in[]) {
        int max=in[0], min=in[0], avg=0, sum=0;
        int[] re;
        re = new int[3];
        int i;
        for(i=0; i<10; i++) {
            if(max <= in[i])
                max = in[i];
            if(min >= in[i])
                min = in[i];
            sum += in[i];
        }
        avg = sum/10;
        re[0] = max;
        re[1] = min;
        re[2] = avg;
        return re;
    }
}

public class exec1 {
    public static void main(String[] args) {
//设计一个类，类中有一个方法用于求任一个整型数组的最大值、最小值和平均值，并将这三个值返回给调用者，由调用者输出。
    int[] in;
    int i;
    in = new int[10];
    Random random = new Random();
    for(i=0; i<10; i++)
        in[i] = Math.abs(random.nextInt() % 100);
    for(i=0; i<10; i++)
        System.out.print(in[i]+" ");
    System.out.println("");

    int[] resp = new int[3];
    calu tt = new calu();
    resp = tt.caca(in);
    System.out.println("max="+resp[0]);
    System.out.println("min="+resp[1]);
    System.out.println("avg="+resp[2]);
    }
}

