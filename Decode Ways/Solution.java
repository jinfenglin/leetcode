import java.util.*;
public class Solution {
	public int numDecodings(String s) {
		int[] dp= new int[s.length()+1];
		dp[0]=1;
		if(s.length()>0 && s.charAt(0)!='0')
			dp[1]=1;
		for(int i=2;i<=s.length();i++){
			if(s.charAt(i-1)!='0')
				dp[i]+=dp[i-1];
			if((s.charAt(i-2)=='2' && s.charAt(i-1)<='6') || s.charAt(i-2)=='1')
				dp[i]+=dp[i-2];
			//for(int n:dp)
			//	System.out.print(n);
			//System.out.println("");
		}
		dp[0]=0;
		return dp[s.length()];
	}
	public static void main(String[] args){
		Solution sol= new Solution();
		System.out.println(sol.numDecodings("1000"));
	}
}
