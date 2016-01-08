#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int numSquares(int n) {
			vector<int> dp(n+1,0);
			dp[0]=0;
			for(int i=1;i<=n;i++){
				int min_val=INT_MAX;
				for(int j=1;j<=sqrt(i);j++){
					min_val=min(dp[i-j*j],min_val);
				}
				dp[i]=min_val+1;
			}
			return dp[n];
		}
};
int main(){
}
