#include <stdint.h>
#include <iostream>
#include <cassert>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
	    uint32_t result=0;
	    for(int i=0;i<32;i++)
	    {
		    uint32_t temp_bit=n & 1;
		    n>>=1;
		    result<<=1;
		    result= result | temp_bit;
	    }
	    cout<<result<<endl;
	    return result;  
    }
};

int main()
{
	Solution *sol=new Solution();

	//cout<<"Done"<<endl;
	return 0;	
}
