=#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int allSell(vector<int> &prices) {
			int ret = 0;
			for(int i=1; i < prices.size(); ++i)
				if(prices[i]-prices[i-1]>0) ret += (prices[i]-prices[i-1]);
			return ret;
		}
		int maxProfit(int k, vector<int>& prices) {
			int n = prices.size();
			if(k>=n/2){
				return allSell(prices);
			}
			int len=prices.size();
			int dp[len+1][k+1];
			for(int i=0;i<=len;i++)
				for(int j=0;j<=k;j++)
					dp[i][j]=0;
			for(int j=1;j<=k;j++){
				int cur=INT_MIN;
				for(int i=1;i<=len;i++){
					dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],cur+prices[i-1]));
					cur=max(cur,dp[i-1][j-1]-prices[i-1]);
				}
			}	
			return dp[len][k];		
		}
};
int main(){
	Solution *sol=new Solution();
	vector<int> prices={1,2,3};
	cout<<sol->maxProfit(1,prices)<<endl;
}
