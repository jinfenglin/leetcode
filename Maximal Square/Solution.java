public class Solution {
	int xLen,yLen;
	public int maximalSquare(char[][] matrix) {
		xLen=matrix.length;
		if(xLen>0)
			yLen=matrix[0].length;
		else
			return 0;
		int max=0;
		int[][] dp= new int[xLen][yLen];
		for(int i=0;i<xLen;i++){
			if(matrix[i][0]=='1'){
				dp[i][0]=1;
				max=1;
			}
			else
				dp[i][0]=0;
		}
		for(int i=0;i<yLen;i++){
			if(matrix[0][i]=='1'){
				dp[0][i]=1;
			    max=1;
			}
			else
				dp[0][i]=0;
		}
		for(int i=1;i<xLen;i++)
			for(int j=1;j<yLen;j++){
			    if(matrix[i][j]=='1')
				    dp[i][j]=Math.min(Math.min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
				else
				    dp[i][j]=0;
				if(dp[i][j]>max)
				    max=dp[i][j];
		}
		return max*max;
	}
}
