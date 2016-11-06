public class Solution {
    public int integerReplacement(int n) {
	    int count =0;
	 while(n!=1){
		count++;
	 	int lastDigit = n&1;
		int lastSecDigit = n&2;
		if(lastDigit == 1){
			if(lastSecDigit == 1 && n!=3){
				n+=1;
			}else{
				n-=1;
			}	
		}else{
			n>>=1;
		}

	 }   
    }
}
