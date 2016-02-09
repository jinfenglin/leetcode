public class Solution {
	public boolean isAdditiveNumber(String num) {
		//cutting the string into 3 segment
		if(num.length()<3)
			return false;
		for(int i=0;i<=num.length()-3;i++){
			String first= num.substring(0,i+1);
			if(!isNum(first))
				continue;

			for(int j=i+1;j<=num.length()-2;j++){
				String second=num.substring(i+1,j+1);
				if(!isNum(second))
					continue;
				if(validation(num,j+1,Integer.parseInt(first),Integer.parseInt(second)))
					return true;				
			}
		}
		return false;
	}
	public boolean isNum(String num){
		if(num.charAt(0)=='0' && num.length()>1)
			return false;
		return true;
	}
	public boolean validation(String num,int rest,int first,int second){
		//check if the sequence is validate
		if(rest==num.length())
			return true;
		int sumInt=first+second;
		String sum= Integer.toString(sumInt);
		
		if(sum.length()+rest>num.length())
			return false;
		for(int i=0;i<sum.length();i++){
			if(!(sum.charAt(i)==num.charAt(rest+i)))
				return false;
		}
		rest+=sum.length();
		return validation(num,rest,second,sumInt);
	}
}
