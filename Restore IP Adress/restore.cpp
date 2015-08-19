#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<string> res;
		void restore(string s,int start,int level,string tmp_res){
			//cout<<start<<" "<<tmp_res<<endl;
			if(level>4)
				return;
			for(int i=1;i<=3;i++){
				string ip_seg;
				if(start+i<=s.size())
				{
					ip_seg=s.substr(start,i);
					if(ip_seg.size()>1 and ip_seg[0]=='0')
						return;
				}
				else
					return;
				int ip_val=atoi(ip_seg.c_str());
				if(ip_val>=0 and ip_val<256)
				{
					if(level==4 and s.size()-start-i==0){
						res.push_back(tmp_res+ip_seg);
						return;
					}
					restore(s,start+i,level+1,tmp_res+ip_seg+".");
				}
			}
		}
		vector<string> restoreIpAddresses(string s) {
			restore(s,0,1,"");
			return res;
		}
};
int main(){
	Solution *sol=new Solution;
	vector<string> res=sol->restoreIpAddresses("010010");
	for(string s:res)
		cout<<s<<endl;
}
