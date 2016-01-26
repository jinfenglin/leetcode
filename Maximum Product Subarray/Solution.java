public class Solution {
	public int maxProduct(int[] nums) {
		int[] max,min;
		if(nums.length==0)
			return 0;
		max=new int[nums.length];
		min=new int[nums.length];
		max[0]=nums[0];
		min[0]=nums[0];
		for(int i=1;i<nums.length;i++){
			max[i]=Math.max(max[i-1],Math.max(min[i-1]*nums[i],Math.max(max[i-1]*nums[i],nums[i])));
			min[i]=Math.min(min[i-1],Math.min(min[i-1]*nums[i],Math.min(min[i-1]*nums[i],nums[i])));
		}
		return max[nums.length-1];
	}
}
