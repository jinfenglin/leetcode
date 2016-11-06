c class Solution {
    public boolean canPartition(int[] nums) {
            int sum = 0;
	            for(int i=0;i<nums.length;i++){
		                sum+=nums[i];
				        }
					        if(sum%2 !=0)
						            return false;
							            sum/=2;
								            boolean[] dp = new boolean[sum+1];
									            dp[0] = true;
										            for(int i=0;i<nums.length;i++){
											                boolean[] tmp = new boolean[sum+1];
													            for(int j=0;j<dp.length;j++){
														                    if(dp[j] && j+nums[i]<=sum){
																                        tmp[j+nums[i]] = true;
																			                }
																					            }
																						                for(int j=0;j<dp.length;j++)
																								                if(tmp[j])
																										                    dp[j]=true;
																												            }
																													            return dp[sum];
																														        }
																															}
