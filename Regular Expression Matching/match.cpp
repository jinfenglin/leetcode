#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
		bool isMatch(string s, string p) {
			int s_len=s.size();
			int p_len=p.size();
			bool dp[p_len+1][s_len+1];
			dp[0][0]=true;
			for(int j=1;j<s_len+1;j++)
				dp[0][j]=false;
			for(int i=1;i<p_len+1;i++){
				cout<<"i:"<<i<<" ";
				for(int j=0;j<s_len+1;j++){
					if(p[i-1]=='*'){
						if(i>1)
							if(j==0)
								dp[i][j]=dp[i-2][j]; //s is empty only when this * match nothing then it is possible
							else 
								dp[i][j]=((s[j-1]==p[i-2] or p[i-2]=='.') and dp[i][j-1]) /*or (dp[i-1][j-1])*/ or (dp[i-2][j]);
						else // * could not be the first symbol
							return 0;						
					}else{
						if(j==0)
							dp[i][j]=false;
						else
							dp[i][j]=dp[i-1][j-1] and( p[i-1]=='.' or p[i-1]==s[j-1]);
					
					}
					cout<<dp[i][j]<<" "; 
					
				}
				cout<<endl;
			}

			return dp[p_len][s_len];			
		}
};
int main(){
	string s="aab";
	string p="c*a*c";
	Solution *sol=new Solution;
	cout<<sol->isMatch(s,p)<<endl;

}
