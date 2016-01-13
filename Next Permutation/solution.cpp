#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		void nextPermutation(vector<int>& nums) {
			int last=INT_MIN;
			int partition_index=-1;
			for(int i=nums.size()-1;i>=0;i--){
				if(nums[i]<last){
					partition_index=i;
					break;
				}
				last=nums[i];
			}
			if(partition_index==-1){
				reverse(nums.begin(),nums.end());
				return ;
			}
			int change_index=-1;
			for(int i=nums.size()-1;i>=0;i--){
				if(nums[i]>nums[partition_index]){
					change_index=i;
					break;
				}
			}
			swap(nums[partition_index],nums[change_index]);
			reverse(nums.begin()+partition_index+1,nums.end());
			
		}
};

int main(){
	vector<int> nums={6,8,7,4,3,2};
	Solution *sol= new Solution;
	sol->nextPermutation(nums);
	for_each(nums.begin(),nums.end(),[](int x){ cout<<x<<" ";});
	cout<<endl;
}
