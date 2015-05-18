#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums,int target) {
	    vector<int> result;
	    for(int i=0;i<nums.size();i++)
		    for(int j=i+1;i<nums.size();j++){
			    if (nums[i]>=target or nums[j]>=target)
				    break;
			    if(nums[i]+nums[j]==target)
			    {
				    result.push_back(i+1);
				    result.push_back(j+1);
			       	
			    }
		    }
	    return result;
    }
};

int main(){
	Solution *sol= new Solution;
	vector<int> init={2,7,11,15};
	auto result=sol->twoSum(init,9);
	for(int x:result)
		cout<<x<<" ";
	cout<<endl;
}
