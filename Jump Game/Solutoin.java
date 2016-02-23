public class Solution {
	public boolean canJump(int[] nums) {
		int range=0;
		for(int i=0;i<nums.length;i++){
			if(range>=nums.length-1)
				return true;
			if(i>range)
			    return false;
			if(nums[i]+i>range)
				range=nums[i]+i;
		}
		return false;
	}
}
