#include <iostream>
#include <queue>

using namespace std;
class Solution {
	public:
		bool isPalin(string s,int start,int end){
			while(start<=end){
				if(s[start]!=s[end])
					return false;
				start++;
				end--;
			}			
			return true;
		}
		int minCut(string s) {
			queue<pair<int,string>> myq;
			myq.push(pair<int,string>(0,s));
			while(!myq.empty()){
				int top_time=myq.front().first;
				string top_s=myq.front().second;
				myq.pop();

				for(int i=0;i<top_s.size();i++){
					if(isPalin(top_s,0,i)){
						if(i==top_s.size()-1){
							return top_time;
						}
						string next_s=top_s.substr(i+1);
						int next_time=top_time+1;
						myq.push(pair<int,string>(next_time,next_s));
					}

				}
			}
			return 0;
		}
};
int main(){
	Solution *sol=new Solution;
	string s="aaa";
	cout<<sol->minCut(s)<<endl;
}
