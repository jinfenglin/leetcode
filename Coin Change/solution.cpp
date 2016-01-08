#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int coinChange(vector<int>& coins, int amount) {
			int dp[amount+1];
			fill_n(dp,amount+1,-1);
			dp[0]=0;
			for(int i=0;i<=amount;i++){
				for(int j=0;j<coins.size();j++){
					int val=coins[j];
					if(val<=i and dp[i-val]!=-1){
						if(dp[i]==-1)
							dp[i]=dp[i-val]+1;
						else
							dp[i]=min(dp[i-val]+1,dp[i]);
					}
				}
			}
			return dp[amount];
		}
};

int main(){
	Solution *sol=new Solution;
	vector<int> coins={186,419,83,408};
	//vector<int> coins={1,2,5};
	cout<<sol->coinChange(coins,6249)<<endl;
}
