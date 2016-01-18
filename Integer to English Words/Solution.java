public class Solution {
	private String[] levels={"Billion","Million","Thousand"};
	private String[] tens={"Ninety","Eighty","Seventy","Sixty","Fifty","Forty","Thirty","Twenty"};
	private String[] toTwenty={"Nineteen","Eighteen","Seventeen","Sixteen","Fifteen","Fourteen","Thirteen","Twelve","Eleven","Ten"};
	private String[] lessTen={"Nine","Eight","Seven","Six","Five","Four","Three","Two","One"};
	private String chunkToWords(int num){
		String res="";
		int hundredDigit,tenDigit,singleDigit;
		hundredDigit=num/100;
		num%=100;
		tenDigit=num/10;
		singleDigit=num%10;
		if(hundredDigit>0){
			res+=lessTen[9-hundredDigit]+" Hundred ";
		}
		if(tenDigit>1){
			res+=tens[9-tenDigit]+" ";
			if(singleDigit>0)
				res+=lessTen[9-singleDigit]+" ";
		}else if(tenDigit==1){
			res+=toTwenty[9-singleDigit]+" ";
		}else if(singleDigit>0){
			res+=lessTen[9-singleDigit]+" ";
		}
		return res.trim();
		
	}
	public String numberToWords(int num) {
		StringBuilder sb= new StringBuilder();
		int level=0;
		if(num==0)
			return "Zero";
		int i=0;
		while(num>0){
			int chunk=num%1000;
			num/=1000;
			String chunkWord=chunkToWords(chunk);
			if(chunkWord.length()>0){
				if(i>0)
					chunkWord+=" "+levels[3-i];
				sb.insert(0,chunkWord+" ");
			}
			i++;
		}
		return sb.toString().trim();
	
	}
	public static void main(String[] args){
		Solution sol=new Solution();
		System.out.println(sol.numberToWords(1000010));
	}
}
