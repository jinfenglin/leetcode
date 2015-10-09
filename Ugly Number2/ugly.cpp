#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int nthUglyNumber(int n) {
			vector<int> ugly={1};
			int i1,i2,i3;
			i1=i2=i3=0;
			for(int i=0;i<n;i++){
				int min3=min(ugly[i1]*2,min(ugly[i2]*3,ugly[i3]*5));
				if(min3==ugly[i1]*2)
					i1++;
				if(min3==ugly[i2]*3)
					i2++;
				if(min3==ugly[i3]*5)
					i3++;
				ugly.push_back(min3);
			}
			return ugly[n-1];
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->nthUglyNumber(7)<<endl;
}
