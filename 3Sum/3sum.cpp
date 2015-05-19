#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	    vector<vector<int> > result;
	    unordered_map<int,int> map_nums;
	    for(int x:nums)
		    map_nums[x]++;
	    for(pair<int,int> x:map_nums){
		    int rest=-x.first;
		    //x.second--;
		    map_nums[x.first]--;
		    
		    unordered_map<int,int> cp_map_nums=map_nums;
		    for(auto y:cp_map_nums)
		    {
			    if(y.second<=0)
				    continue;
			    int comp=rest-y.first;
			    cp_map_nums[y.first]--;
			    if(cp_map_nums.find(comp)!=cp_map_nums.end() and cp_map_nums[comp]>0)
			    {
				    cp_map_nums[comp]--;
				    cp_map_nums[y.first]--;
				    vector<int> temp;
				    temp.push_back(x.first);
				    temp.push_back(comp);
				    temp.push_back(y.first);
				    sort(temp.begin(),temp.end());
				    if(find(result.begin(),result.end(),temp)==result.end())
				    	result.push_back(temp);
			    }
			    //y.second++;
			    cp_map_nums[y.first]++;
		    }
		    //x.second++;
		    map_nums[x.first]++;
	    }
	    return result;
    }
};
int main(){
	Solution *sol=new Solution;
	vector<int> init={3,0,-2,-1,1,2};
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
