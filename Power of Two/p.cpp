#include <iostream>
using namespace std;
class Solution {
	public:
		bool isPowerOfTwo(int n) {
			if(n<=0)
				return false;
			int ruler=1;
			bool meet_one=false;
			for(int i=0;i<32;i++){
				if((n&ruler)!=0 and !meet_one)
					meet_one=true;
				else if((n&ruler)!=0)
					return false;
				ruler=ruler<<1;
			}
			return true;
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->isPowerOfTwo(-INT_MIN)<<endl;
}
