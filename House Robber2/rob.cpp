#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int rob(vector<int>& nums) {
			if(nums.size()==0)
				return 0;
			vector<int> dp(nums.size(),0);
			dp[0]=nums[0];
			int max_val=0;
			if(nums.size()==1)
				return dp[0];


			dp[0]=0;
			dp[1]=nums[1];
			for(int i=2;i<nums.size();i++){
				dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
			}
			max_val=max(max_val,dp[nums.size()-1]);	

			dp[1]=nums[0];
			dp[0]=nums[0];
			for(int i=2;i<nums.size()-1;i++){
				dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
			}
			dp[nums.size()-1]=dp[nums.size()-2];
			max_val=max(max_val,dp[nums.size()-1]);
			return max_val;
		}
};
int main(){
	Solution *sol=new Solution;
	vector<int> house={1,2,3,1};
	cout<<sol->rob(house)<<endl;
}
