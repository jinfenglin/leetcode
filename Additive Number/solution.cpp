#include <iostream>
#include <string>
using namespace std;
class Solution {
	public:
		bool recursive(string num,long first,long second){
			if(num.size()==0)
				return true;
			long sum= first+second;
			string match=to_string(sum);
			//cout<<match<<" "<<num<<endl;
			int i=0;
			if(match.size()>num.size())
				return false;
			for(;i<match.size();i++){
				if(match[i]!=num[i])
					return false;
			}
			return recursive(num.substr(i),second,sum);
		}
		bool isAdditiveNumber(string num) {
			if(num.size()==0)
				return false;
			int first,second;
			for(int i=1;i<num.size();i++){
				string fstr=num.substr(0,i);
				if(fstr.size()>1 and fstr[0]=='0')
					break;
				for(int j=i+1;j<num.size();j++){
					string sstr=num.substr(i,j-i);
					if(sstr.size()>1 and sstr[0]=='0')
						break;
					//cout<<fstr<<" "<<sstr<<endl;
					long first=stol(fstr);
					long second=stol(sstr);
					if(j<num.size() and recursive(num.substr(j),first,second))
							return true; 
					
				}
			}
			return false;
		}
};

int main(){
	Solution *sol=new Solution;
	cout<<sol->isAdditiveNumber("199100199")<<endl;
}
