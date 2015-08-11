#include <iostream>
#include <functional>
#include <vector>
#include <map>
using namespace std;
class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			map<string,vector<string>> raw_res;
			vector<vector<string>> res;
			for(string s: strs){
				string cp=s;
				sort(s.begin(),s.end());
				raw_res[s].push_back(cp);

			}			
			for(pair<string,vector<string>> p:raw_res){
				sort(p.second.begin(),p.second.end());
				res.push_back(p.second);
			}
			return res;

		}

};
int main(){
	vector<string> test={"ate","tea","tan","nat","bat"};
	Solution *sol=new Solution;
	auto res=sol->groupAnagrams(test);
	for(auto vs:res)
	{
		for(string s:vs)
			cout<<s<<" ";
		cout<<endl;
	}
	cout<<endl;

}
