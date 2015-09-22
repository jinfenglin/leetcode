#include <iostream>
using namespace std;
class Solution {
	public:
		int rob(vector<int>& nums) {
			int len=nums.size();
			if(len==0)
				return 0;
			int dp[len+1]={0};
			dp[1]=nums[0];
			for(int i=2;i<=len;i++){
				dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
			}
			return dp[len];
		}
};
int main(){
}
