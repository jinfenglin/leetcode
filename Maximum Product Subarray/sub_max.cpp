#include <iostream>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
	    if(nums.size()==0)
		    return 0;
	    int res=nums[0];
	    int cur_max=nums[0];
	    int cur_min=nums[0];

	    for(int i=1;i<nums.size();i++){
		    int temp=cur_max;
		    cur_max=max(max(cur_max*nums[i],cur_min*nums[i]),nums[i]);
		    cur_min=min(min(temp*nums[i],cur_min*nums[i]),nums[i]);
		    if(cur_max>res)
			    res=cur_max;
	    }
        return res;
    }
};

int main(){
	Solution *sol=new Solution;
	vector<int> init={-4,-3,-2};
	cout<<sol->maxProduct(init)<<endl;
}
