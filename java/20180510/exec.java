/* 设计实现如下两个类:
* 一、    机动车类：包含机动车类的共有属性和功能，如属性：车类型（公交车、汽车、火车），可否上高速。制造地；方法：行驶功能，载人功能等
* 二、    汽车类（继承自机动车）：包含机汽车类的特有属性，如：车灯个数、宽、高、时速等，滴滴服务功能等。
*/
class vehicle {
    String type;            //车类型
    boolean highway;        //可否上高速
    String pruduce;         //制造地

    void fun_drive() {       //行驶功能
        System.out.println("can drive");
    }
    void fun_man() {         //载人功能
        System.out.println("can take people");
    }

    private int ver1 = 100;       //
}

class car extends vehicle {
    int lights;             //车灯数
    double width;           //车宽
    double hight;           //车高
    double speed;           //时速
    boolean didi;           //滴滴服务功能
    void verify1() {
    //    System.out.println(ver1);
    //    exec.java:28: error: ver1 has private access in vehicle
    //    不能访问私有成员
        System.out.println(highway);
    }

}

public class exec {
    public static void main(String[] argv) {
    //    System.out.println("asdasd");
    }
    


}
