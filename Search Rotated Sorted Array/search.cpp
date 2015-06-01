#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:

		int find_pivot(vector<int> nums){
			int start=0;
			int end=nums.size()-1;
			if(nums.size()<=2)
				if(nums[0]>nums[1])
					return 0;
				else
					return 1;

			while(start<end){
				int mid=(start+end)/2;
				
				if(start+1==end)
					if(nums[start]>nums[end])
						return start;
					else
						return end;

				if(nums[start]>nums[mid]){
					end=mid;
				}else if(nums[start]<nums[mid]){
					start=mid;
				}
				
			}
			//return start;
		}
		int binary_search(vector<int> &nums,int target,int start,int end){
			cout<<start<<" "<<end<<endl;
			if(start>end)
				return -1;			
			int mid=(start+end)/2;
			if(target>nums[mid])
				start=mid+1;
			else if(target<nums[mid])
				end=mid-1;
			else
				return mid;
			return binary_search(nums,target,start,end);

		}
		int search(vector<int>& nums, int target) {
			if(nums.size()==0)
				return -1;
			int pivot=find_pivot(nums);
			cout<<pivot<<endl;
			int result=-1;
			if(target>nums[0])
				result=binary_search(nums,target,0,pivot);
			else if(target<nums[0])
				result=binary_search(nums,target,pivot+1,nums.size()-1);
			else
				return 0;
			return result;
		}
};
int main(){
	Solution *sol=new Solution;
	//vector<int> init={3,5,1};
	vector<int> init={1,1,3};
	//cout<<sol->find_pivot(init)<<endl;
	cout<<sol->search(init,3)<<endl;
}
