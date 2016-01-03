#include <iostream>
using namespace std;
class Solution {
	public:
		int countDigitOne(int n) {
			long long int res=0;
			int highn=n,lowc=1,lown=0;
			while(highn>0){
				int curn=highn%10;
				highn=highn/10;
				if(curn==1){
					res+=highn*lowc;
					res+=lown+1;
				}else if(curn==0){
					res+=highn*lowc;
				}else{
					res+=(highn+1)*lowc;
				}
				lown=curn*lowc+lown;
				lowc=lowc*10;
			}
			return res;
		}
};
int main(){
}
