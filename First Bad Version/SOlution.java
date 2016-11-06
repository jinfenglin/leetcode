c class Solution extends VersionControl {
    public int firstBadVersion(int n) {
            int start=0,end=n;
	            while(start<end-1){
		                int mid = start+(end - start)/2;
				            if(isBadVersion(mid)){
					                    end = mid;
							                }else{
									                start = mid;
											            }
												            }
													            return end;
														        }
															}
