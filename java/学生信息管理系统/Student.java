import java.io.*;
import java.util.*;

class Student{
    private String stunumber;
    private String name;
    private String sex;
    private String classno;

    Student() {

    }

    Student(String a, String b, String c, String d) {
        this.set_stunumber(a);
        this.set_name(b);
        this.set_sex(c);
        this.set_classno(d);
    }
    public void get_all() {
        System.out.println("---------------------");
        System.out.println(this.stunumber);
        System.out.println(this.name);
        System.out.println(this.sex);
        System.out.println(this.classno);
        System.out.println("---------------------");
    }

    public void read_from_file(String[] inArray) {
        this.set_stunumber(inArray[0]);
        this.set_name(inArray[1]);
        this.set_sex(inArray[2]);
        this.set_classno(inArray[3]);
    }

    public void set_stunumber(String stu){
        stunumber=stu;
    }

    public String get_stunumber(){
        return stunumber;
    }
    void set_name(String na){
        name=na;
    }
    String get_name(){
        return name;
    }
    void set_sex(String sexx){
        sex=sexx;
    }
    String get_sex(){
        return sex;
    }
    void set_classno(String no){
        classno=no;
    }
    String get_classno(){
        return classno;
    }

    void save_2_db(File file2save) throws IOException{

        if (!file2save.exists())
            file2save.createNewFile();// 不存在则创建
        
        
        BufferedWriter writer = new BufferedWriter(new FileWriter(file2save, true));//true,则追加写入text文本
        writer.write(this.get_stunumber() + ",");
        writer.write(this.get_name() + ",");
        writer.write(this.get_sex() + ",");
        writer.write(this.get_classno());
        writer.write("\r\n");//换行
        writer.flush();
        writer.close();
    }
}
