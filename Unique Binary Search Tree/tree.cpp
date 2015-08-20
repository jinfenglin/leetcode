#include <iostream>

using namespace std;
class Solution {
	public:
		int numTrees(int n) {
			if(n==0)
				return 0;
			int dp[n+1];
			dp[0]=1;
			dp[1]=1;
			for(int i=2;i<=n;i++){
				dp[i]=0;
				for(int j=1;j<=i;j++){
					dp[i]+=dp[j-1]*dp[i-j];
				}
			}
			return dp[n];
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->numTrees(3)<<endl;
}
