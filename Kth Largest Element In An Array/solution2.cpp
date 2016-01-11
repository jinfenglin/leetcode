#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		int QuickSelect(vector<int> &nums,int begin,int end,int k){
			int point=partition(nums,begin,end);
			if(point==nums.size()-k){
				return nums[nums.size()-k];
			}else if(point<nums.size()-k){
				return QuickSelect(nums,point+1,end,k);
			}else
				return QuickSelect(nums,begin,point-1,k);
		
		}
		int partition(vector<int> &nums,int begin,int end){
			int pivotIndex=end;
			int writeIndex=begin;
			int scanIndex=begin;
			while(scanIndex<end){
				if(nums[scanIndex]<nums[pivotIndex]){
					swap(nums[writeIndex],nums[scanIndex]);
					writeIndex++;
				}
				scanIndex++;
			}
			swap(nums[writeIndex],nums[scanIndex]);
			return writeIndex;
		}
		int findKthLargest(vector<int>& nums, int k) {
			return QuickSelect(nums,0,nums.size()-1,k);
		}
};
int main(){
	Solution *sol=new Solution;
	vector<int> nums={1,3,6,5,4,2};
	cout<<sol->findKthLargest(nums,3)<<endl;
}
