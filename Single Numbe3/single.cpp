#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<int> singleNumber(vector<int>& nums) {
			int tester=0;
			for(int num:nums){
				tester^=num;
			}
			int judger=1;
			while((tester&1) ==0){
				tester>>=1;
				judger<<=1;
			}
			int num1=0,num2=0;
			for(int num:nums){
				if((judger&num) ==0)
					num1^=num;
				else
					num2^=num;
			}
			vector<int> res;
			res.push_back(num1);
			res.push_back(num2);
			return res;
		}
};
int main(){
	Solution *sol=new Solution;
	vector<int> vec={1,2,1,3,2,5};
	for(int c:sol->singleNumber(vec))
		cout<<c<<endl;
}
