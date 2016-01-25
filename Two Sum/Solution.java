import java.util.*;
public class Solution {
	public int[] twoSum(int[] nums, int target) {
		int[] origin= nums.clone();
		Arrays.sort(nums);
		int[] res=new int[2];
		int begin=0,end=nums.length-1;
		while(begin<end){
			if(nums[begin]+nums[end]==target){
				int first=nums[begin];
				int second=nums[end];
				int index=0;
				for(int i=0;i<nums.length;i++)
					if(first==origin[i]){
						index=i;
						res[0]=i+1;
						break;
					}
				for(int i=0;i<nums.length;i++){
					if(second==origin[i] && index!=i){
						res[1]=i+1;
						break;
					}
				}
				break;
			}else if(nums[begin]+nums[end]<target){
				begin+=1;
			}else
				end--;
		}
		if(res[0]>res[1]){
			int tmp=res[0];
			res[0]=res[1];
			res[1]=tmp;
		}
		return res;
	}
}
