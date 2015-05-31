#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int search(vector<int>& nums, int target,int start,int end){
			cout<<start<<" "<<end<<endl;
			if(start==end)
			{
				if(target>nums[start])
					return start+1;
				else 
					return start;
			}
			int position=(start+end)/2;
			int result=0;
			if(target==nums[position])
				result=position;
			else if(target>nums[position]){
				if(position+1>end)
					result=search(nums,target,end,end);
				else
					result=search(nums,target,position+1,end);
			}
			else{
				if(start>position-1)
					result=search(nums,target,start,start);
				else
					result=search(nums,target,start,position-1);
			}
			return result;
		};
		int searchInsert(vector<int>& nums, int target) {
			if(nums.size()==0)
				return 0;
			return search(nums,target,0,nums.size()-1);

		}
};
int main(){
	vector<int> init={1,2};
	Solution *sol=new Solution;
	cout<<sol->searchInsert(init,3)<<endl;;
}
