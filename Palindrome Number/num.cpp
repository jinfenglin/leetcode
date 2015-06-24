#include <iostream>

using namespace std;
class Solution {
	public:
		int pow(int base,int time){
			int result=1;
			for(int i=0;i<time;i++)
				result*=base;
			return result;
		}
		bool isPalindrome(int x) {
			if(x<0)
				return false;
			int len=0;
			int copy=x;
			if(copy==0)
				len=1;
			else
				while(copy){
					len++;
					copy/=10;
				}
			if(len==1)
				return true;
			if(len==0)
				return false;
			int chopper=pow(10,len-1);
			while(x){
				//cout<<x<<endl;
				/*if(x<10)
					return true;*/
				int first=x/chopper;
				int last=x%10;
				x=x%chopper;
				x=x/10;
				chopper/=100;
				if(first!=last)
					return false;
			}
			return true;
			
		}
};
int main(){
	int x=0;
	Solution *sol=new Solution;
	cout<<sol->isPalindrome(x)<<endl;
}
