#include <iostream>
using namespace std;
class Solution {
	public:
		int numDistinct(string s, string t) {
			int dp[s.size()+1][t.size()+1];
			for(int i=0;i<s.size()+1;i++){
				memset(dp[i],0,(t.size()+1)*sizeof(int));
				dp[i][0]=1;
			}

			for(int i=1;i<t.size()+1;i++)
				for(int j=i;j<s.size()+1;j++){
					if(s[j-1]==t[i-1])
						dp[j][i]=dp[j-1][i-1]+dp[j-1][i];
					else
						dp[j][i]=dp[j-1][i];

				}

			return dp[s.size()][t.size()];
		}
};

int main(){
	string s="rabbbit";
	string t="rabbit";
	Solution *sol=new Solution;
	cout<<sol->numDistinct(s,t)<<endl;
}
