import java.util.*;
public class Solution {
	public List<String> wordBreak(String s, Set<String> wordDict) {
		boolean [] dp= new boolean[s.length()+1];
		for(int i=0;i<=s.length();i++)
			dp[i]=false;
		dp[0]=true;
		for(int i=0;i<=s.length();i++){
			for(int j=0;j<i;j++){				
				dp[i]=dp[j] & wordDict.contains(s.substring(j,i));
				if(dp[i]==true)
					break;

			}
		}
		List<String> res=new ArrayList<String>();
		DFS(res,new ArrayList<String>(),s,0,s.length(),wordDict,dp);
		return res;
	}
	public void DFS(List<String> result,ArrayList<String> solution,String s,int start,int end,Set<String> wordDict,boolean [] dp){
		//System.out.println(solution);
		//System.out.println(Integer.toString(start)+" "+Integer.toString(end));
		if(start==end){
			StringBuilder sb=new StringBuilder();
			for(String str:solution)
			{
				sb.append(str);
				sb.append(" ");
			}
			sb.deleteCharAt(sb.length()-1);
			result.add(sb.toString());
			return;
		}
		if(!dp[start])
			return;
		for(int i=start;i<=end;i++){
				String tmp= s.substring(start,i);
				if(wordDict.contains(tmp)){
					solution.add(tmp);
					DFS(result,solution,s,i,end,wordDict,dp);
					solution.remove(solution.size()-1);
				}
		}
	}
	/*public static void main(String[] args){
		Set<String> wordDict= new HashSet<String>();
		wordDict.add("le");
		wordDict.add("et");
		wordDict.add("leet");
		wordDict.add("code");
		Solution sol=new Solution();
		List<String> res=sol.wordBreak("leetcode",wordDict);
		for(int i=0;i<res.size();i++)
			System.out.println(res.get(i));
	}*/
}
