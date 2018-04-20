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

    ex2 pwn(ex2 num1) {
    //(a+bi)(c+di)=(ac-bd)+(bc+ad)i.
        double s2 = num1.getReal();
        double x2 = num1.getVirtual();
        double news = (s*s2 - x*x2);
        double newx = (s2*x + s*x2);
        ex2 result = new ex2();
        result.set(news, newx);
        return result;
    }

    ex2 mod(ex2 num1) {
    //(a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +((bc-ad)/(c^2+d^2))i
        double s2 = num1.getReal();
        double x2 = num1.getVirtual();
        double news = (s*s2+x*x2)/(s2*s2 + x2*x2);
        double newx = (x*s2-s*x2)/(s2*s2 + x2*x2);
        ex2 result = new ex2();
        result.set(news, newx);
        return result;
    }

}

public class exec2 {
    public static void main(String[] args) {
    ex2 num1 = new ex2();
    ex2 num2 = new ex2();
    num1.set(1, 2);
    num2.set(3, 4);
    
    ex2 new1 = num1.add(num2);
    ex2 new2 = num1.sub(num2);
    ex2 new3 = num1.pwn(num2);
    ex2 new4 = num1.mod(num2);

    System.out.println("num1:\t"+num1.getReal()+" + i*"+num1.getVirtual());
    System.out.println("num2:\t"+num2.getReal()+" + i*"+num2.getVirtual());
    System.out.println("+:\t"+new1.getReal()+" + i*"+new1.getVirtual());
    System.out.println("-:\t"+new2.getReal()+" + i*"+new2.getVirtual());
    System.out.println("*:\t"+new3.getReal()+" + i*"+new3.getVirtual());
    System.out.println("/:\t"+new4.getReal()+" + i*"+new4.getVirtual());
    }

}
