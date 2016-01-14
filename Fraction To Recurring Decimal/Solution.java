import java.util.*;
import java.lang.StringBuilder;
public class Solution {
    public String fractionToDecimal(int n, int d) {
	   long numerator=(long )n;
	   long denominator=(long) d;
	   StringBuilder sb = new StringBuilder(); 
	   boolean sign=true;
	   if((numerator>0 && denominator<0) || (numerator<0 && denominator>0))
		   sign=false;
	   numerator=Math.abs(numerator);
	   denominator=Math.abs(denominator);
	   long intNum=numerator/denominator;
	   numerator=numerator%denominator;
	   if(numerator==0)
		   return Long.toString(intNum);

	   sb.append(Long.toString(intNum)+".");
	   HashMap<Long,Integer> map= new HashMap<Long,Integer>();
	   int index=0;
	   while(numerator!=0){
		   if(map.containsKey(numerator)){
		   	int begin_index=map.get(numerator)+2;
			sb.insert(begin_index,'(');
			sb.append(')');
			break;
		   }
		   map.put(numerator,index);
		   long num=numerator*10/denominator;
		   numerator=(numerator*10)%denominator;
		   System.out.println(numerator);
		   index+=1;
		   sb.append(num);
	   }
	   
	   if(!sign)
		   sb.insert(0,'-');
	   return sb.toString();
    }
    public static void main(String[] args){
	    Solution sol= new Solution();
	    System.out.println(sol.fractionToDecimal(-1,-214783648));
    	
    }
}
