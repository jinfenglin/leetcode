public class Solution {
	public int maxProduct(int[] nums) {
		int max,min;
		if(nums.length==0)
			return 0;
		max=nums[0];
		min=nums[0];
		int res=nums[0];
		for(int i=1;i<nums.length;i++){
			int tmpS,tmpL;
			tmpL=max*nums[i];
			tmpS=min*nums[i];
			max=Math.max(tmpL,tmpS);
			min=Math.min(tmpL,tmpS);
			max=Math.max(nums[i],max);
			min=Math.min(nums[i],min);
			res=Math.max(res,max);

		}
		return res;
	}
}
