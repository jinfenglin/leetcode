import java.utils.*;
public class Solution {
    public int divide(int dividend, int divisor) {
	    boolean sign= (dividend>0 && divisor>0) || (dividend<0 && divisor<0);
	    long dived= Math.abs((long)dividend);
	    long diver= Math.abs((long) divisor) ;
	    int res=0;
	    while(diver<=dived){
		    long tmp= diver;
		    int i=0;
		    for(;tmp<=dived;i++){
		    	tmp<<=1;
		    }
		    long overflow=(long)res + Math.abs((long)(1<<(i-1)));

		    if(overflow>Integer.MAX_VALUE && sign)
				    return Integer.MAX_VALUE;
		    res+=(1<<(i-1));
		    dived-= (tmp>>1);
	    }
	    return sign? res:-res;
    }

}
