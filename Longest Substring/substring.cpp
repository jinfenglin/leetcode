#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	    unordered_set<char> st;
	    int left=0,right=0;
	    int result=0;
	    //cout<<s.length()<<endl;
	    while(right<s.length()){
	    	while(st.find(s[right])==st.end() and right<s.length())
		{	
			st.insert(s[right]);
			right++;
			result=max(right-left,result);
		}
		while(s[left]!=s[right] and left<=right){
			st.erase(s[left]);
			left++;
		}
		st.erase(s[left]);
		left++;
		//cout<<left<<" "<<right<<endl;
		
	    }
	    return result;
    				
    }
};
int main(){
	string s="abcdefg";
	Solution *sol=new Solution;
	cout<<sol->lengthOfLongestSubstring(s)<<endl;
}
