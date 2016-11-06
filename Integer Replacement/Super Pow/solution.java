public class Solution {
    public int superPow(int a, int[] b) {
        int ans = 1;
        for(int i=0;i<b.length;i++){
            ans = (pow(ans,10)%1337*pow(a,b[i])%1337)%1337;
        }
        return ans;
    }
    
    public int pow(int x, int y){
        int res =1;
        if(y==0)
            return res;
        for(int i=0;i<y;i++)
            res=(res*(x%1337))%1337;
        return res;
    }
}
