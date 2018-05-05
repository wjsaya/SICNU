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
        sortList = new fsys[10];

        fsys newLi[] = new fsys[sortList.length];

        for(int i=0; i<sortList.length ; i++)
            sortList[i] = new fsys(1.0+i, 1.0+i);
        //待排序属组从小到大(1->length)

        newLi = sort(sortList);

        for(int i=0; i<sortList.length ; i++)
            System.out.print(newLi[i].getReal() + "\t+\t"+ newLi[i].getVirtual() + "\n");
    }

    static fsys[] sort(fsys inList[])
    {
    //直接操作原数组,排序,不返回值
       // int len = inList.length;
        int i, j;
        fsys temp;
        double max_S;
        fsys sortList[];

        sortList = new fsys[inList.length];
        for(i=0; i<inList.length; i++)
            sortList[i] = inList[i];

        for(i=0; i<inList.length ; i++)
        {
           max_S = sortList[i].getReal();
           for(j=i; j<inList.length ; j++) 
           {
                if(max_S < sortList[j].getReal())
                {
                    temp = sortList[i];
                    sortList[i] = sortList[j];
                    sortList[j] = temp;
                }
           }
        }
        return sortList;
    }
}
