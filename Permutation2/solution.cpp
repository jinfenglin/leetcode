#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		void DFS(vector<vector<int>> &res, vector<int> &tmp,vector<int> nums,vector<bool> visited,int n){
			if(n==nums.size()){
				res.push_back(tmp);
			}
			for(int i=0;i<nums.size();i++){
				if((i>0 and nums[i]==nums[i-1] and !visited[i-1]) or visited[i])
					continue;
				visited[i]=true;
				tmp.push_back(nums[i]);
				DFS(res,tmp,nums,visited,n+1);
				tmp.pop_back();
				visited[i]=false;
			}

		}
		vector<vector<int>> permuteUnique(vector<int>& nums) {
			vector<vector<int>> res;
			vector<bool> visited(nums.size(),false);
			vector<int> tmp;
			sort(nums.begin(),nums.end());
			DFS(res,tmp,nums,visited,0);
			return res;
		}
};
int main(){
	vector<int> nums={1,1,2};
	Solution *sol=new Solution;
	auto res=sol->permuteUnique(nums);
	for_each(res.begin(),res.end(),[](vector<int> tmp){
			for_each(tmp.begin(),tmp.end(),[](int x){cout<<x<<" ";});
			cout<<endl;
			});
}
