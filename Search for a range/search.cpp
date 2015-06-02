#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int search_left(vector<int> nums,int point){
			int start=0;
			int end=point;
			while(start<=end){
				if(end-start<=1)
					if(nums[start]==nums[point])
						return start;
					else
						return end;
				int mid=(start+end)/2;
				if(nums[mid]==nums[point])
					end=mid;
				else
					start=mid;
			}

		}
		int search_right(vector<int> nums,int point){
			int start=point;
			int end=nums.size()-1;
			while(start<=end){
				if(end-start<=1)
					if(nums[end]==nums[point])
						return end;
					else
						return start;
				int mid=(start+end)/2;
				if(nums[mid]==nums[point])
					start=mid;
				else
					end=mid;
			}

		}

		vector<int> searchRange(vector<int>& nums, int target) {
			int start=0;
			int end=nums.size()-1;
			int res_start,res_end;
			while(start<=end){
				int mid=(start+end)/2;
				if(nums[mid]==target){
					res_start=mid;
					res_end=mid;
					break;
				}
				if(target>nums[mid])
					start=mid+1;
				else
					end=mid-1;
			}
			if(start>end)
			{
				vector<int> res={-1,-1};
				return res;
			}	
			cout<<res_start<<endl;
			vector<int> res;
			res.push_back(search_left(nums,res_start));
			res.push_back(search_right(nums,res_end));
			return res;
		}
};

int main(){
	Solution *sol=new Solution;
	vector<int> init={5,7,7,8,8,10};
	//vector<int> init={8};
	auto res=sol->searchRange(init,8);
	for(auto x:res)
		cout<<x;
	cout<<endl;

}
