#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
			map<long long, int> m;
			int j = 0;
			for (int i = 0; i < nums.size(); ++i) {
				if (i - j > k && m[nums[j]] == j) m.erase(nums[j++]);
				auto a = m.lower_bound(nums[i] - t);
				if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
				m[nums[i]] = i;
			}
			return false;
		}
}; 
int main(){
	Solution *sol=new Solution;
	vector<int> vec={1,3,1};
	cout<<sol->containsNearbyAlmostDuplicate(vec,2,1)<<endl;
}
