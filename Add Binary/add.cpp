#include <iostream>
using namespace std;
class Solution{
	public: 
		string addBinary(string a,string b){
			int add=0;
			int len=max(a.size(),b.size());
			if(a.size()>b.size())
				b.insert(b.begin(),a.size()-b.size(),'0');
			else
				a.insert(a.begin(),b.size()-a.size(),'0');
			string result;
			for(int i=len-1;i>=0;i--){
				int tmp=a[i]-'0'+b[i]-'0'+add;
				add=tmp/2;
				int remain=tmp%2;
				result.insert(result.begin(),remain+'0');
			}
			if(add)
				result.insert(result.begin(),'1');
			return result;
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->addBinary("11","1")<<endl;
}
