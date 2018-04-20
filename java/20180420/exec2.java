//设计一个复数类
//有两个float型成员变量(访问控制权限为私有类型)，
//分别存放一个复数的实部和虚部
//两个复数的加和减（必做）
//乘和除法（选作）运算
//（包括能够完成一个数值型数据的运算，选作）
import java.util.*;
class ex2 {
    private double s;
    private double x;

    public void print() {
        System.out.println("now--"+this.getReal()+"---"+this.getVirtual());
    }
    
/*
    ex2() {
        Scanner newin = new Scanner(System.in);
        System.out.println("输入实部：");
        this.s = newin.nextDouble();
        System.out.println("输入虚部：");
        this.x = newin.nextDouble();
    }
*/
    public void set(double ss, double xx) {
        this.s = ss;
        this.x = xx;
    }

    public double getReal() {
        return this.s;
    }

    public double getVirtual() {
        return this.x;
    }
    ex2 add(ex2 num1) {
        double s2 = num1.getReal();  
        double x2 = num1.getVirtual();  
        double news = s + s2;  
        double newx = x + x2;  
        ex2 result = new ex2();
        result.set(news, newx);  
        return result; 
    }
    ex2 sub(ex2 num1) {
        double s2 = num1.getReal();  
        double x2 = num1.getVirtual();  
        double news = s - s2;  
        double newx = x - x2;  
        ex2 result = new ex2();
        result.set(news, newx);  
        return result; 
    }

}

public class exec2 {
    public static void main(String[] args) {
    ex2 num1 = new ex2();
    ex2 num2 = new ex2();
    num2.set(3, 3);
    num1.set(1, 1);
    System.out.println("num1--"+num1.getReal()+"---"+num1.getVirtual());
    System.out.println("num2--"+num2.getReal()+"---"+num2.getVirtual());
    ex2 nnn = num1.add(num2);
    System.out.println("new--"+nnn.getReal()+"---"+nnn.getVirtual());
    }

}
