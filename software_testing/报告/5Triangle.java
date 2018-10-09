import java.util.Scanner;

public class Triangle {
	public static void main(String[] args) {
		int i=0,j=0,k=0;
		int match;
		boolean isOK=true;
		Scanner sc=new Scanner(System.in);
		for(int m=0;m<100;m++){
			match=0;
			isOK=true;
			try{
				System.out.print("请输入第一个数字:");
				i=sc.nextInt();
			}catch(Exception e){
				System.out.println("第一个数字输入不合法");
				isOK=false;
			}
			try{
				System.out.print("请输入第二个数字:");
				j=sc.nextInt();
			}catch(Exception e){
				System.out.println("第二个数字输入不合法");
				isOK=false;
			}
			try{
				System.out.print("请输入第三个数字:");
				k=sc.nextInt();
			}catch(Exception e){
				System.out.println("第三个数字输入不合法");
				isOK=false;
			}
			if(i<1||i>200){
				System.out.println("第一个数字输入不合法");
				isOK=false;
			}
			if(j<1||j>200){
				System.out.println("第二个数字输入不合法");
				isOK=false;
			}	 
			if(k<1||k>200){
				System.out.println("第三个数字输入不合法");
				isOK=false;
			}
			if(isOK == false){
				return;
			}
			if(i==j){match=match+1;}
			if(i==k){match=match+2;}
			if(j==k){match=match+3;}
			if(match == 0){
				if((i+j<=k)){System.out.println("不能组成三角形");}
				else{
					if((k+j<=i)){System.out.println("不能组成三角形");}
					else{
						if((k+i<=j)){System.out.println("不能组成三角形");}
						else{System.out.println("组成的是一般三角形");}
					}
				}
			}
			else{
				if(match == 1){
					if(i+j<=k){ System.out.println("不能组成三角形");}
					else{   System.out.println("组成的三角形是等腰三角形");}
				}
				else{
					if(match == 2){
						if((i+k<=j)){System.out.println("不能组成三角形");}
						else{   System.out.println("组成的三角形是等腰三角形");}
						}
					else{
						if(match == 3){
							if((j+k<i)){System.out.println("不能组成三角形");}
							else{System.out.println("组成的三角形是等腰三角形");}
						}
						else{  System.out.println("组成的三角形是等边三角形");
						}
					}
				}
			}
		   }
		   return;
	}
}


