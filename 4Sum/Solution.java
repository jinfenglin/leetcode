import java.util.*;
public class Solution {
	public List<List<Integer>> threeSum(int[] nums,int start,int target){
		List<List<Integer>> res=new ArrayList<List<Integer>>();
		for(int i=start;i<nums.length;i++){
			while(i>start && i<nums.length && nums[i]==nums[i-1])
				i++;
			List<List<Integer>> tmp= new ArrayList<List<Integer>>();
			if(i>=nums.length)
				return res;
			tmp=twoSum(nums,i+1,target-nums[i]);
			for(List<Integer> list:tmp){
				list.add(0,nums[i]);
				res.add(list);
			}
		}	
		return res;
	}
	public List<List<Integer>> twoSum(int[] nums,int start,int target){
		List<List<Integer>> res=new ArrayList<List<Integer>>();
		int end=nums.length-1;
		while(start<end){
			if(nums[start]+nums[end]<target){
				start++;
			}else if(nums[start]+nums[end]>target){
				end--;
			}else{
				List<Integer> tmp=new ArrayList<Integer>();
				tmp.add(nums[start]);
				tmp.add(nums[end]);
				res.add(tmp);
				start++;
				end--;
				while(start<end && nums[start]==nums[start-1])
					start++;
				while(start<end && nums[end]==nums[end+1])
					end--;
			}
		}
		return res;
	}
	public List<List<Integer>> fourSum(int[] nums, int target) {
		Arrays.sort(nums);
		List<List<Integer>> res=new ArrayList<List<Integer>>();
		if(nums.length<4)
			return res;
		for(int i=0;i<nums.length;i++){
			while(i>0 && i<nums.length && nums[i]==nums[i-1])
				i++;
			List<List<Integer>> tmp=new ArrayList<List<Integer>>();
			if(i>=nums.length)
				return res;
			tmp=threeSum(nums,i+1,target-nums[i]);
			for(List<Integer> list:tmp){
				list.add(0,nums[i]);
				res.add(list);
			}
		}
		return res;
	}
}

