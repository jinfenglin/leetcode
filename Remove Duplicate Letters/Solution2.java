import java.util.*;
public class Solution2 {
	public String removeDuplicateLetters(String s) {
		StringBuilder res=new StringBuilder();
		int optimal=0;
		Set<Character> visited=new HashSet<Character>();
		int[] countArray=new int[26];
		for(int i=0;i<s.length();i++){
			countArray[s.charAt(i)-'a']++;	
		}
		for(int i=0;i<s.length();i++){
			char c= s.charAt(i);
			if(res.length()==0){
				res.append(c);
				visited.add(c);
			}else if(!visited.contains(c)){
				char last=res.charAt(res.length()-1);
				while(c<last && countArray[last-'a']>0){
					res.deleteCharAt(res.length()-1);
					visited.remove(last);
					if(res.length()>0)
						last=res.charAt(res.length()-1);
					else
						break;

				}
				res.append(c);
				visited.add(c);
			}
			countArray[c-'a']--;
			
		}
		return res.toString();
	}
	public static void main(String[] args){
		Solution2 sol= new Solution2();
		System.out.println(sol.removeDuplicateLetters("bbcaac"));
	}
}

