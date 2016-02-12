public class Solution {
	public int minSubArrayLen(int s, int[] nums) {
		int bot=0,top=0;
		int sum=0,windowLen=0;
		int res=Integer.MAX_VALUE;
		while(top<nums.length || sum>=s){
			while(sum<s && top<nums.length){
				//expand window
				sum+=nums[top];
				top++;
				windowLen++;
			}
			//System.out.println(windowLen);
			if(sum<s && top==nums.length)
			    break;
			while(sum>=s){
				//shrink window
				sum-=nums[bot];
				bot++;
				windowLen--;
			}
			//System.out.println("--"+windowLen);
			res=Math.min(res,windowLen+1);
		}
		return res==Integer.MAX_VALUE?0:res;
	}
}

