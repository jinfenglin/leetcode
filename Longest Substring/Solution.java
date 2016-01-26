public class Solution {
	public int lengthOfLongestSubstring(String s) {
		Set<Character> window= new HashSet<Character>();
		int slow=0,fast=0;
		int max=0;
		for(;fast<s.length();fast++){
			char c=s.charAt(fast);
			while(window.contains(c)){
				char rc=s.charAt(slow++);
				window.remove(rc);
			}
			window.add(c);
			//System.out.println(c+" "+window.size());
			max=Math.max(window.size(),max);
		}
		return max;
	}

}
