#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution{
	public:
		int majorityElement1(vector<int>& nums) {
			for(auto it=nums.begin();it!=nums.end();it++){
				int times=count(nums.begin(),nums.end(),*it);
				if (times > nums.size()/2)
					return *it;

			}

		}

		int majorityElement2(vector<int>& nums) {
			map<int,int> mp;
			for(auto it=nums.begin();it!=nums.end();it++){
				mp[*it]+=1;
				if(mp[*it]>nums.size()/2)
					return *it;
			}
			
		}

};
int main()
{
	int array[]={1,1,1,1,1,2,3};
	vector<int> init(array,array+sizeof(array)/sizeof(int));
	Solution *sol= new Solution();
	cout << sol->majorityElement2(init)<<endl;
	return 0;
}
