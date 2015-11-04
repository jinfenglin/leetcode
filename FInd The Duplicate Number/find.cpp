#include <iostream>
using namespace std;
class Solution {
	public:
		int findDuplicate(vector<int>& nums) {
			int low=0,high=nums.size()-1;
			while(low<=high){
				int mid=(low+high)/2;
				int cnt=0;
				for(int i=0;i<nums.size();i++)
					cnt+= nums[i]<=mid;
				if(cnt>mid)
					high=mid-1;
				else
					low=mid+1;
			}
			return low;
		}
};
int main(){

}
