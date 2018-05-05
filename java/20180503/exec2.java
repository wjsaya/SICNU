//设计一个复数类
//有两个double型成员变量(访问控制权限为私有类型)，
//分别存放一个复数的实部和虚部
//两个复数的加和减（必做）
//乘和除法（选作）运算
//（包括能够完成一个数值型数据的运算，选作）
import java.util.*;
class fsys {
    private double s;
    private double x;

    public void print() {
        System.out.println("now--"+this.getReal()+"---"+this.getVirtual());
    }

    fsys() {
        this.s = 1;
        this.x = 1;
    }

   fsys(double ss, double xx) {
        this.s = ss;
        this.x = xx;
    }

    public double getReal() {
        return this.s;
    }

    public double getVirtual() {
        return this.x;
    }

    fsys add(fsys num1) {
        double news = s + num1.getReal();  
        double newx = x + num1.getVirtual();
        fsys result = new fsys(news, newx);
        return result; 
    }
    
    fsys sub(fsys num1) {
        double news = s - num1.getReal();  
        double newx = x - num1.getVirtual();
        fsys result = new fsys(news, newx);
        return result; 
    }

    fsys pwn(fsys num1) {
    //(a+bi)(c+di)=(ac-bd)+(bc+ad)i.
        double s2 = num1.getReal();
        double x2 = num1.getVirtual();
        double news = (s*s2 - x*x2);
        double newx = (s2*x + s*x2);
        fsys result = new fsys(news, newx);
        return result;
    }

    fsys mod(fsys num1) {
    //(a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +((bc-ad)/(c^2+d^2))i
        double s2 = num1.getReal();
        double x2 = num1.getVirtual();
        double news = (s*s2+x*x2)/(s2*s2 + x2*x2);
        double newx = (x*s2-s*x2)/(s2*s2 + x2*x2);
        fsys result = new fsys(news, newx);
        return result;
    }

}

public class exec2 {
    public static void main(String[] args) {
        fsys sortList[];
        sortList = new fsys[5];
        for(int i=0; i<5 ; i++)
            sortList[i] = new fsys(1.0+i, 1.0+i);

    for(int i=0; i<5 ; i++)
            System.out.print(sortList[i].getReal() + "+"+ sortList[i].getVirtual() + " ");

        sort(sortList);

        System.out.println("\n以上为排序前");
        for(int i=0; i<5 ; i++)
            System.out.print(sortList[i].getReal() + "+"+ sortList[i].getVirtual() + " ");
        System.out.println("\n以上为排序后");

    }

    static void sort(fsys sortList[]) 
    {
        int i, j;
        fsys temp;
        double max_S, max_X;
        int max = 0;
        for(i=0; i<5 ; i++) 
        {
           max_S = sortList[i].getReal();
           for(j=i; j<5; j++) 
           {
                if(max_S < sortList[j].getReal())
                {
                    temp = sortList[i];
                    sortList[i] = sortList[j];
                    sortList[j] = temp;
                }
           }
        }
    }
    
    static void test1() {
        fsys num1 = new fsys(1.0, 2.0);
        fsys num2 = new fsys(3.0, 4.0);
        
        fsys new1 = num1.add(num2);
        fsys new2 = num1.sub(num2);
        fsys new3 = num1.pwn(num2);
        fsys new4 = num1.mod(num2);

        System.out.println("num1:\t"+num1.getReal()+" + i*"+num1.getVirtual());
        System.out.println("num2:\t"+num2.getReal()+" + i*"+num2.getVirtual());
        System.out.println("+:\t"+new1.getReal()+" + i*"+new1.getVirtual());
        System.out.println("-:\t"+new2.getReal()+" + i*"+new2.getVirtual());
        System.out.println("*:\t"+new3.getReal()+" + i*"+new3.getVirtual());
        System.out.println("/:\t"+new4.getReal()+" + i*"+new4.getVirtual());
    }

}
