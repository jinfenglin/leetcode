#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		bool search(vector<int>& nums, int target) {
			int start=0;
			int end=nums.size()-1;
			while(start<=end){
				int mid=(start+end)/2;
				//cout<<start<<end<<endl;
				if(nums[mid]==target)
					return true;
				if(nums[mid]>nums[start]){
					if(nums[start]<=target and target<=nums[mid])
						end=mid-1;
					else
						start=mid+1;
				}
				else if(nums[mid]<nums[start]){
					if(nums[mid]<=target and target<=nums[end])
						start=mid+1;
					else
						end=mid-1;
				}
				else{
					start++;
				}
			}
			return false;

		}
};
int main(){
	Solution *sol=new Solution;
	vector<int> init={1,3,5};
	cout<<sol->search(init,1)<<endl;
}
