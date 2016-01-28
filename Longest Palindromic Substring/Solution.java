public class Solution {
	private boolean dp[][];
	public String longestPalindrome(String s) {
	    if(s.length()==1)
	        return s;
		int len=s.length();
		String res="";
		dp=new boolean[len][len];
		for(int i=0;i<len;i++){
			dp[i][i]=true;
			if(i<len-1 && s.charAt(i)==s.charAt(i+1)){
			    dp[i][i+1]=true;
			    res=s.substring(i,i+2);
			}
				
		}
		//printTable(dp);
		for(int i=3;i<=len;i++)
			for(int j=0;j<=len-i;j++){
				int end=j+i-1;
				if(dp[j+1][end-1] && s.charAt(j)==s.charAt(end)){
					dp[j][end]=true;
					if(i>res.length())
						res=s.substring(j,end+1);
				}
			}
		//printTable(dp);
		return res;
	}
}

