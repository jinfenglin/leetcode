import java.util.*;
public class Solution {
	private int weight(char sign){
		switch(sign){
			case '+': return 1;
			case '-': return 1;
			case '*': return 2;
			case '/': return 2;
		}
		return -1;
	
	}
	public String RPS(String s){
		Stack<Character> signStk=new Stack<Character>(); 
		StringBuilder tmp=new StringBuilder();
		StringBuilder res=new StringBuilder();
		for(int i=0;i<s.length();i++){
			char c=s.charAt(i);
			if(c==' '){
				continue;
			}else if(c<='9' && c>='0'){
				tmp.append(c);
			}else{
				if(tmp.length()>0){
					tmp.append(" ");
					res.append(tmp.toString());	
				}
				tmp.setLength(0);
				if(c=='('){
					signStk.push(c);
				}else if(c==')'){
					while(!signStk.empty() && signStk.peek()!='('){
						res.append(signStk.peek());
						res.append(" ");
						signStk.pop();
					}
					signStk.pop();
				}else{
					while(!signStk.empty() && weight(signStk.peek())>=weight(c)){
						res.append(signStk.peek());
						res.append(" ");
						signStk.pop();
					}
					signStk.push(c);
				}
			}
		}
		if(tmp.length()>0)
			res.append(tmp.toString()+" ");
		while(!signStk.empty()){
			res.append(signStk.peek());
			res.append(" ");
			signStk.pop();
		}
		return res.toString();
	}
	public int calRPS(String[] tokens){
		Stack<Integer> numStk=new Stack<Integer>();
		for(String s:tokens){
			if(s.equals("+")){
				int second=numStk.peek();
				numStk.pop();
				int first=numStk.peek();
				numStk.pop();
				numStk.push(first+second);
			}else if(s.equals("-")){
				int second=numStk.peek();
				numStk.pop();
				int first=numStk.peek();
				numStk.pop();
				numStk.push(first-second);
			}else if(s.equals("*")){
				int second=numStk.peek();
				numStk.pop();
				int first=numStk.peek();
				numStk.pop();
				numStk.push(first*second);
			}else if(s.equals("/")){
				int second=numStk.peek();
				numStk.pop();
				int first=numStk.peek();
				numStk.pop();
				numStk.push(first/second);

			}else{
				numStk.push(Integer.parseInt(s));
			}	
				
			//System.out.println("peek:"+numStk.peek());
		}
		return numStk.peek();
	}
	public int calculate(String s) {
		String rps=RPS(s);
		String[] tokens=rps.split("\\s");
		return calRPS(tokens);
	}
	public static void main(String[] args){
		Solution sol=new Solution();
		sol.calculate("1+22/(10+12)-(4*0)");
	}
}
