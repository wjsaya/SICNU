interface Animal {
    public void run();
}

class Bird implements Animal {
    public void run()   {
        System.out.println("一只鸟在飞");
    }
}

class Fish implements Animal {
    public void run()   {
        System.out.println("一条鱼在游");
    }
}

class TestCls   {
    public void test(Animal a)  {
        a.run();
    }
}

public class main {
    public static void main(String[] argv)  {
        TestCls test = new TestCls();
        Bird b = new Bird();
        test.test(b);
    }
}
