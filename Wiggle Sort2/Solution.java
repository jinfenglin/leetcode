import java.util.*;
public class Solution {
	public void wiggleSort(int[] nums) {
		Arrays.sort(nums);
		int[] tmp= new int[nums.length];
		int low=(nums.length+1)/2;
		int high=nums.length;
		for(int i=0;i<nums.length;i++){
			if(i%2==0){
				tmp[i]=nums[--low];
			} else{
				tmp[i]=nums[--high];
			}

		}		
		for(int i=0;i<nums.length;i++)
			nums[i]=tmp[i];
	}
	public static void main(String[] args){
		Solution sol=new Solution();
		int[] nums={4,4,5,6};
		sol.wiggleSort(nums);
		for(int num:nums)
			System.out.print(num);
		System.out.println("");
	}
}
