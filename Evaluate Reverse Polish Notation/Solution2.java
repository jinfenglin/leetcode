public class Solution {
	public int evalRPN(String[] tokens) {
		Stack<Integer> numStk=new Stack<Integer>();
		int sum=0;
		for(String str:tokens){
			if(str.equals("+")){
			    int first=numStk.peek();
			    numStk.pop();
			    int second=numStk.peek();
			    numStk.pop();
			    numStk.push(first+second);
			}else if(str.equals("-")){
			    			    int first=numStk.peek();
			    numStk.pop();
			    int second=numStk.peek();
			    numStk.pop();
				numStk.push(second-first);
			}else if(str.equals("*")){
			    			    int first=numStk.peek();
			    numStk.pop();
			    int second=numStk.peek();
			    numStk.pop();
				numStk.push(first*second);
			}else if(str.equals("/")){
			    int first=numStk.peek();
			    numStk.pop();
			    int second=numStk.peek();
			    numStk.pop();
				numStk.push(second/first);
			}else{
				int num=Integer.parseInt(str);
				numStk.push(num);
			}
		}
		return numStk.peek();
	}
}

