#include <iostream>
using namespace std;
class Solution {
	public:
		int minCut(string s) {
			int cut[s.size()+1];
			for(int i=0;i<=s.size();i++)
				cut[i]=i-1;

			for(int i=0;i<s.size();i++){
				for(int j=0;i+j<s.size() and i-j>=0 and s[i-j]==s[i+j];j++)
					cut[i+j+1]=min(cut[i+j+1],cut[i-j]+1);
				
				for(int j=1;i+j<s.size() and i-j+1>0 and s[i-j+1]==s[i+j];j++)
					cut[i+j+1]=min(cut[i+j+1],cut[i-j+1]+1);
			}
			return cut[s.size()];
			
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->minCut("bb")<<endl;
}
