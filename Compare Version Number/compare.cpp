#include <iostream>
using namespace std;
class Solution {
	public:
		int composeNumber(string s,int &start){
			int res=0;
			for(;start<s.size();start++){
				if(s[start]=='.')
				{
					start++;
					return res;
				}
				res=10*res+s[start]-'0';
			}
			return res;
		}
		int compareVersion(string version1, string version2) {
			int num1=0,num2=0;
			int ptr1=0,ptr2=0;
			while(ptr1<version1.size() or ptr2<version2.size()){
				//cout<<ptr1<<ptr2<<endl;
				num1=composeNumber(version1,ptr1);
				num2=composeNumber(version2,ptr2);
				cout<<num1<<" "<<num2<<endl;
				if(num1>num2)
					return 1;
				else if(num1<num2)
					return -1;
			}
			return 0;

		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->compareVersion("1","1.1")<<endl;

}
