#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
	unordered_set<int> set(nums.begin(),nums.end());
	int max_value=0;
	while(!set.empty()){
		int left=0,right=0;
		int seed=*set.begin();
		set.erase(set.begin());
		//cout<<"seed "<<seed<<endl;
		int r=seed+1;
		while(set.find(r)!=set.end()){
			right++;
			set.erase(set.find(r));

			r++;
		}
		int l=seed-1;
		while(set.find(l)!=set.end()){
			left++;
			set.erase(set.find(l));
			
			l--;
		}
		//cout<<left<<" "<<right<<endl;
		max_value=max(max_value,right+left+1);
	}
	return max_value;
    }
};
int main(){
	vector<int> init={-1,1,0};
	Solution *sol=new Solution;
	cout<<sol->longestConsecutive(init)<<endl;
}
