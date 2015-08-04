#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<string> generateParenthesis(int n) {
			vector<string> result;
			vector<string> mid_vec;
			vector<string> front_vec;
			vector<string> end_vec;
			if(n==1)
			{
				result.push_back("()");
				return result;
			}else if(n==0)
				return result;

			vector<string> part=generateParenthesis(n-1);
			for(string s:part){
				string mid="("+s+")";
				string front="()"+s;
				string end=s+"()";
				mid_vec.push_back(mid);
				front_vec.push_back(front);
				//result.push_back(mid);
				//result.push_back(front);
				if(front!=end)
				{
					end_vec.push_back(end);
					//result.push_back(end);
				}
			}
			for(string s:mid_vec)
				result.push_back(s);
			for(string s:end_vec)
				result.push_back(s);
			for(string s:front_vec)
				result.push_back(s);


			return result;

		}
};
int main(){
	Solution *sol=new Solution;
	for(string s:sol->generateParenthesis(4))
	{
		cout<<s<<endl;
	}
}
