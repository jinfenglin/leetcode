#include <iostream>
using namespace std;
class Solution {
	public:
		int hIndex(vector<int>& citations) {
			int low=0,high=citations.size()-1,mid;
			while(low<high){
				mid=(low+high)/2;
				int h=citations.size()-mid;
				if(citations[mid]>=h)
					high=mid-1;
				else
					low=mid+1;
			}	
			return citations.size()-high-1;
		}
};
int main(){

}
