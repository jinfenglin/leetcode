#include <iostream>
using namespace std;
class Solution {
	public:
		void moveZeroes(vector<int>& nums) {
			int p1=0,p2=0;
			while(p2<nums.size()){
				while(nums[p1]!=0 and p1<nums.size())
					p1++;
				p2=p1+1;
				while(nums[p2]==0 and p2<nums.size())
					p2++;
				if(p1<nums.size() and p2<nums.size())
					swap(nums[p1],nums[p2]);
			}
		}
};
int main(){
}
