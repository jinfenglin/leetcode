#include <isotream>
using namespace std;

class Solution {
	public:
		vector<string> summaryRanges(vector<int>& nums) {
			vector<string> res;
			if(nums.size()==0)
				return res;
			int left=nums[0],right=nums[0];
			for(int num:nums){
				if(num==right+1){
					right=num;
				}
				else if(num==right){
					continue;
				}else{
					if(left==right){
						res.push_back(to_string(left));
						left=num;
						right=num;
					}
					else{
						res.push_back(to_string(left)+"->"+to_string(right));
						left=num;
						right=num;
					}
				}
			}
			if(left==right)
				res.push_back(to_string(left));
			else{
				res.push_back(to_string(left)+"->"+to_string(right));
			}

			return res;
		}
};
int main(){
}
