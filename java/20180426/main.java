class test {
    double re;
    test(int in1, int in2) {
        System.out.println("传入了一个int数值");
        re = in1 + in2;
    }

    test(double in1, double in2) {
        System.out.println("传入了一个double数值");
        re = in1 + in2;
    }

    double get() {
        return re;
    }

    
}

public class main {
    public static void main(String[] args) {
    test q1 = new test(1, 1);
    test q2 = new test(2.2, 2.2);
    System.out.println("Q1-----" + q1.get());
    System.out.println("Q2-----" + q2.get());
    }
}
