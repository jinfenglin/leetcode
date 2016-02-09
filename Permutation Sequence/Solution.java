public class Solution {
	public String getPermutation(int n, int k) {
		int pmtCount=1;
		StringBuilder res=new StringBuilder();
		int[] nums=new int[n];
		for(int i=0;i<n;i++){
			nums[i]=i+1;
		}
		for(int i=1;i<=n;i++){
			pmtCount*=i;
		}
		k--;
		for(int i=n;i>=1;i--){
			pmtCount/=i;
			int index=k/pmtCount;
			int move=-1;
			//System.out.println(index);
			while(index>=0){
			    if(nums[move+1]!=0){
			        index--;
			    }
			    move++;
			}
			res.append(nums[move]);
			nums[move]=0;
			k=k%pmtCount;
		}
		return res.toString();
	}
}
