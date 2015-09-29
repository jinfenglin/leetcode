#include <iostream>
using namespace std;
class Solution {
	public:	
		string largestNumber(vector<int>& nums) {
			vector<string> num_string;
			string res="";
			for(int num:nums){
				num_string.push_back(to_string(num));
			}
			sort(num_string.begin(),num_string.end(),[](const string &m,const string &n){ return m+n > n+m; });

			for(string str:num_string){
				res+=str;
			}
			return res;
		}
};
int main(){
}
