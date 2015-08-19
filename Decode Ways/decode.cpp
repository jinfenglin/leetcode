#include <iostream>
using namespace std;
class Solution {
	public:

		int numDecodings(string s) {
			if(s.size()==0)
				return 0;
			int dp[s.size()+1];
			dp[0]=1;
			for(int i=1;i<=s.size();i++){
				dp[i]=0;
				if(s[i-1]>='1' and s[i-1]<='9')
					dp[i]=dp[i-1];
				if(i>=2){
					if(s[i-2]=='1' and s[i-1]<='9' and s[i-1]>='0'){
						dp[i]+=dp[i-2];
					}else if(s[i-2]=='2' and s[i-1]>='0' and s[i-1]<='6'){
						dp[i]+=dp[i-2];
					}
				}
				cout<<"i:"<<i<<" dp[i]"<<dp[i]<<endl;
			}
			return dp[s.size()];
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->numDecodings("12")<<endl;
}
