#include <iostream>
using namespace std; 
class Solution {
	public:
		int mySqrt(int x) {
			if(x<1)
				return 0;
			unsigned long low=0,high=x;
			unsigned long mid=(low+high)/2;
			while(low<=high){
				//cout<<low<<" "<<mid<<" "<<high<<endl;
				mid=(low+high)/2;
				if(mid*mid<x)
					low=mid+1;
				else if(mid*mid>x)
					high=mid-1;
				else
					return mid;
			}
			return (low+high)/2;
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->mySqrt(2)<<endl;
}
