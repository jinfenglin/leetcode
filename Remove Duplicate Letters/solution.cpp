#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <set>
using namespace std;
class Solution {
	public:
		string removeDuplicateLetters(string s) {
			stringstream result;
			set<char> check;
			stack<char> stk;
			vector<int> table(26,0);
			for(char c:s){
				table[c-'a']+=1;
			}
			for(char c:s){
				if(stk.empty()){
					stk.push(c);
					check.insert(c);
				}
				else if(check.find(c)==check.end()){
					while(!stk.empty() and c<stk.top() and table[stk.top()-'a']){
						check.erase(stk.top());
						stk.pop();
					}
					stk.push(c);
					check.insert(c);
				}
				table[c-'a']--;
			}
			while(!stk.empty()){
				result<<stk.top();
				stk.pop();
			}
			string str=result.str();
			reverse(str.begin(),str.end());
			return str;
		}
};

int main(){
	Solution *sol=new Solution;
	cout<<sol->removeDuplicateLetters("cbacdcbc")<<endl;
}
