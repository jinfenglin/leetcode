import java.util.*;
public class Solution {
	private String reversedPolish(String s){
		String res="";
		Stack<Character> sign=new Stack<Character>();
		int num=0;
		for(int i=0;i<s.length();i++){
			switch(s.charAt(i)){
				case '+':
					while(!sign.empty() && sign.peek()!='('){
						res+=sign.peek();
						sign.pop();
					}
					sign.push('+');
					res+=' ';
					break;
				case '-':
					while(!sign.empty() && sign.peek()!='('){
						res+=sign.peek();
						sign.pop();
					}
					sign.push('-');
					res+=' ';
					break;

				case '(':
					sign.push('(');
					break;
				case ')':
					while(!sign.empty() && sign.peek()!='('){
						res+=sign.peek();
						sign.pop();
					}
					sign.pop();
					break;
				case '*':
					while(!sign.empty() && (sign.peek()=='*' || sign.peek()=='/')){
						res+=sign.peek();
						sign.pop();
					}
					sign.push('*');
					res+=' ';
					break;
				case '/':
					while(!sign.empty() && (sign.peek()=='*' || sign.peek()=='/')){
						res+=sign.peek();
						sign.pop();
					}
					sign.push('/');
					res+=' ';
					break;
				case ' ':
					break;
				default:
					res+=s.charAt(i);
			}
		}	
		while(!sign.empty()){
			res+=sign.peek();
			sign.pop();
		}
		return res;
	}
	private int calReversedPolish(String s){
		Stack<Integer> num=new Stack<Integer>();
		Stack<Character> sign=new Stack<Character>();
		int tmp=0;
		for(int i=0;i<s.length();i++){
			char ch= s.charAt(i);
			if(ch>='0' && ch<='9'){
				tmp*=10;
				tmp+=ch-'0';
			}
			else if(ch==' '){
				if(s.charAt(i-1)<='9' && s.charAt(i-1)>='0')
					num.push(tmp);
				tmp=0;
			}
			else{
				int first;
				int second;

				if(s.charAt(i-1)<='9' && s.charAt(i-1)>='0'){
					first=num.peek();
					num.pop();
					second=tmp;
				}
				else{
					second=num.peek();
					num.pop();
					first=num.peek();
					num.pop();
				}
				tmp=0;
				if(ch=='+'){
					num.push(first+second);	
				}
				else if(ch=='-'){
					num.push(first-second);
				}
				else if(ch=='*'){
					num.push(first*second);
				}else if(ch=='/'){
					num.push(first/second);
				}
			}
		}
		return num.peek();
	}
	public int calculate(String s) {
		return calReversedPolish(reversedPolish(s));	
		
	}
	public static void main(String[] args){
		Solution sol=new Solution();
		System.out.println(sol.calculate("100+2-(4+5)/6"));
	}
}
