import java.util.*;
public class Solution {
	public int next(int n){
		int digit;
		int sum=0;
		while(n>0){
			digit=n%10;
			n=n/10;
			sum+=digit*digit;

		}
		return sum;
	}
	public boolean isHappy(int n) {
		Set<Integer> st= new HashSet<Integer>();
		while(!st.contains(n)){
			int new_one=next(n);
			st.add(n);
			n=new_one;
			if(n==1)
				return true;

		}
		return false;
	}
}
