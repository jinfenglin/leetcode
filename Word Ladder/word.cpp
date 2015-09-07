#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
	public:
		int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
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
	unordered_set<string> set={"hot","dog"};
	string start="hot";
	string end="dog";
	Solution *sol=new Solution;
	cout<<sol->ladderLength(start,end,set)<<endl;
}
