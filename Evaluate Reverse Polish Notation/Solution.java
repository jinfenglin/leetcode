import java.util.*;
public class Solution {
	public int evalRPN(String[] tokens) {
		Stack<Integer> stk=new Stack<Integer>();
		stk.push(Integer.parseInt(tokens[0]));
		int cur=1;
		while(!stk.isEmpty() & cur<tokens.length){
			int v1;
			int v2;
			switch(tokens[cur]){
				case "+":v1=stk.pop();v2=stk.pop(); stk.push(v1+v2);break;
				case "-":v1=stk.pop();v2=stk.pop(); stk.push(v2-v1);break;
				case "*":v1=stk.pop();v2=stk.pop(); stk.push(v1*v2);break;
				case "/":v1=stk.pop();v2=stk.pop(); stk.push(v2/v1);break;
				default:
					 stk.push(Integer.parseInt(tokens[cur]));
			}
			cur++;
		}
		return stk.pop();
	}
}
