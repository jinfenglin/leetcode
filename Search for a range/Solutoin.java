public class Solution {
	public int searchLeft(int[] nums,int target){
		if(nums.length==0)
			return -1;
		int start=0,end=nums.length-1;
		while(end-start>1){
			int mid=start+(end-start)/2;
			if(nums[mid]>=target){
				end=mid;
			}else{
				start=mid;
			}
		}
		if(nums[end]!=target && nums[start]!=target)
			return -1;
		else if(nums[start]==target)
			return start;
		else
		    return end;
	}
	public int searchRight(int[] nums,int target){
		if(nums.length==0)
			return -1;
		int start=0,end=nums.length-1;
		while(end-start>1){
			int mid=start+(end-start)/2;
			if(nums[mid]<=target){
				start=mid;
			}else{
				end=mid;
			}
		}
		if(nums[start]!=target && nums[end]!=target)
			return -1;
		else if(nums[end]==target)
			return end;
		else
		    return start;


	}
	public int[] searchRange(int[] nums, int target) {
		int left=searchLeft(nums,target);
		int right=searchRight(nums,target);
		return new int[]{left,right};
	}
}

