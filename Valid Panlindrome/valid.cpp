#include <iostream>
#include <string>
using namespace std;
class Solution {
	public:
		bool isAlph(char c){
			if('0'<=c and c<='9')
				return true;
			if('a'<=c and c<='z')
				return true;
			if('A'<=c and c<='Z' )
				return true;
			return false;
		}
		bool isPalindrome(string s) {
			int end=s.length()-1;
			int start=0;
			while(start<=end){
				
				while(!isAlph(s[start]) and start<end)
					start++;
				while(!isAlph(s[end]) and start<end)
					end--;

				if(tolower(s[start])!=tolower(s[end]))
					return false;
				start++;
				end--;
				
			}
			return true;

		}
};
int main(){
	string s1="A man, a plan, a canal: Panama";
	string s2="1b2";
	Solution *sol=new Solution;
	cout<<sol->isPalindrome(s1)<<endl;
	cout<<sol->isPalindrome(s2)<<endl;
}
