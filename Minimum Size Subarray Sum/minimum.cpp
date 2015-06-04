#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int minSubArrayLen(int s, vector<int>& nums) {
			int left=0;
			int right=0;
			int sum=0;
			int res=nums.size()+1;
			while(right<nums.size()){
				while(sum<s and right<nums.size())
				{
					sum+=nums[right];
					right++;
				}
			
				while(sum>=s){
				        if(right-left<res and sum>=s)
						res=right-left;

					sum-=nums[left];
					left++;
				}
			}
			return res>nums.size()? 0:res;
		}
};
int main(){
	vector<int> init={1,2,3,4,5};
	Solution *sol=new Solution;
	cout<<sol->minSubArrayLen(11,init)<<endl;
	//cout<<sol->minSubArrayLen(7,init)<<endl;
}
