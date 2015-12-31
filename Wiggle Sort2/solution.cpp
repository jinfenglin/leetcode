#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		void wiggleSort(vector<int>& nums) {
			if(nums.size()==0)
				return;
			sort(nums.begin(),nums.end());
			int point;
			if(nums.size()%2)
				point=nums.size()/2;
			else
				point=nums.size()/2-1;
			vector<int> small(nums.begin(),nums.begin()+point+1);
			vector<int> large(nums.begin()+point+1,nums.end());
			for(int i=0;i<nums.size();i++){
				if(i%2==0){
					nums[i]=small[small.size()-i/2-1];
				}else{
					nums[i]=large[large.size()-i/2-1];
				}
			}
		}
};
int main(){
	vector<int> nums={4,5,5,6};
	Solution *sol=new Solution;
	sol->wiggleSort(nums);
	for(int num:nums)
		cout<<num<<endl;
}
