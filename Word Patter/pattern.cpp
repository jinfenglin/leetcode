#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
	public:
		vector<string> split(string str){
			size_t pos=0;
			size_t i=0;
			vector<string> tokens;
			while(pos!=string::npos){
				pos=str.find(" ",pos+1);
				tokens.push_back(str.substr(i,pos-i));
				i=pos+1;
			}
			return tokens;
		}
		bool wordPattern(string pattern, string str) {
			unordered_map<char,string> umap;
			set<string> st;
			vector<string> tokens=split(str);
			if(pattern.size()!=tokens.size())
				return false;
			int i=0;	
			for(char c:pattern){
				if(umap.find(c)==umap.end() and st.find(tokens[i])==st.end()){
					umap[c]=tokens[i];
					st.insert(tokens[i]);
				}
				else
					if(umap[c]!=tokens[i])
						return false;
				i++;
			}
			return true;
		}
};
int main(){
	Solution *sol=new Solution;
	auto vec=sol->split("this is a sentence");
	for(string str:vec)
		cout<<str<<endl;
}
