public class exec1 {
    public static void main(String[] argv) {
    
    column a = new column(1, 2);
    column b = new column();
    column c = new column(1, 2);
    column d = new column();
    /*
     * double aa = a.get_V();
     * System.out.println(aa);
     */
    System.out.println("a.get_S()\t:\t" +  a.get_S()  );
    a.change_pi(3.33);
    System.out.println("a.change_pi(3.33)");
    System.out.println("column.pi\t:\t" +   column.pi  );
    System.out.println("b.get_S()\t:\t" +   b.get_S()  );
    System.out.println("d.get_count()\t:\t" +  d.get_count()  );
    }
}

class column {
    private double r, h;
    static double pi = 3.14;
    static int count;

    column(double a, double b) {
        column.count++;
        this.r = a;
        this.h = b;
    }
    column() {
        column.count++;
        this.r = 1;
        this.h = 1;
    }

    double get_S() {
        double S;
        S = pi * (this.r * this.r);
        return S;
    }

    double get_V() {
        double V;
        V = this.get_S() * this.h;
        return V;
    }

    void change_pi(double in) {
        column.pi = in;
    }

    int get_count() {
        return column.count;
    }
}
