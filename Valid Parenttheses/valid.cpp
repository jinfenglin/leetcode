#include <iostream>
#include <stack>
using namespace std;
class Solution {
	public:
		bool isValid(string s) {
			stack<char> stk;
			for(int i=0;i<s.size();i++){
				if(stk.empty())
					stk.push(s[i]);
				else
					switch(s[i]){
						case ']':
							if(stk.top()=='[')
								stk.pop();
							else
								stk.push(s[i]);
							break;
						case '}':
							if(stk.top()=='{')
								stk.pop();
							else
								stk.push(s[i]);
							break;
						case ')':
							if(stk.top()=='(')
								stk.pop();
							else
								stk.push(s[i]);
							break;
						default:
							stk.push(s[i]);}
			}
			return stk.empty();
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->isValid("(])")<<endl;
}
