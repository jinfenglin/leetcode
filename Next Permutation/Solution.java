public class Solution {
	public void nextPermutation(int[] nums) {
		int parIndex=0;
		int changeInde=0;
		for(int i=nums.length-1;i>=0;i--){
			if(i==nums.length-1)
				continue;
			fi(nums[i]<nums[i-1]){
				parIndex=i;
				break;
			}
		}
		for(int i=nums.length-1;i>parIndex;i--){
			if(nums[i]>nums[parIndex]){
				changeIndex=i;
				break;
			}
		}
		swap(nums,parIndex,changeIndex);
		Arrays.sort(nums,changeIndex,nums.length-1);
	}
	public void swap(int[] nums,int i,int j){
		int tmp=nums[i];
		nums[i]=nums[j];
		nums[j]=tmp;
	}
}
