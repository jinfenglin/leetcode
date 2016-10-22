public class Solution {
    public int longestSubstring(String s, int k) {
        int[] charCount = new int[26];
        int res=0;
        for(int i=0;i<s.length();i++){
            charCount[s.charAt(i)-'a']+=1;
        }
        StringBuilder sb = new StringBuilder();
        int validChar=0, totalChar=0;
        for(int i=0;i<26;i++){
            if(charCount[i]>=k){
                validChar++;
            }
            if(charCount[i]>0){
                totalChar++;
                if(charCount[i]<k)
                    sb.append((char)('a'+i));
            }
            
        }
        if(totalChar==validChar)
            return s.length();
        String[] subString = s.split("["+sb.toString()+"]");
        for(int j=0;j<subString.length;j++){
            res = Math.max(res, longestSubstring(subString[j],k));
        }
        return res;
    }
}
