#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;
class Solution {
	public:
		vector<string> table;
		Solution(){
			table={" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		}
		vector<string> letterCombinations(string digits) {
			if(digits.empty())
			{
				vector<string> emp;
				return emp;
			}
			vector<string> result;
			int num=digits[0]-'0';
			string rest=digits.substr(1);

			string chs=table[num];
			for(char add:chs){
				vector<string> part=letterCombinations(rest);
				if(part.empty()){
					result.push_back(string(1,add));
				}
				else
					for(string ans:part){
						ans.insert(ans.begin(),add);
						result.push_back(ans);
					}
				
			}
			return result;
		}
};
int main(){
	Solution *sol=new Solution;
	for(string s:sol->letterCombinations("23"))
		cout<<s<<endl;
}
