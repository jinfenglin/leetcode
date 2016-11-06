public class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n+1];
        for(int i=1;i<=n;i++){
            if(dp[i]==0)
                dp[i] = Integer.MAX_VALUE;
            if(i*i<=n)
                dp[i*i]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i-j*j>=1)
                    dp[i] = Math.min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
}
