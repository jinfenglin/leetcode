#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		void parse(string s,vector<char> &signs,vector<int> &nums){
			int tmp=0;
			for(char c:s){
				if(c<='9' and c>='0'){
					tmp=tmp*10+c-'0';
				}else if(c=='+' or c=='-' or c=='*'){
					signs.push_back(c);
					nums.push_back(tmp);
					tmp=0;
				}
			}
			nums.push_back(tmp);
		}
		int cal(int v1,int v2,char sign){
			switch(sign){
				case '+':return v1+v2;
				case '-':return v1-v2;
				case '*':return v1*v2;
			}
			return 0;
		}
		vector<int> divid(vector<char> &signs,vector<int> &nums){
			vector<int> sol;
			if(signs.empty())
				return nums;
			for(int i=0;i<signs.size();i++){
				vector<int> left,right;
				vector<char> s_left,s_right;
				left.insert(left.begin(),nums.begin(),nums.begin()+i+1);
				right.insert(right.begin(),nums.begin()+i+1,nums.end());
				/*for(int n:left)
					cout<<n<<" ";
				cout<<"|";
				for(int n:right)
					cout<<n<<" ";
				cout<<endl;*/
				s_left.insert(s_left.begin(),signs.begin(),signs.begin()+i);
				s_right.insert(s_right.begin(),signs.begin()+i+1,signs.end());
				/*for(char c:s_left)
					cout<<c<<" ";
				cout<<"|";
				for(char c:s_right)
					cout<<c<<" ";
				cout<<endl;	*/
				vector<int> left_ans=divid(s_left,left);
				vector<int> right_ans=divid(s_right,right);

				for(int n:left_ans)
					for(int m:right_ans){
						//cout<<n<<" "<<m<<" "<<signs[i]<<endl;
						sol.push_back(cal(n,m,signs[i]));
					}
			}
			return sol;
		}
		vector<int> diffWaysToCompute(string input) {
			vector<char> signs;
			vector<int> nums;
			parse(input,signs,nums);
			return divid(signs,nums);

		}
};
int main(){
	Solution *sol=new Solution;
	for(int i:sol->diffWaysToCompute("2-1-1"))
		cout<<i<<endl;
}

