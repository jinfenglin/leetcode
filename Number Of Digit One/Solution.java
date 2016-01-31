public class Solution {
	public int countDigitOne(int n) {
		int count=0;
		for(int k=1;k<n;k*=10){
			int r=n/k;
			int m=n%k;
			count+= (r+8)/10*k+(r%k==1)? m+1:0; 
		}
		return count;
	}
}
