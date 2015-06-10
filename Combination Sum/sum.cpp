#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	 vector<vector<int> > recu(vector<int> candidates,int target,int start){
			vector<vector<int> > res;
			if(target<0)
				return res;
			for(int i=start;i<candidates.size();i++){
				int cur=candidates[i];
				if(target-cur==0){
					vector<int> tmp;
					tmp.push_back(cur);
					res.push_back(tmp);
					
				}
				vector<vector<int> > part=recu(candidates,target-cur,i);
				for(int j=0;j<part.size();j++)
				{
					part[j].push_back(cur);
					sort(part[j].begin(),part[j].end());
				}
				res.insert(res.begin(),part.begin(),part.end());				
			}
			return res;

				 
	 }
   	 vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		 return recu(candidates,target,0);
        
    	}
};
int main(){
	vector<int> init={4,2,8};
	Solution *sol=new Solution;
	auto res=sol->combinationSum(init,8);
	for(auto x:res)
	{
		for(auto y:x)
		{
			cout<<y<<" ";
		}
		cout<<endl;
	}
}
