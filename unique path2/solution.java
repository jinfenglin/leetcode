c class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
            int rows=obstacleGrid.length;
	            if(rows==0)
		                return 0;
				        int cols=obstacleGrid[0].length;
					        if(cols==0)
						            return 0;
							            int[][] dp = new int[rows][cols];
								            dp[0][0]= obstacleGrid[0][0]==1? 0:1;
									            for(int i=1;i<rows;i++){
										                dp[i][0]= (dp[i-1][0]==1 && obstacleGrid[i][0]!=1)? 1:0;
												        }
													        for(int i=1;i<cols;i++){
														            dp[0][i]= (dp[0][i-1]==1 && obstacleGrid[0][i]!=1)? 1:0;
															            }
																            
																	            for(int i=1;i<rows;i++){
																		                for(int j=1;j<cols;j++){
																				                if(obstacleGrid[i][j]==1)
																						                    dp[i][j]=0;
																								                    else
																										                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
																													            }
																														            }
																															            return dp[rows-1][cols-1];
																																        }
																																	}
