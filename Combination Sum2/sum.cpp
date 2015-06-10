#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	void combine(vector<int>& candidates,map<int,int> &counter,int target,int start,vector<vector<int> > &result, vector<int> &solution){
		if(target<=0)
			return ;
		/*for(auto x:solution)
			cout<<x<<" ";
		cout<<endl;*/
		for(int i=start;i<candidates.size();i++){
			int cur=candidates[i];
			if(counter[cur]<=0)
				continue;
			counter[cur]--;	
			solution.push_back(cur);
			if(cur==target)
				result.emplace_back(solution);
			else
				combine(candidates,counter,target-cur,i,result,solution);
			solution.pop_back();
			counter[cur]++;
		}
	}
    	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		map<int,int> mp;
		int last=-1;
		vector<int> new_candidates;
		sort(candidates.begin(),candidates.end());
		for(int x:candidates){
			if(x!=last )
			{
				new_candidates.push_back(x);
			}
			last=x;
			mp[x]++;
		}
		vector<vector<int> > res;
		vector<int> solution;
		combine(new_candidates,mp,target,0,res,solution);
		return res;
        
    	}
};

int main(){
	vector<int> init={10,1,2,7,6,1,5};
	Solution *sol=new Solution;
	auto res=sol->combinationSum2(init,8);
	for(auto x :res){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}

