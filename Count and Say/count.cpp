#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Solution {
	public:
		string interleave(string say,string count){
			string result="";
			for(int i=0;i<say.size();i++){
				result+=count[i];
				result+=say[i];
			}
			return result;
		}
		string make_count(string raw_say){
			string result="";
			for(int i=0;i<raw_say.size();i++){
				int count=1;
				//cout<<i<<endl;
				while(i<raw_say.size()-1 and raw_say[i]==raw_say[i+1]){
					i++;
					count++;
				}
				result+='0'+count;
			}
			return result;
		}
		string make_say(string raw_say){
			string result="";
			for(int i=0;i<raw_say.size();i++){
				while(i<raw_say.size()-1 and raw_say[i]==raw_say[i+1]){
					i++;
				}
				result+=raw_say[i];
			}
			return result;

		}
		string countAndSay(int n) {
			string count="1";
			string say="1";
			string raw_say="1";
			for(int i=1;i<n;i++){
				raw_say=interleave(say,count);
				count=make_count(raw_say);
				say=make_say(raw_say);
			}
			return raw_say;
		}
};
int main(){
	Solution *sol=new Solution;
	string say="1223334";
	string count="1234567";
	//cout<<sol->interleave(say,count)<<endl;
	//cout<<sol->make_count(say)<<endl;
	//cout<<sol->make_say(say)<<endl;
	cout<<sol->countAndSay(1)<<endl;
}
