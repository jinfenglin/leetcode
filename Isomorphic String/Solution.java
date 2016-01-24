import java.util.*;
public class Solution {
	public boolean isIsomorphic(String s, String t) {
		Map<Character,Character> source,target;
		source= new HashMap<Character,Character>();
		target= new HashMap<Character,Character>();
		if(s.length()!=t.length())
			return false;
		for(int i=0;i<s.length();i++){
			if(source.get(s.charAt(i))!=null){
				if(source.get(s.charAt(i))!=t.charAt(i))
					return false;
			}
			else{
				source.put(s.charAt(i),t.charAt(i));
			}
		}
		for(int i=0;i<t.length();i++){
			if(target.get(t.charAt(i))!=null){
				if(target.get(t.charAt(i))!=s.charAt(i))
					return false;
			}
			else
				target.put(t.charAt(i),s.charAt(i));
		}
		return true;
	}
}
