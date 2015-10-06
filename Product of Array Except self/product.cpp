#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<int> productExceptSelf(vector<int>& nums) {
			int p=nums[0];
			vector<int> res;
			res.push_back(1);
			for(int i=1;i<nums.size();i++){
				res.push_back(p);
				p*=nums[i];
			}
			p=nums[nums.size()-1];
			for(int i=nums.size()-2;i>=0;i--){
				res[i]*=p;
				p=p*nums[i];
			}
			return res;

		}
};
int main(){
}
