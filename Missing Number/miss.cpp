#include <iostream>
using namespace std;
class Solution {
	public:
		int missingNumber(vector<int>& nums) {
			int n=nums.size()+1;
			int sum=(n-1)*n/2;
			for(int i:nums)
				sum-=i;
			return sum;
		}
};
int main(){
}
