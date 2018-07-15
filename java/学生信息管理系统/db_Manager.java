import java.io.*;
import java.util.*;

public class db_Manager {

    File inFile = new File("studentdb.csv"); // 读取的CSV文件
    File outFile = new File("studentdb_new.csv"); // 读取的CSV文件
    
    db_Manager() {
    }


    void traverse() throws IOException
    {
        BufferedReader reader = new BufferedReader(new FileReader(inFile));
        System.out.println("traverse.遍历");
        try
        {
            for (String line = reader.readLine(); line != null; line = reader.readLine()) 
            {  
                System.out.println(line.replace(",", "\t"));
            }
            reader.close();
        } catch (FileNotFoundException ex) 
        {
            System.out.println("没找到文件！");
        } catch (IOException ex)
        {
            System.out.println("读写文件出错！");
        }
    }

    void select()  throws IOException{
        BufferedReader reader = new BufferedReader(new FileReader(inFile));
        System.out.println("select.查询");
        System.out.println("想如何查询?");
        System.out.println("\t1.学号");
        System.out.println("\t2.名字");
        Scanner in = new Scanner(System.in);
        String instr = "";
        int judge = in.nextInt();
        int sign = 0;
        if (judge != 1 && judge !=2)
            System.out.println("输入有误,请按照提示输入对应数字");
        
        if (judge == 1)
            System.out.println("输入学号");
        
        if (judge == 2)
            System.out.println("输入姓名");

        instr = in.next();
        
        try
        {
            for (String line = reader.readLine(); line != null; line = reader.readLine()) 
            {
                String[] StrArray = line.split(",", 4);
                    {
                        if (judge == 1)
                        {
                            if (instr.equals(StrArray[0]))                            
                            {
                                if(sign == 0)
                                    System.out.print("|学号"+"\t"+"|姓名"+"\t"+"|性别"+"\t"+"|班级"+"\n");

                                for (int i = 0; i < StrArray.length; i++)
                                    System.out.print("|"+StrArray[i]+"\t");

                                sign = 1;
                                System.out.print("\n");
                            }
                        }
                        if (judge == 2)
                        {
                            if (instr.equals(StrArray[1]))
                            {
                                if(sign == 0)
                                    System.out.print("|学号"+"\t"+"|姓名"+"\t"+"|性别"+"\t"+"|班级"+"\n");

                                for (int i = 0; i < StrArray.length; i++)
                                    System.out.print("|"+StrArray[i]+"\t");
                                
                                sign = 2;
                                System.out.print("\n");
                            }
                        }
                    }
            }

            if (judge == 1 && sign == 0) 
                System.out.print("未找到学号为[" + instr + "]的学生信息\n");
            if (judge == 2 && sign == 0) 
                System.out.print("未找到姓名为[" + instr + "]的学生信息\n");
            
            reader.close();

        } catch (FileNotFoundException ex)
        {
            System.out.println("没找到文件！");
        } catch (IOException ex) 
        {
            System.out.println("读写文件出错！");
        }
    }

    void add()  throws IOException{
        Scanner in = new Scanner(System.in);
        Student newbee = new Student();
        System.out.println("add.录入");
        System.out.println("学号");
        newbee.set_stunumber(in.next());
        System.out.println("姓名");
        newbee.set_name(in.next());
        System.out.println("性别");
        newbee.set_sex(in.next());
        System.out.println("班级");
        newbee.set_classno(in.next());
        newbee.save_2_db(inFile);
    }

    void delete()  throws IOException{
        BufferedReader reader = new BufferedReader(new FileReader(inFile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));
        System.out.println("delete.删除");
        System.out.println("想如何删除?");
        System.out.println("\t1.通过学号");
        System.out.println("\t2.通过名字");
        Scanner in = new Scanner(System.in);
        String instr = "";
        int judge = in.nextInt();
        if (judge != 1 && judge !=2)
            System.out.println("输入有误,请按照提示输入功能所对应数字");
        
        if (judge == 1)
            System.out.println("输入学号");
        
        if (judge == 2)
            System.out.println("输入姓名");
        
        instr = in.next();
        
        System.out.print("|学号"+"\t"+"|姓名"+"\t"+"|性别"+"\t"+"|班级"+"\n");          
        for (String line = reader.readLine(); line != null; line = reader.readLine()) 
        {
            Student onebee = new Student();
            String[] StrArray = line.split(",", 4);
            onebee.read_from_file(StrArray);
                {
                    if (judge == 1)
                    {
                        /*
                        int inNo = Integer.parseInt(instr);
                        int fileNo = Integer.parseInt(StrArray[0]);
                        if (inNo == fileNo)
                        */
                        if (instr.equals(StrArray[0]))
                        {
                            for (int i = 0; i < StrArray.length; i++) 
                                System.out.print("|"+StrArray[i]+"\t");
                            System.out.print("\n以上信息已删除\n");
                        }
                        else
                            onebee.save_2_db(outFile);
                    }
                    if (judge == 2)
                    {
                        if (instr.equals(StrArray[1]))
                        {
                            for (int i = 0; i < StrArray.length; i++)
                                System.out.print("|"+StrArray[i]+"\t");
                            System.out.print("\n以上信息已删除\n");
                        }
                        else
                            onebee.save_2_db(outFile);
                    }
                }
        }
        file_manage(inFile, outFile);
        reader.close();
        writer.close();

    }

/*
    void get_error_info(Process todeal) {
        InputStream stderr = todeal.getInputStream();//执行结果 得到进程的标准输出信息流
        InputStreamReader isr = new InputStreamReader(stderr);//将字节流转化成字符流
        BufferedReader br = new BufferedReader(isr);//将字符流以缓存的形式一行一行输出
        String line = null;
            while ((line = br.readLine()) != null) { 
                if (!StringUtils.isEmpty(line)) {
                    String[] strLine = line.split(":");
                    if(strLine.length>=2) {
                        lineMap.put(strLine[0].trim(), strLine[1].trim());
                    }                    
                }
            }
    }\
*/
    void file_manage (File origin, File dest) throws IOException {
        //把dest重命名为origin
        String path_origin = inFile.getAbsolutePath();
        String path_dest = outFile.getAbsolutePath();
        
        String cmd_del = "cmd /c del " + path_origin;
        String cmd_mv = "cmd /c move " + path_dest + " " + path_origin;            
        Runtime rt = Runtime.getRuntime();
        rt.exec(cmd_del);
        rt.exec(cmd_mv);
        /*
        Process proc_del = rt.exec(cmd_del);
        Process proc_mv = rt.exec(cmd_mv);
        get_error_info(proc_del);
        */
    }

    void update()  throws IOException{     
        BufferedReader reader = new BufferedReader(new FileReader(inFile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));
        System.out.println("delete.更新");
        System.out.println("想如何更新?");
        System.out.println("\t1.通过学号");
        System.out.println("\t2.通过名字");
        Scanner in = new Scanner(System.in);
        String instr = "";
        int judge = in.nextInt();
        if (judge != 1 && judge !=2)
            System.out.println("输入有误,请按照提示输入功能所对应数字");
        
        if (judge == 1)
            System.out.println("输入学号");

        if (judge == 2)
            System.out.println("输入姓名");
    
        instr = in.next();
        
        System.out.println("需要更新什么?");
        System.out.println("\t1,学号");
        System.out.println("\t2,姓名");
        System.out.println("\t3,性别");
        System.out.println("\t4,班级");
        int judge2 = in.nextInt();

        System.out.print("|学号"+"\t"+"|姓名"+"\t"+"|性别"+"\t"+"|班级"+"\n");          
        for (String line = reader.readLine(); line != null; line = reader.readLine()) 
        {
            Student onebee = new Student();
            String[] StrArray = line.split(",", 4);
            onebee.read_from_file(StrArray);
            if (judge == 1)
            {
                if (instr.equals(StrArray[0]))
                    update_onebee(onebee, judge2);
            
                onebee.save_2_db(outFile);
            }

            else if (judge == 2)
            {
                if (instr.equals(StrArray[1]))
                    update_onebee(onebee, judge2);

                onebee.save_2_db(outFile);
            }
        }

        file_manage(inFile, outFile);
        reader.close();
        writer.close();
    }
    
    void update_onebee(Student onebee, int judge2) {
        Scanner in = new Scanner(System.in);
        switch(judge2)
        {
            case 1:
                onebee.set_stunumber(in.next());
                break;
            case 2:
                onebee.set_name(in.next());
                break;
            case 3:
                onebee.set_sex(in.next());
                break;
            case 4:
                onebee.set_classno(in.next());
                break;
        }
    }



    void save() {
        System.out.println("save.入库");
    }
}
