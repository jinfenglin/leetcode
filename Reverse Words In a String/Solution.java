import java.util.*;
public class Solution {
    public String reverseWords(String s) {
	    String [] splits=s.trim().split(" +");
	    StringBuilder sb=new StringBuilder();
	    for(int i=splits.length-1;i>=0;i--){
	    	sb.append(splits[i]+" ");
	    }
	    System.out.println(sb.length());
	    if(sb.length()>0)
	    	sb.deleteCharAt(sb.length()-1);
	    return sb.toString();
    }
}
