#include <iostream>
#include <queue>
using namespace std;
class Solution {
	public:
		int findKthLargest(vector<int>& nums, int k) {
			priority_queue<int,vector<int>> pq(nums.begin(),nums.end());
			while(k>1){
				pq.pop();
				k--;
			}
			return pq.top();
		}
};
int main(){
	Solution *sol=new Solution;
	vector<int> num={1,2,3,4,5,6};
	cout<<sol->findKthLargest(num,1)<<endl;
}
