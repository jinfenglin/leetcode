import java.util.*;
public class Solution2 {
	public String reverseWords(String s) {
		StringBuilder res= new StringBuilder();
		String[] words= new StringBuilder(s).reverse().toString().split("\\s+");
		for(int i=0;i<words.length;i++){
			StringBuilder tmp=new StringBuilder(words[i].trim());
			res.append(tmp.reverse().toString());
			if(i<words.length-1 && tmp.length()>0)
				res.append(" ");
		}
		return res.toString();	
	}
	public static void main(String[] args){
		Solution2 sol= new Solution2();
		System.out.println(sol.reverseWords("1     "));
	}
}
