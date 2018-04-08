import java.util.Scanner;
import java.lang.String;
import java.util.Random;

public class p78 {

    public static void exc1() {
        double avg, sum=0;
        int i;
        System.out.println("请输入一串数字,输出大于平均数的:");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        String[] str2 = str.split(" ");
        for (i=0;i<str2.length;i++) {
            sum += Double.parseDouble(str2[i]);
        }
        avg = (sum * 1.0) / (str2.length + 1.0);

        for (i=0;i<str2.length;i++) {
            if (Double.parseDouble(str2[i]) > avg)
                System.out.println(str2[i]);
        }
    }


    public static void exc2() {
        int min, max;
        int i, now;
        System.out.println("请输入一串数字,求最大最小:");
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        String[] str2 = str.split(" ");
        min = max = Integer.parseInt(str2[0]);
        for (i=0;i<str2.length;i++) {
            now = Integer.parseInt(str2[i]);
            if (now <= min)
                min = now;
            if (now >= max)
                max = now;
        }
        System.out.println("max=" + max);
        System.out.println("min=" + min);
    }

    public static void exc3() {
        int sum=0;
        int[][] three;
        three = new int[3][3];
        int i,j;
        for(i=0; i<3; i++)
            for(j=0; j<3; j++)
                three[i][j] = j+1;

        for(i=0; i<3; i++) {
            for (j = 0; j < 3; j++) {
                System.out.print(three[i][j]);
                if (i == j)
                    sum += three[i][j];
            }
            System.out.print("\n");
        }
        System.out.println("和为:" + sum);
    }

    public static void exc4() {
        int min, max;
        int min_i, min_j, max_i, max_j;
        int[][] four;
        four = new int[4][5];
        int i, j;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 5; j++) {
                four[i][j] = j + 1;
            }
        }

        max = min = four[0][0];
        min_i = min_j = max_i = max_j = 0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 5; j++) {
                int now = four[i][j];
                if (now <= min) {
                    min = now;
                    min_i = i;
                    min_j = j;
                }
                if (now >= max) {
                    max = now;
                    max_i = i;
                    max_j = j;
                }
                System.out.print(four[i][j]);
            }
            System.out.print("\n");
        }
        System.out.printf("max=%d(%d, %d)\n", max, max_i, max_j);
        System.out.printf("min=%d(%d, %d)\n", min, min_i, min_j);
    }

    public static void exc5() {
        int[] list;
        Random rand = new Random();
        list = new int[8];
        int i, j, temp = 0;
        for(i=0; i<8; i++)
            list[i] = rand.nextInt(100);

        System.out.println("原排序");
        for(i=0; i<8; i++)
            System.out.printf("%d ", list[i]);
        System.out.println("");

        for(i=0; i<8; i++) {
            for(j=0; j<=i-1; j++) {
                if (list[i] <= list[j]) {
                    temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }

        System.out.println("冒泡排序后");
        for(i=0; i<8; i++)
            System.out.printf("%d ", list[i]);
        System.out.println("");
    }

    public static void main(String[] args) {
        int sw = 0;
        Scanner in = new Scanner(System.in);
        System.out.println("请输入想执行功能:");
        System.out.println("1:习题5.1");
        System.out.println("2:习题5.2");
        System.out.println("3:习题5.3");
        System.out.println("4:习题5.4");
        System.out.println("5:习题5.5");
        sw =  Integer.parseInt(in.next());
        switch (sw) {
            case 1:
                exc1();
                break;
            case 2:
                exc2();
                break;
            case 3:
                exc3();
                break;
            case 4:
                exc4();
                break;
            case 5:
                exc5();
                break;
        }



    }
}

