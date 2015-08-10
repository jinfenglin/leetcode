#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
	public:
		bool isMatch(string s, string p) {
			vector<vector<bool>> dp;
			//bool dp[p.size()+1][s.size()+1];
			for(int x=0;x<p.size()+1;x++)
			{
				vector<bool> tmp(s.size()+1,false);
				dp.push_back(tmp);
			}
			dp[0][0]=true;	
			for(int i=1;i<=p.size();i++){
				for(int j=0;j<=s.size();j++){
					if(j==0){
						if(p[i-1]=='*')
							dp[i][j]=dp[i-1][j];
						else
							continue;
					}else{
						if(p[i-1]=='?'){
							dp[i][j]=dp[i-1][j-1];
						}else if(p[i-1]=='*'){
							dp[i][j]=dp[i-1][j] or dp[i-1][j-1] or dp[i][j-1];
						}else{
							dp[i][j]=dp[i-1][j-1] and p[i-1]==s[j-1];
						}
					}

					/*for(int x=0;x<=p.size();x++){

						for(int y=0;y<=s.size();y++)
							cout<<dp[x][y]<<" ";
						cout<<endl;
					}
					cout<<endl;*/


				}
			}

			return dp[p.size()][s.size()];
		}
};


int main(){
	string s="aab";


	string p="c*a*b";
	Solution *sol=new Solution;
	cout<<sol->isMatch(s,p)<<endl;;

}
