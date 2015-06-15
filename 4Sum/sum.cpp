#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> twoSum(vector<int>& nums, int target,int start){
		int l=start;
		int r=nums.size()-1;
		vector<vector<int>> result;
		while(l<r){
			int sum=nums[l]+nums[r];
			if(sum==target)
			{
				vector<int> solution={nums[l],nums[r]};
				result.push_back(solution);
				l++;
				r--;
				while(l<r and nums[l]==nums[l-1])
					l++;
				while(l<r and nums[r]==nums[r+1])
					r--;
			}else if(sum>target)
				r--;
			else
				l++;
		}
		return result;

	}
	vector<vector<int>> threeSum(vector<int>& nums, int target,int start,int val){
		vector<vector<int>> result;
		//sort(nums.begin(),nums.end());

		for(int i=start;i<nums.size();i++){
			if(i>start and nums[i]==nums[i-1])
				continue;
			auto tmp=twoSum(nums,target-nums[i],i+1);
			for(int j=0;j<tmp.size();j++){
				vector<int> merge={val,nums[i]};
				merge.insert(merge.end(),tmp[j].begin(),tmp[j].end());
				result.push_back(merge);
			}
		}
		return result;
	}
    	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		sort(nums.begin(),nums.end());
		for(int i=0;i<nums.size();i++){
			if(i>0 and nums[i]==nums[i-1])
				continue;
			auto tmp=threeSum(nums,target-nums[i],i+1,nums[i]);
			result.insert(result.end(),tmp.begin(),tmp.end());
		}
		return result;
    	}
};

int main(){
	vector<int> init={0,0,0,0};
	Solution *sol=new Solution;
	auto res=sol->fourSum(init,0);
	//auto res=sol->threeSum(init,0,0,0);
	for(auto x:res){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}

}
