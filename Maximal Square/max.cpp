#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int maximalSquare(vector<vector<char>>& matrix) {
			int x_len=matrix.size();
			int y_len=x_len? matrix[0].size():0;
			int max_side=0;
			int dp[x_len][y_len];
			//for(int i=0;i<x_len;i++)
			//	for(int j=0;j<y_len;j++)
			//		dp[i][j]=0;
			for(int i=0;i<x_len;i++){
				for(int j=0;j<y_len;j++){
					if(i>0 and j>0 and matrix[i][j]=='1' and dp[i-1][j-1]!=0 and dp[i-1][j]!=0 and dp[i][j-1]!=0)
					{
						dp[i][j]=min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j])+1;
					}
					else if(matrix[i][j]=='1')
						dp[i][j]=1;
					else
						dp[i][j]=0;
					max_side=max(max_side,dp[i][j]);
				}
			}
			for(int i=0;i<x_len;i++){
				for(int j=0;j<y_len;j++)
					cout<<dp[i][j]<<" ";
				cout<<endl;
			}

			return max_side*max_side;
			
		}
};
int main(){
	Solution *sol=new Solution;
	vector<vector<char>> matrix;
	vector<char> v1={'1','1','1','1',};
	vector<char> v2={'1','1','1','1',};	
	vector<char> v3={'1','1','1','1',};
	vector<char> v4={'1','1','1','1',};
	vector<char> v5={'1','1','1','1',};
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);
	matrix.push_back(v5);
	cout<<sol->maximalSquare(matrix)<<endl;
}
