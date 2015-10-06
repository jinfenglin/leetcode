#include <iostream>
#include <deque>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			deque<int> dq;
			vector<int> res;

			if(nums.size()==0)
				return res;
			for(int i=0;i<nums.size();i++){
				if(dq.empty())
					dq.push_back(i);
				else{
					if(dq.front()==i-k){
						dq.pop_front();
					}
					int in_queue_element=nums[i];
					while(!dq.empty() and in_queue_element>nums[dq.back()]){
						dq.pop_back();
					}
					dq.push_back(i);
				}
				if(i>=k-1)
					res.push_back(nums[dq.front()]);
			}
			return res;
		}
};
int main(){
	Solution *sol=new Solution;
	vector<int> nums={7,2,4};
	for(int i:sol-> maxSlidingWindow(nums,2))
		cout<<i<<endl;
}
