public class Solution {
	public int searchInsert(int[] nums, int target) {
		int left=0;
		int right= nums.length;
		while(left<right-1){
			int mid = left+(right-left)/2;
			if(nums[mid]>target){
				right=mid;
			}else if(nums[mid]<target){
				left=mid;
			}else{
				return mid;
			}
		}
		if(nums[left]<target)
		    return right;
		else
		    return left;
	}
}
