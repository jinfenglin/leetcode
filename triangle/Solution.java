public class Solution {
	public int minimumTotal(List<List<Integer>> triangle) {
		int rows= triangle.size();
		int[] dp= new int[rows];
		int[] tmp = new int[rows]; 
		if(rows==0)
			return 0;
		dp[0]=triangle.get(0).get(0);

		for(int i=1;i<rows;i++){
			List<Integer> row = triangle.get(i);
			for(int j=0;j<row.size();j++){
				if(j==0){
					tmp[j]=dp[j]+row.get(j);
				}
				else if(j>0 && j<row.size()-1){
					tmp[j]= Math.min(dp[j]+row.get(j),dp[j-1]+row.get(j));
				}else
					tmp[j]=dp[j-1]+row.get(j);
			}
			dp=tmp;
			tmp = new int[rowsß];
		}
		int min=dp[0];
		for(int num:dp){
			
			min=Math.min(min,num);
		}
		return min;
	}
}
