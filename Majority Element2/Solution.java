public class Solution{
	public List<Integer> majorityElement(int[] nums){
		int m1=0,m2=0;
		int count1=0,count2=0;
		List<Integer> res=new ArrayList<Integer>();
		for(int n:nums){
			if(count1==0 && m2!=n)
				m1=n;
			else if(count2==0 && m1!=n)
				m2=n;
			if(m1==n){
				count1++;
			}else if(m2==n){
				count2++;
			}else{
				count1--;
				count2--;
			}
		}
		count1=0;
		count2=0;
		for(int n:nums){
			if(n==m1)
				count1++;
			else if(n==m2)
				count2++;
		}
		System.out.println(m1+" "+m2);
		int n=nums.length;
		if(count1>n/3)
			res.add(m1);
		if(count2>n/3)
			res.add(m2);
		return res;
	}
}


