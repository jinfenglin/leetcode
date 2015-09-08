#include <iostream>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;
class Solution {
	public:
		void DFS(string start, string end,vector<string> &solution,vector<vector<string>> &res,unordered_set<string> &dict,int depth){
			if(depth==0)
				return;
			for(int i=0;i<start.size();i++){
				char tmp=start[i];
				for(int j=0;j<26;j++){
					if(tmp=='a'+j)
						continue;			
					start[i]='a'+j;
					//cout<<start<<endl;
					if(start==end){
						solution.push_back(start);
						res.push_back(solution);
						solution.pop_back();
						//cout<<start<<" "<<res.size()<<endl;
						return ;	
					}
					if(dict.find(start)!=dict.end()){
						solution.push_back(start);
						dict.erase(start);
						//cout<<start<<" "<<depth<<endl;

						DFS(start,end,solution,res,dict,depth-1);
						solution.pop_back();
						dict.insert(start);
					}			
					start[i]=tmp;
				}
			}

		}
		vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
			int depth=ladderLength(start,end,dict);
			vector<vector<string>> res;	
			vector<string> solution;
			solution.push_back(start);
			DFS(start,end,solution,res,dict,depth-1);
			return res;


		}
		int ladderLength(string beginWord, string endWord, unordered_set<string> wordDict) {
			queue<pair<string,int>> myq;
			if(beginWord==endWord)
				return 1;
			myq.push(pair<string,int>(beginWord,1));
			while(!myq.empty()){
				pair<string,int> cur_pair=myq.front();
				string cur_str=cur_pair.first;
				int cur_time=cur_pair.second;
				myq.pop();
				for(int i=0;i<cur_str.size();i++){
					char tmp=cur_str[i];
					for(int j=0;j<26;j++){
						if(cur_str[i]=='a'+j)
							continue;			
						cur_str[i]='a'+j;
						if(cur_str==endWord)
							return cur_time+1;

						if(wordDict.find(cur_str)!=wordDict.end()){
							myq.push(pair<string,int>(cur_str,cur_time+1));
							wordDict.erase(cur_str);
						}						
						cur_str[i]=tmp;
					}
				}
			}
			return 0;
		}

};
int main(){
	Solution *sol=new Solution;
	string start="hit";
	string end="cog";
	unordered_set<string> set={"hot","dot","dog","lot","log"};
	auto res=sol->findLadders(start,end,set);
	for(vector<string> vs:res){
		for(string s:vs)
			cout<<s<<" ";
		cout<<endl;
	}
}
