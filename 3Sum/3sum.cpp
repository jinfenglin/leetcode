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
			    if(cp_map_nums[comp]>0)
			    {
				    cp_map_nums[comp]=-1;
				    cp_map_nums[y.first]=-1;
				    map_nums[x.first]=-1;
				    vector<int> temp(3,0);
				    temp[0]=x.first;
				    temp[1]=comp;
				    temp[2]=y.first;
				    sort(temp.begin(),temp.end());
				    //if(find(result.begin(),result.end(),temp)==result.end())
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
