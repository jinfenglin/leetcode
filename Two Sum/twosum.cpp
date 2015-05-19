#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums,int target) {
	    vector<int> result;
	    unordered_map<int,int> mymap;
	    for(int i=0;i<nums.size();i++){
	    	int complement=target-nums[i];
		if(mymap.count(complement)){
			int another_pos=mymap[complement];
			if(another_pos>i)
			{
				
				result.push_back(i+1);
				result.push_back(another_pos+1);
			}
			else{
				result.push_back(another_pos+1);
				result.push_back(i+1);
			}
		}
		else
		{
			mymap[nums[i]]=i;
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
