#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> grayCode(int n) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int size = 1<<n;
			vector<int> grayCodes;
			grayCodes.resize(size);

			for (int i = 0; i < size; i++){
				int gCode = i ^ i>>1;
				grayCodes[i] = gCode;
			}

			return grayCodes;
		}
};
int main(){
	Solution *sol=new Solution;
	vector<int> res=sol->grayCode(2);
	for(int i:res)
		cout<<i<<" ";
	cout<<endl;

	res=sol->grayCode(3);
	for(int i:res)
		cout<<i<<" ";
	cout<<endl;


}
