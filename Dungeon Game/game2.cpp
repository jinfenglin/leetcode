#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int calculateMinimumHP(vector<vector<int>>& dungeon) {
			int N,M;
			N=dungeon.size();
			vector<vector<int>> dp;
			for(int i=0;i<dungeon.size();i++)
				dp.push_back(vector<int>(dungeon[i]));
			for(int i=N-1;i>=0;i--){
				M=dungeon[i].size();
				for(int j=M-1;j>=0;j--){
					if(i==N-1 and j!=M-1){
						dp[i][j]=min(dp[i][j+1]+dp[i][j],0);
					}else if(i!=N-1 and j==M-1){
						dp[i][j]=min(dp[i+1][j]+dp[i][j],0);
					}else if(i!=N-1 and j!=M-1){
						dp[i][j]=min(max(dp[i+1][j],dp[i][j+1])+dp[i][j],0);
					}else{
						dp[i][j]=min(dp[i][j],0);
					}
				}
			}
			return abs(dp[0][0])+1;
		}
};
int main(){
	Solution *sol=new Solution();
	vector<vector<int>> in;
	vector<int> l1={3,49,38,30,-93,-99,13,10,6,-77};
	in.push_back(l1);
	cout<<sol->calculateMinimumHP(in)<<endl;
}
