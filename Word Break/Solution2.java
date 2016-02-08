public class Solution {
	public boolean wordBreak(String s, Set<String> wordDict) {
		boolean[] dp= new boolean[s.length()+1];
		dp[0]=true;
		for(int i=0;i<s.length();i++){
			for(int j=i;j>=0;j--){
			    //System.out.println(i);
				if(dp[i-j]){
					String sub=s.substring(i-j,i+1);
					if(wordDict.contains(sub)){
						dp[i+1]=true;
						break;
					}
				
				}
			}
		}
		return dp[s.length()];
	}
}
