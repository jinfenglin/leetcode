#include <iostream>
#include <stack>
using namespace std;
class Solution {
	public:
		string simplifyPath(string path) {
			stack<string> stk;
			string result="";
			string tmp;
			if(*path.end()!='/')
				path+='/';
				
			for(char c:path){
				if(c=='/'){
					//cout<<tmp<<endl;
					if(tmp==".."){
						if(!stk.empty())
							stk.pop();
					}
					else if(!tmp.empty() and tmp!=".")
						stk.push(tmp);
					tmp="";
				}
				else
					tmp+=c;
			}
			while(!stk.empty())
			{
				result=stk.top()+result;
				result="/"+result;
				stk.pop();
			}
			if(result.empty())
				result="/";
			return result;
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->simplifyPath("/...")<<endl;
}
