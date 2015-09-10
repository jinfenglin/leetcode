import java.util.*;
public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {
	    boolean [] dp= new boolean[s.length()+1];
	    dp[0]=true;
	    for(int i=1;i<s.length();i++)
		    dp[i]=false;
	    for(int i=0;i<=s.length();i++)
	    {
		    for(int j=0;j<i;j++){
	    		String tmp=s.substring(j,i);
			if(dp[i]==true)
				break;
			dp[i]=(dp[j] & wordDict.contains(tmp));		
		    }
	    }
	    return dp[s.length()];
    }
    /*public static void main(String[] args){
	    Solution sol=new Solution();
	    Set<String> dict=new HashSet<String>();
	    dict.add("leet");
	    dict.add("code");
	    System.out.println(sol.wordBreak("leetcode",dict));

    }*/
}
