#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		int start=0,end=nums.size()-1;
		int res=nums[(start+end)/2];
		while(start<=end){
			int mid=(start+end)/2;
			res=min(res,nums[mid]);
			if(nums[start]<nums[mid]){
					res=min(res,nums[start]);
					start=mid+1;
					
			}else if(nums[start]>nums[mid]){
					res=min(nums[mid],res);
					end=mid-1;
			}
			else{
				start++;
			}
		}
		return res;
	}
};

int main(){
	Solution *sol=new Solution;
	vector<int> init1={1,2,3,4,5};
	vector<int> init2={4,5,6,0,1,2};
	vector<int> init3={1,3};
	vector<int> init4={3,1};
	vector<int> init5={2,3,1};

	cout<<sol->findMin(init1)<<endl;
	cout<<sol->findMin(init2)<<endl;
	cout<<sol->findMin(init3)<<endl;
	cout<<sol->findMin(init4)<<endl;
	cout<<sol->findMin(init5)<<endl;



}
