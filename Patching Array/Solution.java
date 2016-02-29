public class Solution {
	public int minPatches(int[] nums, int n) {
	    long sum=1;
		int count=0;
		int i=0;
		while(sum<=n){
			if(i<nums.length && sum>=nums[i]){
				sum+=nums[i];
				i++;
			}else{
			    count++;
			    sum*=2;
			}
		}
		return count;
	}
}
