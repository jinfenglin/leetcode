#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		bool isPalindrome(string &s,int start,int end){
			if(start==end)
				return true;
			while(start<end){
				if(s[start]!=s[end])
					return false;
				start++;
				end--;
			}
			return true;
		}
		void combine(string s,vector<vector<string>> &tmp,vector<vector<string>> &res){
			for(vector<string> vec:tmp){
				vec.insert(vec.begin(),s);
				res.push_back(vec);
			}
		}
		vector<vector<string>> part(string &s,int start,int end){
			cout<<start<<" "<<end<<endl;
			vector<vector<string>> res;
			if(start==end)
			{
				res.push_back(vector<string>(1,s.substr(start,1)));
				return res;
			}
			else if(start>end)
			{
				res.push_back(vector<string>());
				return res;
			}
			for(int i=start;i<=end;i++){
				if(isPalindrome(s,start,i)){
					vector<vector<string>> tmp= part(s,i+1,end);
					combine(s.substr(start,i-start+1),tmp,res);
				}
			}			
			return res;	
		}
		vector<vector<string>> partition(string s) {
			return part(s,0,s.size()-1);
			
		}		
};
int main(){
	Solution *sol=new Solution;
	vector<vector<string>> res=sol->partition("aa");
	//string s="abc";
	//cout<<s.substr(1,1)<<endl;
	for(vector<string> vec:res){
		for(string parts:vec){
			cout<<parts<<" ";
		}
		cout<<endl;
	}
}
