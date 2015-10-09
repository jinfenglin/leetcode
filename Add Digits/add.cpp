#include <iostream>
using namespace std;
class Solution {
	public:
		int addDigits(int num) {
			int tmp=0;
			while(num>=10){
				tmp+=num%10;
				num=num/10;
				if(num<10){
					tmp+=num;
					num=tmp;
					tmp=0;
				}
			}
			return num;
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->addDigits(38)<<endl;
}
