#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int minDistance(string word1, string word2) {
			int row_num=word1.size();
			int list_num=word2.size();
			vector<vector<int>> dp;
			for(int i=0;i<=row_num;i++){
				dp.push_back(vector<int>(list_num+1,0));
			}
			for(int i=1;i<=list_num;i++)
				dp[0][i]=i;
			for(int i=1;i<=row_num;i++)
				dp[i][0]=i;
			for(int i=1;i<=row_num;i++){
				for(int j=1;j<=list_num;j++){
					/*for( int n=0;n<=row_num;n++)
					{
						for(int m=0;m<=list_num;m++){
							cout<<dp[n][m]<<" ";
						}
						cout<<endl;
					}
					cout<<endl;*/
					int del=dp[i][j-1]+1;
					int insert=dp[i-1][j]+1;
					int rep;
					if(word1[i-1]==word2[j-1])
						rep=dp[i-1][j-1];
					else
						rep=dp[i-1][j-1]+1;
					dp[i][j]=min(min(del,insert),rep);	
				}
			}
			return dp[row_num][list_num];
			
		}
};
int main(){
	Solution *sol=new Solution;
	string word1="c";
	string word2="abc";
	cout<<sol->minDistance(word1,word2)<<endl;
}
