#include <iostream>
#include <stack>
using namespace std;
class Solution {
	public:
		void cal(char sign,stack<int> &nums){
			int v1=nums.top();
			nums.pop();
			int v2=nums.top();
			nums.pop();
			//cout<<v1<<sign<<v2<<endl;
			int res=0;
			switch (sign){
				case '+':
					res=v1+v2;
					break;
				case '-':
					res=v2-v1;
					break;
				case '*':
					res=v1*v2;
					break;
				case '/':
					res= v2/v1;
					break;
			}
			//cout<<"res "<<res<<endl;
			nums.push(res); 

		}
		bool low_priority(char sign,stack<char> &signs){
			if(signs.empty())
				return false;
			
			//cout<<sign<<signs.top()<<endl;
			char top=signs.top();
			int top_val=0,sign_val=0;
			if(top=='+' or top=='-')
				top_val=1;
			else if (top=='*' or top=='/')
				top_val=2;
			
			if(sign=='+' or sign=='-')
				sign_val=1;
			else if(sign=='*' or sign=='/')
				sign_val=2;
			//cout<<(sign_val<=top_val )<<endl;
			return sign_val<=top_val;


		}
		int calculate(string s) {
			stack<char> signs;
			stack<int> nums;
			int tmp=0;
			s+='#';
			for(char c:s){
				if(c<='9' and c>='0'){
					tmp=tmp*10+c-'0';	
				}else if(c==' '){
					continue;
				}
				else{
					nums.push(tmp);
					tmp=0;
					while(low_priority(c,signs)){
						cal(signs.top(),nums);	
						signs.pop();
					}
					signs.push(c);
				}
			}
			while(signs.top()!='#'){
				cal(signs.top(),nums);
				signs.pop();
			}
			return nums.top();
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->calculate("1+2")<<endl;
	cout<<sol->calculate("3+5 / 2")<<endl;
}
