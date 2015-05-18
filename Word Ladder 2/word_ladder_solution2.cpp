#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool is_candidate(string word1,string word2){
		if(word1==word2)
			return false;
		int count=0;
		for(int i=0;i<word1.size();i++){
			if(word1[i]!=word2[i])
				count++;
			if(count>=1)
				return false;
		}
		return true;
	}
	vector<string> candidates(string word ,unordered_set<string> dict)
	{
		vector<string> res;
		for(int i=0;i<word.size();i++)
		{
			char tmp=word[i];
			for(char c='a';c<='z';c++)
			{
				word[i]=c;
				cout<<word<<endl;
				if(dict.find(word)!=dict.end())
					res.push_back(word);
			}
			word[i]=tmp;
		}
		return res;
	}
	vector<vector<string> > findLadders(string start,string end,unordered_set<string> &dict){
		vector<vector<string> > res;
		unordered_set<string> small_dict;
		return res;
	}
};
int main()
{
	Solution *sol= new Solution;
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict({"hot","dot","dog","lot","log"});
	auto result=sol->findLadders(start,end,dict);
	for(auto x:result){
		for(auto y:x)
			cout<<y<<" ";
		cout<<endl;
	}
}
