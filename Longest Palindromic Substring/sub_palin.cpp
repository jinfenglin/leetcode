#include <iostream>
#include <string>
using namespace std;
class Solution {
	public:
		string myfunc(string s){
			int max_len=0;
			int left=0,right=0,max_left=0,max_right=0;
			if(s.size()<2)
				return s;
			for(int start=0;start<s.size();){
				right=left=start;
				while(right<s.size()-1 and s[right]==s[right+1])
					right++;
				start=right+1;
				while(left-1>=0 and right+1<s.size() and s[right+1]==s[left-1] ){
					right++;
					left--;
				}
				//cout<<left<<" "<<right<<endl;
				if(right-left>max_len)
				{
					max_right=right;
					max_left=left;
					max_len=right-left;
				}
			}
			return s.substr(max_left,max_right-max_left+1);
		}
		string longestPalindrome(string s) {
			int len=s.size();
			int max_len=0;
			int start=0;
			int end=0;
			bool **table=(bool **)malloc(sizeof(bool *)*len);
			for(int i=0;i<len;i++)
				table[i]=(bool *)malloc(sizeof(bool)*len);
			for(int i=0;i<len;i++)
			{
				table[i][i]=true;
				for(int j=0;j<i;j++){
					table[i][j]=(s[i]==s[j] and (i-j<2 or table[i-1][j+1]));
					if(table[i][j] and i-j>max_len){
						start=j;
						end=i;
						max_len=end-start;

					}

				}
			}
			return s.substr(start,end-start+1);

		}
};
int main(){
	string str1="abba";
	string str2="adsfabbacddfsda";
	string str3="skaaks";
	string str4="aaaaa";
	Solution *sol=new Solution;
	cout<<sol->myfunc(str1)<<endl;
	cout<<sol->myfunc(str2)<<endl;
	cout<<sol->myfunc(str3)<<endl;
	cout<<sol->myfunc(str4)<<endl;

}



