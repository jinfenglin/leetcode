#include <iostream>
using namespace std;
class Solution {
	public:
		bool isAnagram(string s, string t) {
			int char_pool[26];
			if(s.size()!=t.size())
				return false;
			memset(char_pool,0,26*sizeof(int));
			for(char c:s){
				char_pool[c-'a']+=1;	
			}
			for(char c:t){
				if(!char_pool[c-'a'])
					return false;
				char_pool[c-'a']--;
			}
			return true;

		}
};
int main(){
}
