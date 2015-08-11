#include <iostream>
using namespace std;
class Solution {
	public:
		int lengthOfLastWord(string s) {
			int i=s.size()-1;
			int count=0;
			for(;i>=0;i--)
			{
				if(s[i]==' ' and count)
					break;
				else if(s[i]==' ')
					continue;
				else
					count++;
			}
			return count;
		}
};
int main(){
	string s=" ";
	Solution *sol=new Solution;
	cout<<sol->lengthOfLastWord(s)<<endl;
}
