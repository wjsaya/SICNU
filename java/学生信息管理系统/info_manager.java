import java.io.*;
import java.util.*;

//import javax.lang.model.util.ElementScanner6;
//import com.sun.org.apache.xpath.internal.operations.And;

class SystemManager extends db_Manager{ //继承db_Manager
    SystemManager() {
    }
    void showmenu() throws IOException  {
      //  BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        Scanner in = new Scanner(System.in);
        System.out.println("回车继续, cls清屏......");


        String innn = in.next();
        if (innn.equals("cls"))
        {
            for(int i=0;i<=100;i++)
                System.out.println("\r\n");
        }   
//        System.out.println(innn);


        System.out.println("*****************************");
        System.out.println("学生信息管理系统");
        System.out.println("*****************************");
        System.out.println("1.遍历学生信息");
        System.out.println("2.录入学生信息");
        System.out.println("3.删除学生信息");
        System.out.println("4.修改学生信息");
        System.out.println("5.查询学生信息");
        System.out.println("6.统计学生信息.");
        System.out.println("0.退出系统.");
    }

    void judge() throws MyException, IOException{
        Scanner in = new Scanner(System.in);
        int sw=in.nextInt();
        switch(sw) {
            case 1:
                traverse();break;
            case 2:
                add();break;
            case 3:
                delete();break;
            case 4:
                update();break;
            case 5:
                select();break;
            case 6:
                //count();
                break;
            case 0:
                System.out.println("感谢使用,Bye~\n");
                System.exit(0);
            default:
                System.out.println("输入有误，请输入1-6之间的数字\n");
        }
        this.showmenu();
    }
}

public class info_manager {
    public static void main(String[] argv) throws MyException, IOException{
        
        SystemManager mainmenu = new SystemManager();
        mainmenu.showmenu();
        while(true)
            mainmenu.judge();
    }
}

class MyException extends Exception{
    public MyException(String e) {
        super(e);
    }
}