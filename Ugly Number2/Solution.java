public class Solution {
	public int nthUglyNumber(int n) {
		int c1=0,c2=0,c3=0;
		List<Integer> uglys=new ArrayList<Integer>();
		uglys.add(1);
		int min=1;
		for(int i=1;i<n;i++){
			int n1=uglys.get(c1)*2;
			int n2=uglys.get(c2)*3;
			int n3=uglys.get(c3)*5;
			min=Math.min(n3,Math.min(n1,n2));
			if(min==n1)
				c1++;
			if(min==n2)
				c2++;
			if(min==n3)
				c3++;
			uglys.add(min);
		}
		return min;
	}
}
