import java.util.*;
public class Solution {
	public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
		TreeSet<Integer> set =new TreeSet<Integer>();
		if(k<1 || t<0 || nums.length==0)
			return false;
		for(int i=0;i<nums.length;i++){
			if(set.floor(nums[i])!=null && nums[i]<set.floor(nums[i])+t || set.ceiling(nums[i])!=null && set.ceiling(nums[i])-t<=nums[i])
					return true;
			set.add(nums[i]);
			if(i>=k)
				set.remove(nums[i-k]);
		}
		return false;
	}

}
