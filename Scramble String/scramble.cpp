#include <iostream>
#include <set>
using namespace std;
class Solution {
	public:
		bool samechars(string s1,string s2){
			int len=s1.size();
			int count[26] = {0};
			for(int i=0; i<len; i++)
			{
				count[s1[i]-'a']++;
				count[s2[i]-'a']--;
			}

			for(int i=0; i<26; i++)
			{
				if(count[i]!=0)
					return false;
			}

			return true;
		}
		bool isScramble(string s1, string s2) {
			if(s1.size()!=s2.size())
				return false;
			if(!samechars(s1,s2))
				return false;
			if(s1==s2)
				return true;
			int len=s1.size();
			for(int i=1;i<len;i++){
				string s11=s1.substr(0,i);
				string s12=s1.substr(i);

				string s21=s2.substr(0,i);
				string s22=s2.substr(i);
				if(isScramble(s11,s21) and isScramble(s12,s22))
					return true;

				s21=s2.substr(0,len-i);
				s22=s2.substr(len-i);
				if(isScramble(s12,s21) and isScramble(s11,s22))
					return true;
			}
			return false;
		}
};
int main(){
}
