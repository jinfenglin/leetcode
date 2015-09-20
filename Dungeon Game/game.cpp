#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int calculateMinimumHP(vector<vector<int>>& dungeon) {
			vector<vector<pair<int,int>>> dp;
			int N=dungeon.size();
			int M=dungeon[N-1].size();
			//cout<<N<<" "<<M<<endl;
			for(int i=0;i<N;i++){
				dp.push_back(vector<pair<int,int>>(dungeon[i].size(),pair<int,int>(0,0)));
			}
			dp[0][0].first=1;
			dp[0][0].second=0;
			cout<<dp[0][0].first<<" "<<dp[0][0].second<<endl;
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++){
					select(dp,i,j);				
					int damage=min(dp[i][j].second+dungeon[i][j],0);
					dp[i][j].second=max(dp[i][j].second+dungeon[i][j],0);
					dp[i][j].first-=damage;
				}
			}
			//cout<<dp[N-1][M-1].first<<endl;
			return dp[N-1][M-1].first;
		}
		void select(vector<vector<pair<int,int>>> &dp,int i,int j){
			
			if(i!=0 and j!=0){
				pair<int,int> left=dp[i][j-1];
				pair<int,int> up=dp[i-1][j];
				if(left.first<up.first){
					dp[i][j]=left;
				}else if(left.first>up.first){
					dp[i][j]=up;
				}else{
					if(left.second>up.second)
						dp[i][j]=left;
					else
						dp[i][j]=up;
				}
			}else if(i==0 and j!=0){
				dp[i][j]=dp[i][j-1];
			}else if(i!=0 and j==0){
				dp[i][j]=dp[i-1][j];
			}	
		}
};
int main(){
	Solution *sol=new Solution;
	vector<vector<int>> in;
	in.push_back(vector<int>(1,0));
	cout<<sol->calculateMinimumHP(in)<<endl;

}
