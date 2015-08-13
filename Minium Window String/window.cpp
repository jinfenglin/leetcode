#include <iostream>
#include <map>
#include <set>
using namespace std;
class Solution {
	public:
		string minWindow(string s, string t) {
			if(s.empty())
				return "";
			map<char,int> count;
			map<char,int> standar;
			set<char> content;
			for(char c:t)
			{
				content.insert(c);
				standar[c]++;
			}
			int need=t.size();
			int begin=0,end=0;
			int min_begin=0,min_end=0;
			while(end<s.size()){				
				while(need!=0 and end<s.size()){
					char c=s[end];
					if(content.find(c)!=content.end()){
						if(count[c]<standar[c]){
							need--;
						}
						count[c]++;
					}
					end++;
				}
				while(need==0 and begin<=end){
					char c=s[begin];
					if(content.find(c)!=content.end()){	
						count[c]--;
						if(count[c]<standar[c]){
							need++;
						}
						//cout<<c<<":"<<count[c]<<endl;
					}
					//cout<<c<<":"<<count[c]<<endl;
					begin++;
				}
				//cout<<begin<<" "<<end<<endl;
				if(end-begin<min_end-min_begin or (min_end==0 and min_begin==0)){
					min_end=end;
					min_begin=begin;
				}
			}

			cout<<min_begin<<" "<<min_end<<endl;
			if(min_begin==0)
				return "";
			return s.substr(min_begin-1,min_end-min_begin+1);
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->minWindow("aa","aa")<<endl;
}
