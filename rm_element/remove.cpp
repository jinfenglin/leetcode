#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
	    int start=0;
	    for(int i=0;i<nums.size();i++){
	    	if(nums[i]!=val)
		{
			nums[start]=nums[i];
			start++;
		}
	    }
	    return start;
    }
};
int main(){
	Solution *sol=new Solution;
	vector<int> init={0,1,2,1,1,3,4,5,6};
	cout<<sol->removeElement(init,1)<<endl;
}
