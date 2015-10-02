#include <iostream>
#include <stack>
using namespace std;
class Solution {
	public:
		int cal(char sign,stack<int> &nums){
			int v1=nums.top();
			nums.pop();
			int v2=nums.top();
			nums.pop();
			cout<<v1<<sign<<v2<<endl;
			return sign=='+'? v2+v1:v2-v1;
		}

		int calculate(string s) {
			stack<int> nums;
			stack<char> signs;
			signs.push('#');
			int tmp=-1;
			s+='#';
			for(char c:s){
				if(c<='9' and c>='0'){
					if(tmp==-1)
						tmp=c-'0';
					else
						tmp=tmp*10+c-'0';
				}
				else if(c==' ')
					continue;
				else{
					
					if(tmp>=0){
						nums.push(tmp);
						tmp=-1;
					}
					char last=signs.top();
					//cout<<nums.top()<<endl;
					switch(c){
						case '+': if(last=='(' or last=='#')
								  signs.push(c);
							  else{
								  signs.pop();
								  nums.push(cal(last,nums));
								  signs.push(c);
							  }
							  break;
						case '-':
							  if(last=='(' or last=='#')
								  signs.push(c);
							  else{
								  signs.pop();
								  nums.push(cal(last,nums));
								  signs.push(c);
							  }
							  break;

						case '(':
							  signs.push(c);break;
						case ')':
							  //cout<<"top:"<<signs.top()<<endl;
							  while(signs.top()!='(' and signs.top()!='#'){
							  	nums.push(cal(signs.top(),nums));
								signs.pop();
							  }
							  signs.pop();
							  break;
						case '#':
							  //cout<<"top:"<<signs.top()<<endl;
							  while(signs.top()!='#'){
							  	nums.push(cal(signs.top(),nums));
								signs.pop();
							  }
							  break;
					}
				}
			}
			return nums.top();

		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->calculate("1+5-4")<<endl;
}

