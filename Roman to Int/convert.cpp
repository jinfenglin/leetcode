#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
	public:
		int romanToInt(string s) {
			int result=0;
			map<char,int> roman;
			roman['I']=1;  
			roman['V']=5;  
			roman['X']=10;  
			roman['L']=50;  
			roman['C']=100;  
			roman['D']=500;  
			roman['M']=1000; 
			int last=0;
			for(char c:s){
				int current=roman[c];
				result+=current;
				if(last<current){
					result-=2*last;
				}
				last=current;
			}
			return result;
		}
};
int main(){
	string s="CM";
	Solution *sol=new Solution;

	cout<<sol->romanToInt(s)<<endl;
}

