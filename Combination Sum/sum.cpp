#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	 vector<vector<int> > recu(vector<int> candidates,int target,unordered_set<int> blacklist){
			vector<vector<int> > res;
			if(target<0)
				return res;
			for(int i=0;i<candidates.size();i++){
				if(blacklist.find(i)!=blacklist.end())
					continue;
				int cur=candidates[i];
				if(target-cur==0){
					vector<int> tmp;
					tmp.push_back(cur);
					res.push_back(tmp);
					return res;
				}
				vector<vector<int> > part=recu(candidates,target-cur,blacklist);
				for(int j=0;j<part.size();j++)
					part[j].insert(part[j].begin(),cur);
				res.insert(res.begin(),part.begin(),part.end());
				blacklist.insert(i);
			}
			return res;

				 
	 }
   	 vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		 unordered_set<int> blacklist;
		 return recu(candidates,target,blacklist);
        
    	}
};
int main(){
	vector<int> init={1,2};
	Solution *sol=new Solution;
	auto res=sol->combinationSum(init,3);
	for(auto x:res)
	{
		for(auto y:x)
		{
			cout<<y<<" ";
		}
		cout<<endl;
	}
}
