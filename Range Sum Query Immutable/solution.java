c class NumArray {

    int[] accumArray;
        int[] nums;
	    public NumArray(int[] nums) {
	            this.nums=nums;
		            accumArray = new int[nums.length];
			            if(nums.length>0){
				            accumArray[0] = nums[0];
					            for(int i=1;i<nums.length;i++)
						                accumArray[i] = accumArray[i-1]+nums[i];
								            
									            }
										        }

											    public int sumRange(int i, int j) {
											            return accumArray[j] - accumArray[i] + nums[i];
												        }
													}
