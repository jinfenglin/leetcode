#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int firstMissingPositive(vector<int>& nums) {
			for(int i=0;i<nums.size();i++){
				while(nums[i]!=i+1){
					if(nums[i]<=0 or nums[i]>=nums.size() or nums[i]==nums[nums[i]-1])
						break;

					int tmp=nums[i];
					nums[i]=nums[tmp-1];
					nums[tmp-1]=tmp;
				}
			}
			int result=0;
			for(int i=0;i<nums.size();i++){
				if(nums[i]!=i+1)
					return i+1;}
			return nums.size()+1;

		}
};
int main(){
	vector<int> init={1};
	Solution *sol=new Solution;
	cout<<sol->firstMissingPositive(init)<<endl;
}

