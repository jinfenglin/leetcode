public class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int res = 0 ;
        for(int i=1;i<A.length;){
            int diff = A[i] - A[i-1];
            i++;
            int len=2;
            while(i<A.length && A[i]-A[i-1]==diff){
                i++;
                len++;
            }
            res += (1+len-2)*(len-2)/2;
        }
        return res;
    }
}
