#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int lengthOfLIS(vector<int>& nums) {
			if(nums.size()==0)
				return 0;
			vector<int> dp(nums.size(),0);
			int len=1;
			dp[0]=nums[0];
			for(int i=1;i<nums.size();i++){
				if(nums[i]<dp[0]){
					dp[0]=nums[i];
				}else if(nums[i]>dp[len-1]){
					dp[len++]=nums[i];
				}else{
					int index=biSearch(dp,nums[i],0,len-1);
					dp[index]=nums[i];
				}
			}
			return len;
		}
		int biSearch(vector<int> dp,int num,int l,int r){
			int left=l,right=r;
			while(right-left>1){
				int mid=left+(right-left)/2;
				if(num<=dp[mid]){
					right=mid;
				}else{
					left=mid;
				}
			}
			return right;
		}
};
int main(){
	Solution *sol=new Solution;
	vector<int> vec={3,5,6,2,5,4,19,5,6,7,12};
	cout<<sol->lengthOfLIS(vec)<<endl;
}
