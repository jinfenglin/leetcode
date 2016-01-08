#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int nthSuperUglyNumber(int n, vector<int>& primes) {
			vector<int> dp;
			dp.push_back(1);
			vector<int> primeIndex(primes.size(),0);
			for(int i=0;i<n;){
				int min_val=INT_MAX;
				int min_index=-1;
				for(int j=0;j<primes.size();j++){
					int tmp=dp[primeIndex[j]]*primes[j];
					if(tmp<min_val){
						min_val=tmp;
						min_index=j;
					}
				}

				primeIndex[min_index]+=1;
				if(i==0 or dp[i]!=min_val){
					dp.push_back(min_val);
					i++;
				}
			}
			return dp[n-1];
		}
};
int main(){
	Solution *sol=new Solution;
	vector<int> in={2,3,5};
	cout<<sol->nthSuperUglyNumber(7,in)<<endl;
}
