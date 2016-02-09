public class Solution {
	public int coinChange(int[] coins, int amount) {
		int coinType=coins.length;
		int[] dp = new int[amount+1];
		for(int i=0;i<amount+1;i++)
			dp[i]=Integer.MAX_VALUE;
		dp[0]=0;
		for(int i=0;i<=amount;i++){
			for(int j=0;j<coinType;j++){
				if(i-coins[j]<0 || dp[i-coins[j]]==Integer.MAX_VALUE)
					continue;
				dp[i]=Math.min(dp[i-coins[j]]+1,dp[i]);
			}
		}
		//System.out.println(dp[amount]);
		return dp[amount]==Integer.MAX_VALUE?-1:dp[amount];
	}
}
