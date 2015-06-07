#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:		
		bool canJump(vector<int>& nums) {
			int end=nums.size()-1;
			for(int i=end;i>=0;i--){
				if(i+nums[i]>=end)
					end=i;
				//cout<<"end:"<<end<<endl;
			}
			if(end==0)
				return true;
			else
				return false;
		}
};
int main(){
	vector<int> init={};
	Solution *sol=new Solution;
	cout<<sol->canJump(init)<<endl;
}
