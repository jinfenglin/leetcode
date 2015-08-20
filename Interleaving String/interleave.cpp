#include <iostream>
using namespace std;
class Solution {
	public:
		bool isInterleave(string s1, string s2, string s3) {
			int x=s1.size();
			int y=s2.size();
			if(s3.size()!=x+y)
				return false;
			bool dp[x+1][y+1];
			dp[0][0]=true;
			for(int i=1;i<=x;i++)
				dp[i][0]= dp[i-1][0] and s1[i-1]== s3[i-1];
			for(int i=1;i<=y;i++)
				dp[0][i]=dp[0][i-1] and s2[i-1]== s3[i-1];
			for(int i=1;i<=x;i++)
				for(int j=1;j<=y;j++)
					dp[i][j]=(dp[i-1][j] and s1[i-1]==s3[i+j-1]) or (dp[i][j-1] and s2[j-1]==s3[i+j-1]);
			return dp[x][y];
		}
};
int main(){
	Solution *sol=new Solution;
	string s1="";
	string s2="";
	string s3="aadbbbaccc";
	cout<<sol->isInterleave(s1,s2,s3)<<endl;
}
