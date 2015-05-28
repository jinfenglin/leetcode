#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void quick_sort(vector<int> &nums,int begin,int end){
		int left=begin;
		int right=end;
		int pivot=nums[(begin+end)/2];
		while(left<right){
			while(nums[left]<pivot)
				left++;
			while(nums[right]>pivot)
				right--;
			if(left<=right){
				int tmp=nums[left];
				nums[left]=nums[right];
				nums[right]=tmp;
				left++;
				right--;
			}
		}
		if(left<end)
			quick_sort(nums,left,end);
		if(right>begin)
			quick_sort(nums,begin,right);
	}
    	void sortColors(vector<int>& nums) {
		int i=0;
		int j=nums.size()-1;
		quick_sort(nums,i,j);
    	}
};
int main(){
	Solution *sol=new Solution;
	vector<int > init={0,0,1,2,1,0};
	sol->sortColors(init);
	for(int x: init)
		cout<<x<<" ";
	cout<<endl;
}
