c class Solution {
    public int countPrimes(int n) {
            boolean[] dp = new boolean[n];
	            int count=0;
		            for(int i=0;i<n;i++)
			                dp[i] = true;
					        for(int i=2;i<n;i++){
						            if(dp[i]){
							                    count++;
									                    int tagIndex = i;
											                    while(tagIndex<n){
													                        dp[tagIndex]=false;
																                    tagIndex+=i;
																		                    }
																				                }
																						        }
																							        return count;
																								    }
																								    }
