c class Solution {
    public int thirdMax(int[] nums) {
            int l=Integer.MIN_VALUE,m=Integer.MIN_VALUE,s=Integer.MIN_VALUE;
	            Set<Integer> numSet = new HashSet<Integer>();
		            for(int i=0;i<nums.length;i++){
			                numSet.add(nums[i]);
					            if(nums[i]>=l){
						                    if(nums[i]==l)
								                        continue;
											                s=m;
													                m=l;
															                l=nums[i];
																	            }else if(nums[i]>=m){
																		                    if(nums[i]==m)
																				                        continue;
																							                s=m;
																									                m=nums[i];
																											            }else if(nums[i]>s){
																												                    s=nums[i];
																														                }
																																        }
																																	        if(numSet.size()<3)
																																		            return l;
																																			            return s;
																																				        }
																																					}
