#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
	    int counter=0;
	    vector<vector<int> > result;
	    for(int x:nums){	    	
    		    vector<vector<int> > sub_result=TwoSum(nums,-x,counter);
		    for(auto each:sub_result){
		    	if(!count(result.begin(),result.end(),each))
				result.push_back(each);
		    }		    
		    counter+=1;		    
	    }
	    return result;
    }
    vector< vector<int>>TwoSum(vector<int> nums,int target,int forbid){
	    unordered_map<int,int> map;
	    vector<vector<int> > result; 
	    for(int i=0;i<nums.size();i++){
		    if(i==forbid)
			    continue;
		    vector<int> temp_result;
		    int complement=target-nums[i];
		    if(map[complement]){
			    map[complement]--;
			    temp_result.push_back(nums[i]);
			    temp_result.push_back(complement);
			    temp_result.push_back(-target);
			    sort(temp_result.begin(),temp_result.end());
			    result.push_back(temp_result);
		    }
		    else{
			    map[nums[i]]++;
		    }
	    }
	    return result;


    }
};
int main(){
	Solution *sol=new Solution;
	vector<int> init={-1,0,1,2,-1,-4};
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
