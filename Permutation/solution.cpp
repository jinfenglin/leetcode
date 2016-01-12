#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
	public: void DFS(vector<int> &tmp,vector<vector<int>> &res,unordered_set<int> &input){
			if(input.size()==0){
				res.push_back(tmp);
				return ;
			}
			for(int num:input){
				unordered_set<int> t_set=input;
				t_set.erase(num);
				tmp.push_back(num);
				DFS(tmp,res,t_set);
				tmp.pop_back();
			}
			
		}
		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> res;
			vector<int> tmp;
			unordered_set<int> in(nums.begin(),nums.end());
			DFS(tmp,res,in);
			return res;
		}
};
int main(){
	Solution *sol=new Solution;
	vector<int> num={1,2,3};
	auto res=sol->permute(num);
	for_each(res.begin(),res.end(),[](vector<int> tmp){
				for_each(tmp.begin(),tmp.end(),[](int x){cout<<x<<" ";});
				cout<<endl;
			});
}
