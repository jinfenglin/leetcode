#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
	void select(int k,int n,vector<int> nums,vector<int> &solution,vector<vector<int> > &result,int start){
		if(k==0 and n==0)
			result.push_back(solution);
		else if(k<0)
			return;
		for(int i=start;i<nums.size();i++){
			if(i==start or nums[i]!=nums[i-1]){
				solution.push_back(nums[i]);
				select(k-1,n+nums[i],nums,solution,result,i+1);
				solution.pop_back();
			}
		}
	}
    	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<int> solution;
		vector<vector<int> >result;
		select(3,0,nums,solution,result,0);
		return result;
		

	}
};
int main(){
	Solution *sol=new Solution;
	//vector<int> init={7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	//vector<int> init={1,0,-1,0};
	vector<int> init={2,2,-1,-3,3,1,-2,1,-2,3,0,-5,0,4,-3,3};
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
