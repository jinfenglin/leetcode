#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int factorial(int num){
			int res=1;
			for(int i=1;i<=num;i++){
				res*=i;
			}
			return res;

		}
		int pick(vector<bool> &flag,int order){
			cout<<order<<endl;
			int count=0;
			int i=0;
			for(;i<flag.size();i++){
				if(flag[i]){
					count++;
				}
				if(count==order){
					break;
				}
			}
			flag[i]=0;
			return i;
		}
		string getPermutation(int n, int k) {
			vector<bool> flag(n,true);
			string res;
			k--;
			int per_amount=factorial(n);
			for(int i=n;i>0;i--){
				per_amount/=i;
				int order=k/per_amount+1;
				k=k%per_amount;
				res+=pick(flag,order)+1+'0';
			}
			return res;
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->getPermutation(3,3)<<endl;
}
