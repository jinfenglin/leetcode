#include <iostream>
using namespace std;
class Solution {
	public:
		double myPow(double x, int n) {
			if(n==0)
				return 1;
			bool sign=true;
			if(n<0)
				x=1/x;
			n=abs(n);
			double result=x;
			int i=1;
			for(;i<=n/2;i*=2){
				result*=result;
			}
			return result*myPow(x,n-i);
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->myPow(3,-1)<<endl;
}
