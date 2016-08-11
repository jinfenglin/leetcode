class Solution {
	public int rangeBitwiseAnd(int m, int n) {
		int count=0;
		while(n>0){
			if(m==n)
				break;
			m>>=1;
			n>>=1;
			count++;
		}
		return m<<count;
	}

}
