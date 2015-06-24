#include <iostream>
using namespace std;
class Solution {
	public:
		int reverse(int x) {
			int digit=0;
			int result=0;
			while(x){
				
				if(result>INT_MAX/10 or result<INT_MIN/10)
					return 0;
				digit=x%10;
				result=10*result+digit;
				x/=10;
			}
			return result;
		}
};
int main(){
	int x=1534236469;
	Solution *sol=new Solution;
	cout<<sol->reverse(x)<<endl;

}
