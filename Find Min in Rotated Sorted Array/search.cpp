#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int search(vector<int> &nums,int start,int end,int min_res){
		if(start>end)
			return min_res;
		int mid=(start+end)/2;
		int res=min(min_res,nums[mid]);
		if(nums[mid]>=nums[start]){
			res=min(min_res,nums[start]);
			return search(nums,mid+1,end,res);
		}else{
			res=min(min_res,nums[mid]);
			return search(nums,start,mid-1,res);
		}
	}
    	int findMin(vector<int>& nums) {
		int start=0,end=nums.size()-1;
		int min_val=nums[(start+end)/2];
		return search(nums,start,end,min_val);
    	}
};
int main(){
	vector<int> init1={0,1,2,3,4,5,6};
	vector<int> init2={2,3,1};
	vector<int> init3={4,5,6,7,9,1,2};
	Solution *sol=new Solution;
	cout<<sol->findMin(init1)<<endl;
	cout<<sol->findMin(init2)<<endl;
	cout<<sol->findMin(init3)<<endl;
}
