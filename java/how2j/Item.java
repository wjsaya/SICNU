


public class Item {
    String name;
    int price;
    
    void getName() {
        System.out.println(name);    
    }
    void setName(String a)  {
        name = a;
        }

    public static void main(String[] args) {
        Item xp = new Item();
        Item cx = new Item();
        Item cj = new Item();
        xp.name = "血瓶";
        xp.price = 50;
        cx.name = "草鞋";
        cx.price = 300;
        cj.name = "长剑";
        cj.price = 350;
        
        cj.setName("233");
        cj.getName();
        }
}
