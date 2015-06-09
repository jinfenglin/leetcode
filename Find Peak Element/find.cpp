#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int findPeakElement(vector<int>& nums) {
			if(nums.size()<=1)
				return 0;
			for(int i=0;i<nums.size();i++){
				if(i==0 and nums[i+1]<nums[i])
					return 0;
				else if(i==nums.size()-1 and nums[i-1]<nums[i])
					return nums.size()-1;
				else if(nums[i]>nums[i-1] and nums[i]>nums[i+1])
					return i;
			}
		}
};

int main(){
	vector<int> init={1,6,3,1,1};
	Solution *sol=new Solution;
	cout<<sol->findPeakElement(init)<<endl;
}
