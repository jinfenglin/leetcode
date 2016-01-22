import java.util.*;
public class Solution {
	public List<List<Integer>> twoSum(int[] nums,int start,int end,int target){
		int left,right;
		List<List<Integer>> res = new ArrayList<List<Integer>>();
		left=start;
		right=end;
		//System.out.println(left+" "+right);
		while(left<right){
			int lnum,rnum;		
			lnum=nums[left];
			rnum=nums[right];
			if(lnum+rnum==target){
				List<Integer> tmp= new ArrayList<Integer>();
				tmp.add(-target);
				tmp.add(lnum);
				tmp.add(rnum);
				res.add(tmp);
				left++;
				right--;
				while(left<right && nums[left]==nums[left-1])
					left++;
				while(left<right && nums[right]==nums[right+1])
					right--;
			}else if(lnum+rnum<target){
				left++;
			}else{
				right--;
			}
		}
		return res;
	}

	public List<List<Integer>> threeSum(int[] nums) {
		Arrays.sort(nums);
		List<List<Integer>> res= new ArrayList<List<Integer>>();
		for(int i=0;i<nums.length-2;){
			res.addAll(twoSum(nums,i+1,nums.length-1,-nums[i]));
			i++;
			while(i<nums.length && nums[i]==nums[i-1])
				i++;
		}
		return res;
	}
	public static void main(String[] args){
		int[] nums={-1,0,1,2,-1,-4};
		Solution sol=new Solution();
		List<List<Integer>> res=sol.threeSum(nums);
		for(List<Integer> tmp:res){
			for(Integer num:tmp){
				System.out.print(num);
			}
			System.out.println("");
		}
	}

}
