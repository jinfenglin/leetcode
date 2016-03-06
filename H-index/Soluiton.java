public class Solution {
	public int hIndex(int[] citations) {
		Integer[] cite=new Integer[citations.length];
		for(int i=0;i<citations.length;i++){
			cite[i]=citations[i];
		}
		Arrays.sort(cite,Collections.reverseOrder());
		int res=0;
		for(int i=0;i<citations.length;i++){
		    
			if(cite[i]<i+1){
				break;
			}
			res=i+1;
		}
		return res;
	}
}
