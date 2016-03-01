public class Solution {
	public int threeSumClosest(int[] nums, int target) {
		int diff=Integer.MAX_VALUE;
		Arrays.sort(nums);
		for(int i=0;i<nums.length-1;i++){
			int left=i+1;
			int right=nums.length-1;
			while(left<right){
			    //System.out.println(left+" "+right);
				int tmpDiff=target-nums[i]-nums[left]-nums[right];
				if(Math.abs(diff)>Math.abs(tmpDiff))
				    diff=tmpDiff;
				if(tmpDiff>0)
					left++;
				else if(tmpDiff<0)
					right--;
				else
				    return target;
			}
		}
		return target-diff;
	}
}
