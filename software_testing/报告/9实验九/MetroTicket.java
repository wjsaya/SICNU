


public class MetroTicket {
	private int _OneTicket,_MonthTicket,_Line1Num,_Line2Num,_count_of_five,_count_of_Ten,_count_of_Fifty,_count_of_OneHundred;
//	private float _total;
	private String[] _type={"OneTicket","MonthTicket"};
	private String[] _lineno={"Line1","Line2"};
	private int _money;
	private String _result;
	public MetroTicket()
	{
		init();
	}
	/*public MetroTicket(int five,int beer,int orange)	//���ڲ��Եĳ�ʼ������
	{
         _count_of_one=one;	
		_count_of_five=five;
		_beerNum=beer;
		_orangeNum=orange;
	}*/
	private void init()
	{
		_OneTicket=5;
		_MonthTicket=200;
		
	//	_Line1Num=0;
	//	_Line2Num=0;
		
		_count_of_five=1;
		_count_of_Ten=0;
//		_count_of_Fifty=0;
		_count_of_OneHundred=0;
		
	}
	public String Operate(String type,String lineno,int money)
 //type���û�ѡ��Ĳ�Ʒ,money���û�Ͷ������,
	{
//		float loose_change=0;
		if(type.equals(_type[0]))//����û�ѡ��one ticket
		{
			if(money==5)	//����û�Ͷ��5ԪǮ
			{
				if(lineno.equals(_lineno[0]))	//����û�ѡ��line1
				{
					_count_of_five++;
					_result="You have pay for the Line1. Please pick it up.";
					return _result;
				}
				else if(lineno.equals(_lineno[1]))	//����û�ѡ��Line2
				{
					_count_of_five++;
					_result="You have pay for the Line2. Please pick it up.";
					return _result;
				}
				else//???????????????????
					return "The line message is errno!!!";
			}
			else if(money==10)	//����û�Ͷ��10ԪǮ
			{
				if(lineno.equals(_lineno[0]))	//����û�ѡ��Line1
				{
					if(_count_of_five>=1)	//�������Ǯ��
					{
						_count_of_five--;
						_count_of_Ten++;
						_result="You have pay for the Line1. Please pick it up and the loose change.";
						return _result;
					}
					else
						return "There has no loose change,Please pick up your money,Sorry!!!!";
						
				}
				else if(lineno.equals(_lineno[1]))	//����û�ѡ��Line2
				{
					if(_count_of_five>=1)	//�������Ǯ��
					{
						_count_of_five--;
						_count_of_Ten++;
						_result="You have pay for the Line2. Please pick it up and the loose change.";
						return _result;
					}
					else
						return "There has no loose change,Please pick up your money,Sorry!!!!";
				}
				return "The line message is errno!!!";
			}
			return "The money message is errno!!!";
		}
		else if(type.equals(_type[1]))//����û�ѡ��month ticket
		{
			if(money<200)	//����û�Ͷ������200ԪǮ
			{
				_result="You have not pay enough for the month ticket. Please pay 200 RMB.";
				return _result;
			}
			else if(money==200)	//����û�Ͷ��200ԪǮ
			{	
				if(lineno.equals(_lineno[0]))	//����û�ѡ��line1
				{
					_count_of_OneHundred++;
					_result="You have pay for the Line1 month ticket. Please pick it up.";
					return _result;
				}
				else if(lineno.equals(_lineno[1]))	//����û�ѡ��Line2  error:else if(lineno.equals(_type[1])
				{	_count_of_OneHundred++;
					_result="You have pay for the Line2 month ticket. Please pick it up.";
					return _result;
				}
				return "The line message is errno!!!";
			}
			return "The money message is errno!!!";
		}
		
		return "There has some input error!!!!!!";
	}




public static void main(String[] args) {
	// TODO Auto-generated method stub
	System.out.println("Hello,Welcome");
	
	MetroTicket MetroTicket1 = new MetroTicket() ;
	MetroTicket1.init();
//	MetroTicket1.Operate("OneTicket","Line1",5);
	MetroTicket1.Operate("MonthTicket","Line1",200);
}
}