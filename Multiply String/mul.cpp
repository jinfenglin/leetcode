#include <iostream>
#include <string>
using namespace std;
class Solution {
	public: 
		string multi(string num,char single){
			if(num=="0" or single=='0')
				return "0";
			int add=0;
			int remain=0;
			string result="";
			for(int i=num.size()-1;i>=0;i--){
				int n1=num[i]-'0';
				int n2=single-'0';				
				int tmp=n1*n2+add;
				add=tmp/10;
				remain=tmp%10;
				result.insert(result.begin(),remain+'0');
			}
			if(add!=0)
				result.insert(result.begin(),add+'0');
			return result;
		}
		string add_string(string num1,string num2){
			string result;
			int len=max(num1.size(),num2.size());
			int i=num1.size()-1;
			int j=num2.size()-1;
			if(i<j){
				num1.insert(num1.begin(),j-i,'0');
			}else{
				num2.insert(num2.begin(),i-j,'0');
			}
			int add=0;
			for(int x=len-1;x>=0;x--){
				int tmp=num1[x]-'0'+num2[x]-'0'+add;
				//cout<<tmp<<endl;
				add=tmp/10;
				int remain=tmp%10;
				result.insert(result.begin(),remain+'0');
			}
			if(add>0)
				result.insert(result.begin(),add+'0');
			return result;
		}
		string multiply(string num1, string num2) {
			string result="";
			int i=num1.size()-1;
			int j=num2.size()-1;
			for(;i>=0;i--){
				string tmp=multi(num2,num1[i]);
				//cout<<tmp<<endl;
				if(tmp!="0")
					tmp.insert(tmp.end(),num1.size()-i-1,'0');
				result=add_string(result,tmp);
			}
			return result;

		}
};
int main(){
	Solution *sol=new Solution;
	string num="999";
	char single='3';
	//cout<<sol->multi(num,single)<<endl;
	//cout<<sol->add_string("","1230001")<<endl;
	cout<<sol->multiply("0","51")<<endl;
}
