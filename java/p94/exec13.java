import java.util.Scanner;
import java.lang.String;


class Student {
    String stu_no;
    String name;
    String xb;
    String gb;
    double math;
    double yw;
    double wy;

    void input() {
        Scanner in = new Scanner(System.in);
        System.out.println("请输入学号");
        stu_no = in.nextLine();
        System.out.println("请输入姓名");
        name = in.nextLine();
        System.out.println("请输入性别");
        xb = in.nextLine();
        System.out.println("请输入是否为干部（是|否）");
        gb = in.nextLine();
        System.out.println("请输入数学成绩");
        math = Double.parseDouble(in.nextLine());
        System.out.println("请输入语文成绩");
        yw = Double.parseDouble(in.nextLine());
        System.out.println("请输入外语成绩");
        wy = Double.parseDouble(in.nextLine());
    }

    double total() {
        double total;
        total = math + yw + wy;
        return total;
    }

    double average() {
       double average;
       average = total() / 3.0;
       return average;
    }
}
public class exec13 {
    public static void main(String args[]) {
        System.out.println("test");
        Student xm = new Student();
        xm.input();
        System.out.println("总分为：" + xm.total());
        System.out.println("平均分为：" + xm.average());
    }
}
