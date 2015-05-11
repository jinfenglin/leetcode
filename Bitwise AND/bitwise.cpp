#include <iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
	while(n>m)
	{
		n=n&n-1;
	}		
	    return n;
        
    }
};
int main()
{
	Solution *sol=new Solution();
	cout<<sol->rangeBitwiseAnd(5,7)<<endl;
}
