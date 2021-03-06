//package zzzzzzzz;
import java.io.*;//作者：凯鲁嘎吉 - 博客园<br>//http://www.cnblogs.com/kailugaji/
public class Text {
    public static void main(String[] args) throws MyException, IOException {
        Login l=new Login();
        l.login();
    }
}
class Student{
    private String stunumber;
    private String name;
    private String age;
    private String sex;
    private String score;
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
    void set_age(String agee){
        age=agee;
    }
    String get_age(){
        return age;
    }
    void set_sex(String sexx){
        sex=sexx;
    }
    String get_sex(){
        return sex;
    }
    void set_score(String scoree){
        score=scoree;
    }
    String get_score(){
        return score;
    }
}
class StudentManager{
    int n=0;
    Student ss[]=new Student[50];
    //遍历学生信息
    void showStudent(){
        for(int i=0;i<=n;i++){
            System.out.println("学号："+ss[i].get_stunumber()+"姓名："+ss[i].get_name()+"年龄："+ss[i].get_age()+"性别："+ss[i].get_sex()+"分数："+ss[i].get_score()+"\t\n");
        }      
    }
    //判断学号是否已经存在
     boolean panduan(String st)
    {
        boolean flag=true;   
        for(int i=0;i<n;i++)
        {
            if(ss[i].get_stunumber().equals(st))
                flag= false;
            else
                flag= true;
        }
        return flag;
    }   
     //添加学生信息
    void addStudent(String stunumber,String name,String age,String b,String score){
        ss[n]=new Student();
        ss[n].set_stunumber(stunumber);
        ss[n].set_name(name);
        ss[n].set_age(age);
        ss[n].set_sex(b);
        ss[n].set_score(score);
        n++;
    }
    //删除学生信息
    void deleteStudent(String stunumber) throws MyException{
        for(int i=0;i<=n;i++){
            if(ss[i].get_stunumber().equals(stunumber)){
                System.out.println("学号为："+stunumber+"的学生已被删除！");
                if(n==1){
                    System.out.println("数组为空");
                    ss[0]=new Student();
                }
                    else {
                        for(int j=i;j<=n;j++){
                            ss[j]=ss[j+1];
                        }
                        n--;
                    }
                }
                else{
                    throw new MyException("该学生不存在！");
                }
            }
        }
    //修改学生信息
    void updateStudent(String stu1,String name,String age,String sex,String score) throws MyException{
        for(int i=0;i<=n;i++){
            if(ss[i].get_stunumber().equals(stu1)){
                ss[i]=new Student();
                ss[i].set_stunumber(stu1);
                ss[i].set_name(name);
                ss[i].set_age(age);
                ss[i].set_sex(sex);
                ss[i].set_score(score);
            }
            else
                throw new MyException("没有找到该学生！");
        }
    }
    //查询学生信息
    void selectStudent(String number) throws MyException{
        for(int i=0;i<=n;i++){
            if(ss[i].get_stunumber().equals(number)){
                System.out.println("学号："+ss[i].get_stunumber()+"姓名："+ss[i].get_name()+"年龄："+ss[i].get_age()+"性别："+ss[i].get_sex()+"分数："+ss[i].get_score()+"\t\n");
            }
            else
                throw new MyException("没有找到该学生！");
        }
    }
    //统计不及格的人数
    void tongji(){
        int s=0;
        for(int i=0;i<=n;i++){
            int a=Integer.parseInt(ss[i].get_score());
            if(a<=60){
                s=s+1;
                System.out.println("学号："+ss[i].get_stunumber()+"姓名："+ss[i].get_name()+"年龄："+ss[i].get_age()+"性别："+ss[i].get_sex()+"分数："+ss[i].get_score()+"\t\n");
            }
        }
        System.out.println("不及格的人数为："+s+"人");
    }
    //输入界面
    void showface(){
        System.out.println("*****************************");
        System.out.println("石家庄铁道大学学生信息管理系统");
        System.out.println("*****************************");
        System.out.println("1.遍历输出学生信息");
        System.out.println("2.新学生信息录入");
        System.out.println("3.删除学生信息");
        System.out.println("4.修改学生信息");
        System.out.println("5.查询学生信息");
        System.out.println("6.学生信息统计");
        System.out.println("7退出.");
    }
    }
class Login{
    User users=new User("001","123456");//用户名，密码
    //登录
    void login() throws MyException, IOException{
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        DataOutputStream out=new DataOutputStream(new BufferedOutputStream(new FileOutputStream("Student.txt",true)));
        for(int i=1;i<=3;i++){
        System.out.println("请输入用户ID：");
        String id=in.readLine();
        System.out.println("请输入密码：");
        String pass=in.readLine();
            if((users.uername.equals(id))&&(users.passage.equals(pass))){
                StudentManager sm=new StudentManager();
                while(true){
                sm.showface();
                System.out.println("请选择：");
                String choose=in.readLine();
                if(choose.startsWith("1")){
                    sm.showStudent();
                }
                else if(choose.startsWith("2")){
                    System.out.print("请输入学号：");
                    String stu=in.readLine();
                    System.out.print("请输入姓名：");
                    String name=in.readLine();
                    System.out.print("请输入年龄：");
                    String age=in.readLine();
                    System.out.println("请输入性别（true男，false女）：");
                    String sex=in.readLine();
                    System.out.print("请输入分数：");
                    String score=in.readLine();
                    if(sm.panduan(stu)){
                    sm.addStudent(stu, name, age, sex, score);
                    System.out.println("创建成功！");
                    out.writeUTF("|学号："+stu+"|姓名："+name+"|年龄："+age+"|性别："+sex+"|分数："+score+"|\t\t\n\n");
                    }
                    else
                        throw new MyException("该学生已存在，请勿重复添加");
                }
                else if(choose.startsWith("3")){
                    System.out.println("请输入学号：");
                    String stu=in.readLine();
                    if(!(sm.panduan(stu))){
                        sm.deleteStudent(stu);
                    }
                    else
                        throw new MyException("该学号不存在！");
                }
                else if(choose.startsWith("4")){
                    System.out.println("请输入学号：");
                    String stu=in.readLine();
                        System.out.println("请输入姓名：");  
                        String name=in.readLine();
                        System.out.println("请输入年龄：");
                        String age=in.readLine();
                        System.out.print("请输入性别（true男，false女）：");
                        String sex=in.readLine();
                        System.out.print("请输入分数：");
                        String score=in.readLine();
                        if(!(sm.panduan(stu))){
                        sm.updateStudent(stu, name, age, sex, score);
                        out.writeUTF("|学号："+stu+"|姓名："+name+"|年龄："+age+"|性别："+sex+"|分数："+score+"|\t\n");
                    }
                    else
                        throw new MyException("该学号不存在！");
                }
                else if(choose.startsWith("5")){
                    System.out.println("请输入学号：");
                    String stu=in.readLine();
                    if(!(sm.panduan(stu))){
                        sm.selectStudent(stu);
                    }
                    else
                        throw new MyException("该学号不存在！");
                }
                else if(choose.startsWith("6")){
                    sm.tongji();
                }
                else if(choose.startsWith("7")){
                        in.close();
                        out.close();
                    System.exit(0);               
                }
                else {
                    throw new MyException("选择错误，请重新选择");
                }
            }
            }
            else
                System.out.println("用户ID或密码错误，请重新输入");
        }         
        throw new MyException("该卡已锁定！");
    }
}
class User{
    String uername;
    String passage;
    User(String user,String pass){
        this.uername=user;
        this.passage=pass;     
    }
    void set_uername(String use){
        uername=use;       
    }
    String get_uername(){
        return uername;
    }
    void set_passage(String pass){
        passage=pass;
    }
    String get_passage(){
        return passage;
    }
}
class MyException extends Exception{
    public MyException(String e) {
        super(e);
    }
}
