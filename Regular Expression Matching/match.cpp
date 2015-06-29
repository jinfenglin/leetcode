#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
		bool match(string s,int s_cur,string p,int p_cur){
			if(s_cur>=s.size()){
				if(p_cur==p.size()-2 or p_cur==p.size())
					return true;
				else
					return false;
			}
			if(p[p_cur+1]!='*'){
				if(p[p_cur]==s[s_cur] or p[p_cur]=='.')
					return match(s,s_cur+1,p,p_cur+1);
				else
					return false;
			}else{			
				if(p[p_cur]==s[s_cur] or p[p_cur=='.'])
					if(!match(s,s_cur+1,p,p_cur))
						return match(s,s_cur,p,p_cur+2);
					else
						return true;
				else
					return match(s,s_cur,p,p_cur+2);
			}

		}
		bool isMatch(string s, string p) {
			return match(s,0,p,0);
			
		}
};
int main(){
	string s="cabbccaccabacccbaa";
	string p="b*b*c*b*b*c*.c*.*c";
	Solution *sol=new Solution;
	cout<<sol->isMatch(s,p)<<endl;

}
