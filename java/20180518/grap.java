/*
（2）   设计实现如下两个类:

*/
class gra {
//a、     图形类：包含图形类的共有属性和功能，如属性：类型（圆、正方形、三角形等），颜色等；方法包括：求周长、求面积的功能、获得类型的值的功能。
    String type;
    String color;

    double get_C() {
        System.out.println("求周长");
        return 1;
    }

    double get_S() {
        System.out.println("求面积");
        return 1;
    }
}

class round extends gra {
//b、     圆类：包含圆类的特有属性和功能：如：私有的pi、半径等；一个公有的设置pi值的方法、一个公有的获得半径值的功能等
//d、     在圆类和长方形类中覆盖图形类中的求周长和求面积的方法。
    private double pi = 3.1415926;
    private double r;
    
    round(double in_r) {
        this.r = in_r;
    }

    round() {
        this.r = 1;
    }
    public void set_pi(double in_pi) {
        this.pi = in_pi;
    }

    public double get_r() {
        return this.r;
    }

    double get_C() {
        return 2 * ( this.pi * r );
    }

    double get_S() {
        return this.pi * r * r;
    }
    
}

class rectangle extends gra {
//c、     长方形类：包含长方形类的特有属性和功能：如：私有的长、宽等；一个公有的设置长、宽值的方法、一个公有的获得长、宽值的功能等
//d、     在圆类和长方形类中覆盖图形类中的求周长和求面积的方法。
    private double length;
    private double width;

    rectangle(double in_len, double in_wid) {
        this.length = in_len;
        this.width = in_wid;
    }

    rectangle() {
        this.length = 1;
        this.width = 1;

    }

    public void set_len(double in_len) {
        this.length = in_len;
    }
    public void set_wid(double in_wid) {
        this.width = in_wid;
    }

    public double get_len() {
        return this.length;
    }

    public double get_wid() {
        return this.width;
    }

    public double get_C() {
        return 2 * (this.length + this.width);
    }

    public double get_S() {
        return (this.length * this.width);
    }
}

public class grap {
    public static void main(String[] args) {
//e、     在main方法中定义一个图形类变量，依次指向圆类和长方形类对象，并调用其中的求周长和求面积方法。
    round a = new round(10);
    a.set_pi(3.14);
    System.out.println("圆A，r=\t"+a.get_r());
    System.out.println("圆A，C=\t"+a.get_C());
    System.out.println("圆A，S=\t"+a.get_S());

    rectangle b = new rectangle(10, 20);
    System.out.println("长方形B，len=\t"+b.get_len());
    System.out.println("长方形B，wid=\t"+b.get_wid());
    System.out.println("长方形B，C=\t"+b.get_C());
    System.out.println("长方形B，S=\t"+b.get_S());
    }
}
