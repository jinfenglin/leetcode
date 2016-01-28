public class Solution2 {
	public String multiply(String num1, String num2) {
		int m=num1.length(),n=num2.length();
		int[] res= new int[m+n];
		for(int i=m-1;i>=0;i--){
			for(int j=n-1;j>=0;j--){
				int tmp=(num1.charAt(i)-'0')*(num2.charAt(j)-'0');
				res[i+j]+=tmp/10;
				res[i+j+1]+=tmp%10;
			}
		}
		StringBuilder resStr=new StringBuilder();
		boolean highest=false;
		for(int num:res){
			if(highest || num!=0)
				resStr.append(num);
		}
		return resStr.length()>0? "0":resStr.toString();
	}
}
