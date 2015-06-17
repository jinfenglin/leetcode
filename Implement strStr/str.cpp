#include <string>
#include <iostream>
using namespace std;
class Solution {
	public:
		int strStr(string haystack, string needle) {
			if(haystack.compare(0,needle.size(),needle)==0)
					return 0;
			for(int i=0;i<haystack.size();i++){
				if(haystack.compare(i,needle.size(),needle)==0)
					return i;
			}
			return -1;

		}
};
int main(){
	string str="";
	string needle="";
	Solution *sol=new Solution;
	cout<<sol->strStr(str,needle)<<endl;
}
