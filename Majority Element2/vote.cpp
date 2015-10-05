#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<int> majorityElement(vector<int>& nums) {
			int m1=0,m2=0;
			int n1=0,n2=0;
			for(int num:nums){
				if(m1==num) 
					n1++;
				else if(m2==num)
					n2++;
				else if(!n1){
					m1=num;
					n1=1;
				}else if(!n2){
					m2=num;
					n2=1;
				}else{
					n1--,n2--;
				}
			}
			n1=n2=0;			
			for(int num:nums)
				if(num==m1)
					n1++;
				else if(num==m2)
					n2++;
			vector<int> res;
			if(n1>nums.size()/3)
				res.push_back(m1);
			if(n2>nums.size()/3)
				res.push_back(m2);
			return res;
		}
};

int main(){
	Solution *sol=new Solution;
	vector<int> in ={4,2,1,1};
	for(int num:sol->majorityElement(in))
		cout<<num<<endl;
}
