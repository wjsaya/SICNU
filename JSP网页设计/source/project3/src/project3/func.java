package project3;

public class func {
	public String counter(String numin1, String numin2, String swin) {
		
		try {
			int sw = Integer.valueOf(swin);
			Double num1 = Double.valueOf(numin1);
			Double num2 = Double.valueOf(numin2);
			String re_total = "";
			String re = "";
			
			switch(sw) {
				case 1:
					re_total += num1 + "+" + num2 + "=";
					re = String.valueOf(num1 + num2);
					break;
				case 2:
					re_total += num1 + "-" + num2 + "=";
					re = String.valueOf(num1 - num2);
					break;
				case 3:
					re_total += num1 + "*" + num2 + "=";
					break;
				case 4:
					re_total += num1 + "/" + num2 + "=";
					re = String.valueOf(num1 / num2);
					break;
				case 5:
					re_total += num1 + "%" + num2 + "=";
					re = String.valueOf(num1 % num2);
			}
//			return re_total += re;
			return re;
			
		}
			
		catch (Exception e) {
			return "参数解析错误，请重新计算";
		}
	}
}
