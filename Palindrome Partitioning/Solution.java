public class Solution {
	public List<List<String>> partition(String s) {
		List<List<String>> res=new ArrayList<List<String>>();
		if(s.length==0)
			return res;
		boolean[][] dp=new boolean[s.length()][s.length()];
		for(int i=0;i<s.length();i++){
			for(int j=0;j<s.length;j++){
				if(s.charAt(i)==s.charAt(j)&& (dp[j+1][i-1] || i-j<=2))
					dp[i][j]=true;
			}
		}
		return DFS(s,dp,0);
	}
	public List<List<String>> DFS(String s,boolean[][] dp,int start){
		List<List<String>> res=new ArrayList<List<String>>();
		if(start==s.length()){
			res.add(new ArrayList<String>());
			return res;
		}
		for(int i=start;i<s.length();i++){
			if(dp[start][i]){
				List<List<String>> tmp=DFS(s,dp,i+1);
				for(List<String> sol:tmp){
					tmp.add(s.substring(start,i+1));
					res.add(tmp);
				}
			}
		}
		return res;
	}
}
