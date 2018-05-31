interface Animal    {
    public void sound();
}

class Dog implements Animal {
    public void sound() {
        System.out.println("我是狗");
    }
    public void sound2() {
        System.out.println("我");
}   

}
class Cow implements Animal {
    public void sound() {
        System.out.println("我是牛");
    }
}



public class exec1 {
    public static void main(String[] argv) {
        Animal now;
        now = new Dog();
        now.sound();
        now = new Cow();
        now.sound();
    }
}
