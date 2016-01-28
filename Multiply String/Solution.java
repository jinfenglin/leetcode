public class Solution {
	public String singleMultiply(String base,String single,int index,int shift){
		int acc=0;
		int singleDigit=single.charAt(index)-'0';
		if(singleDigit==0)
			return '0';
		StringBuilder res=new StringBuilder();
		for(int i=base.length()-1;i>=0;i--){
			int baseDigit=base.charAt(i)-'0';
			int tmp=baseDigit*singleDigit+acc;
			acc=tmp/10;
			int resDigit=tmp%10;
			res.append(resDigit);
		}
		if(acc>0)
			res.append(acc);
		res.reverse();
		while(shift>0){
			res.append('0');
			shift--;
		}
		return res.toString();

	}
	public String stringSum(String num1,String num2){
		int minLen=Math.min(num1.length(),num2.length());
		int i=0;
		int acc=0;
		StringBuilder res=new StringBuilder();
		for(i=1;i<=minLen;i++){
			int tmp=num1.charAt(num1.length()-i)-'0'+num2.charAt(num2.length()-i)-'0'+acc;
			acc=tmp/10;
			int resDigit=tmp%10;
			res.append(resDigit);
		}
		
		for(i=num1.length()-minLen-1;i>=0;i--){
			int tmp=num1.charAt(i)+acc-'0';
			int resDigit=tmp%10;
			acc= tmp/10;
			res.append(resDigit);
		}

		for(i=num2.length()-minLen-1;i>=0;i--){
			int tmp=num2.charAt(i)+acc-'0';
			int resDigit=tmp%10;
			acc= tmp/10;
			res.append(resDigit);
		}
		if(acc>0)
			res.append(acc);
		return res.reverse().toString();
		
	}
	public String multiply(String num1, String num2) {
		String tmp="0";
		for(int i=num2.length()-1;i>=0;i--){
			String layer=singleMultiply(num1,num2,i,num2.length()-i-1);
			System.out.println(layer);
			tmp=stringSum(layer,tmp);
		}
		return tmp;
	}
	public static void main(String[] args){
		Solution sol=new Solution();
		System.out.println(sol.multiply("123","456"));
	}
}
