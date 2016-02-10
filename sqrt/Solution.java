public class Solution {
	public int mySqrt(int x) {
		if(x==0)
			return 0;
		int low=1,high=x;
		int mid=low+(high-low)/2;
		while(low<high-1){
			mid=low+(high-low)/2;
			if(mid*mid>x)
				high=mid-1;
			else if(mid*mid<x)
				low=mid+1;
			else
				return mid;
		}
		return low;
	}
}
