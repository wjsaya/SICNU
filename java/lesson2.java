/*
char类型及转义字符的使用
*/
import java.util.Scanner; 

class Lesson2 {
        public static void main(String[] args) {
                char var1 = 'A';
                char var2 = 'B';
                boolean var3 = (var1 == var2);
                float var4=2.33f;
                System.out.print("var1与var2的比较结果：\n" + var3);
                
                String str1 = "串1";
                String str2 = "串2";
                int int1 = Integer.parseInt("123123");
                System.out.printf("\nstr1和str2做+运算的结果为：%s\n",str1 + str2);
                System.out.printf("字符串转数字类型结果为:%d\n", int1);
                /*
        Scanner scanNext = new Scanner(System.in);// 从键盘接收数据
        System.out.println("next方式接收：");
        // 判断是否还有输入
        if (scanNext.hasNext()) {
            String strnext = scanNext.next();
                        // next方式接收字符串
            System.out.println("输入的数据为：" + strnext);
        }
        scanNext.close();
                
                Scanner scanNextLine = new Scanner(System.in);
                System.out.println("nextLine方式接收：");
        if (scanNextLine.hasNextLine()) {
            String strNextLine = scanNextLine.nextLine();
            System.out.println("输入的数据为：" + strNextLine);
        }
        scanNextLine.close();
*/
                int int2 = 12;
                int int3 = 5;
                int int4 = int2 % int3;
                System.out.printf("%d和%d取余为%d\n", int2, int3, int4);
                
                float float2 = 120f;
                float float3 = 5f;
                float float4 = float2 / float3;
                System.out.printf("%f和%f的商为%f\n", float2, float3, float4);
                
                
                
        }
}

