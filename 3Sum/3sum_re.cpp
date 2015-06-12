#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
	public:
		vector<vector<int> > twoSum(vector<int> &nums,int target,int start){
			int l=start;
			int r=nums.size()-1;
			//cout<<l<<" "<<r<<endl;
			vector<vector<int> > result;
			//cout<<"target:"<<target<<endl;
			while(l<r){
				int sum=nums[l]+nums[r];
				if(sum==target )
				{
					vector<int> vec={-target,nums[l],nums[r]};
					result.push_back(vec);
					l++;
					r--;
					while(l<r and nums[l]==nums[l-1])
						l++;
					while(l<r and nums[r]==nums[r+1])
						r--;

				}
				else if(sum>target)
					r--;
				else
					l++;
			}
			return result;
		
		}
		vector<vector<int>> threeSum(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			vector<vector<int> > result;
			for(int i=0;i<nums.size();i++){
				if(i==0 or nums[i]!=nums[i-1])				
				{
					auto res=twoSum(nums,-nums[i],i+1);
					result.insert(result.end(),res.begin(),res.end());
					
				}
			}
			return result;
		}
};
int main(){
	Solution *sol=new Solution;
	//vector<int> init={7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};

	vector<int> init={0,0,0};
	auto result=sol->threeSum(init);
	for(auto x:result){
		{
			for(auto y:x)
				cout<<y<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

}

