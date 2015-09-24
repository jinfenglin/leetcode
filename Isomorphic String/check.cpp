#include <iostream>
using namespace std;
class Solution {
	public:
		bool isIsomorphic(string s, string t) {
			int s_table[300],t_table[300];
			memset(s_table,-1,sizeof(s_table));
			memset(t_table,-1,sizeof(t_table));
			int len=s.size();
			for(int i=0;i<len;i++){
				int s_loc,t_loc;
				s_loc=s[i];
				t_loc=t[i];
				if(s_table[s_loc]==-1 and t_table[t_loc]==-1){
					s_table[s_loc]=t_loc;
					t_table[t_loc]=s_loc;
					continue;
				}else if(s_table[s_loc]==t_loc and t_table[t_loc]==s_loc){
					continue;
				}
				return false;
			}
			return true;
		}
};
int main(){
}
