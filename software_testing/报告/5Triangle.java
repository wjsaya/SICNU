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
				System.out.print("�������һ������:");
				i=sc.nextInt();
			}catch(Exception e){
				System.out.println("��һ���������벻�Ϸ�");
				isOK=false;
			}
			try{
				System.out.print("������ڶ�������:");
				j=sc.nextInt();
			}catch(Exception e){
				System.out.println("�ڶ����������벻�Ϸ�");
				isOK=false;
			}
			try{
				System.out.print("���������������:");
				k=sc.nextInt();
			}catch(Exception e){
				System.out.println("�������������벻�Ϸ�");
				isOK=false;
			}
			if(i<1||i>200){
				System.out.println("��һ���������벻�Ϸ�");
				isOK=false;
			}
			if(j<1||j>200){
				System.out.println("�ڶ����������벻�Ϸ�");
				isOK=false;
			}	 
			if(k<1||k>200){
				System.out.println("�������������벻�Ϸ�");
				isOK=false;
			}
			if(isOK == false){
				return;
			}
			if(i==j){match=match+1;}
			if(i==k){match=match+2;}
			if(j==k){match=match+3;}
			if(match == 0){
				if((i+j<=k)){System.out.println("�������������");}
				else{
					if((k+j<=i)){System.out.println("�������������");}
					else{
						if((k+i<=j)){System.out.println("�������������");}
						else{System.out.println("��ɵ���һ��������");}
					}
				}
			}
			else{
				if(match == 1){
					if(i+j<=k){ System.out.println("�������������");}
					else{   System.out.println("��ɵ��������ǵ���������");}
				}
				else{
					if(match == 2){
						if((i+k<=j)){System.out.println("�������������");}
						else{   System.out.println("��ɵ��������ǵ���������");}
						}
					else{
						if(match == 3){
							if((j+k<i)){System.out.println("�������������");}
							else{System.out.println("��ɵ��������ǵ���������");}
						}
						else{  System.out.println("��ɵ��������ǵȱ�������");
						}
					}
				}
			}
		   }
		   return;
	}
}


