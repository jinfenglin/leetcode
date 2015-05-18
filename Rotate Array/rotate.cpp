#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while(k){
		k--;
		int back=nums.back();
		nums.pop_back();
		nums.insert(nums.begin(),back);
	}
    }
};
int main()
{
	Solution *sol=new Solution;
	vector<int> init={1,2,3,4,5,6,7};
	sol->rotate(init,3);
	for(auto x:init)
	{
		cout<<x<<" ";
	}	
	cout<<endl;
}
