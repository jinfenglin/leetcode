#include <iostream>
using namespace std;
class Solution {
	public:
		int longestValidParentheses(string s) {
			stack<int> stk;
			int max_len=0;
			int start=0;
			for(int i=0;i<s;i++){
				if(s[i]=='(')
					stk.push(i);
				else{
					if(stk.empty()){
						start=i+1;
					}else{
						stack.pop();
						max_len=if(stack.empty())
							max(max_len,i-start+1);
						else
							max_len=max(max_len,i-stack.peek());
					}
					
				}
			}
			return max_len;
		}
};
int main(){
}
