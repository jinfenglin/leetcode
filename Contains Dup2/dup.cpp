#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution{
	public:
		bool containsNearbyDuplicate(vector<int>& nums, int k){
			unordered_map<int,vector<int> > mp;
			for(int i=0;i<nums.size();i++){
				if(mp.find(nums[i])==mp.end()){
					vector<int> new_vec={i};
					mp[nums[i]]=new_vec;
				}else{
					for(int x:mp[nums[i]]){
						if(i-x<=k)
							return true;
					}
					mp[nums[i]].push_back(i);
				}
			}
			return false;
		}
};
int main(){
	vector<int> init1={1,0,1,1};
	vector<int> init2={1,2,3,4,5,6,7};
	vector<int> init3={1,1};
	vector<int> init4={};

	Solution *sol=new Solution;
	cout<<sol->containsNearbyDuplicate(init1,1)<<endl;
	cout<<sol->containsNearbyDuplicate(init2,3)<<endl;
	cout<<sol->containsNearbyDuplicate(init3,3)<<endl;
	cout<<sol->containsNearbyDuplicate(init4,3)<<endl;
}
