#include <iostream>
#include <string>
using namespace std;
class Solution {
	public:
		int myAtoi(string str) {
			int i=0,result=0;
			for(;i<str.size();i++){
				if(str[i]==' ')
					continue;
				else if((str[i]<='9' and str[i]>=0) or str[i]=='+' or str[i]=='-')
					break;
				else
					return 0;			
					
			}
			int sign=true;
			if(str[i]=='+')
				i++;
			else if (str[i]=='-')
			{
				sign=false;
				i++;
			}
			for(;i<str.size();i++){
				if(str[i]<='9' and str[i]>='0'){
					if(result>INT_MAX/10 or (result==INT_MAX/10 and str[i]>='8' and str[i]<='9'))
						if(sign)
							return INT_MAX;
						else
							return INT_MIN;
					else
						result=10*result+str[i]-'0';
				}
				else
					break;
			}

			if(sign)
				return result;
			else
				return -result;
		}
};
int main(){
	string str="   2147483648";
	Solution *sol=new Solution;
	cout<<sol->myAtoi(str)<<endl;

}
