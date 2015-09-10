import java.util.*;
public class Solution {
	public List<String> wordBreak(String s, Set<String> wordDict) {
		int len=s.length();
		boolean [] dp= new boolean[len+1];
		for(int i=0;i<=len;i++)
			dp[i]=false;
		/*dp[0]=true;
		  for(int i=0;i<=len;i++){
		  for(int j=0;j<i;j++){				
		  dp[i]=dp[j] & wordDict.contains(s.substring(j,i));
		  if(dp[i]==true)
		  break;

		  }
		  }*/
		boolean[] D = new boolean[len + 1];
		D[len] = true;
		for (int i = len - 1; i >= 0; i--) {
			for (int j = i; j <= len - 1; j++) {
				// 左边从i 到 j
				D[i] = false;
				if (D[j + 1] && wordDict.contains(s.substring(i, j + 1))) {
					D[i] = true;
					break;
				}
			}
		}
		List<String> res=new ArrayList<String>();
		DFS(res,new ArrayList<String>(),s,0,len,wordDict,D);
		return res;
	}
	public void DFS(List<String> result,ArrayList<String> solution,String s,int start,int end,Set<String> wordDict,boolean [] dp){
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
	public static void main(String[] args){
		Set<String> wordDict= new HashSet<String>();
		wordDict.add("a");
		wordDict.add("aa");
		wordDict.add("leet");
		wordDict.add("code");
		Solution sol=new Solution();
		List<String> res=sol.wordBreak("aaaaaaaa",wordDict);
		for(int i=0;i<res.size();i++)
			System.out.println(res.get(i));
	}
}
