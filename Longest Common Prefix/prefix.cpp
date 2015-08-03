#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			if(strs.size()==0)
				return "";
			string result=strs[0];
			int len=strs[0].size();

			for(string s:strs){
				int round=min((int)s.size(),len);
				int i=0;
				for(;i<round;i++){
					//len=i;
					if(s[i]!=result[i])
						break;
				}
				len=i;
			}
			return result.substr(0,len);
		}
};
int main(){
	vector<string> test={"ab","b","abcd"};
	Solution *sol= new Solution;
	cout<<sol->longestCommonPrefix(test)<<endl;

}
