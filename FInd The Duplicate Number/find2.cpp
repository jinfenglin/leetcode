#include <iostream>
using namespace std;
class Solution {
	public:
		int findDuplicate(vector<int>& nums) {
			int fast=0,slow=0;
			slow=nums[slow];
			fast=nums[nums[fast]];
			while(fast!=slow){
				slow=nums[slow];
				fast=nums[nums[fast]];
			}
			slow=0;
			while(fast!=slow){
				slow=nums[slow];
				fast=nums[fast];
			}
			return slow;
		}
};
int main(){
}
