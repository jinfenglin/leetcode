public class Solution {
    public int characterReplacement(String s, int k) {
        int high=0,low=0;
        int[] charTable = new int[26];
        for(;high<s.length();){
             charTable[s.charAt(high)-'A']++;
             high++;
             if(countDiff(charTable)>k){
                 charTable[s.charAt(low)-'A']--;
                 low++;
             }
         }
         return high-low;
    }
    private int countDiff(int[] charTable){
        int max=0,sum=0;
        for(int i=0;i<charTable.length;i++){
            if(charTable[i]>max)
                max = charTable[i];
            sum+=charTable[i];
        }
        return sum - max;
    }
}
