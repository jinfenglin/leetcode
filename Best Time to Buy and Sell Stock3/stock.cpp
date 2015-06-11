#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    	int maxProfit(vector<int>& prices) {
		if(prices.size()<=1)
			return 0;
    		vector<int> l(prices.size(),0);
		vector<int> r(prices.size(),0);
		l[0]=0;
		r[prices.size()-1]=0;
		int min_val=prices[0];
		for(int i=1;i<prices.size()-1;i++){
			l[i]=max(l[i-1],prices[i]-min_val);
			if(prices[i]<min_val)
				min_val=prices[i];
		}
		int max_val=prices[prices.size()-1];
		for(int i=prices.size()-2;i>=0;i--){
			r[i]=max(r[i+1],max_val-prices[i]);
			if(prices[i]>max_val)
				max_val=prices[i];
		}
		int result=0;
		for(int i=0;i<prices.size();i++){
			result=max(result,l[i]+r[i]);
		}
		return result;


    }
 };
int main(){
	vector<int> init={4};
	Solution *sol=new Solution;
	cout<<sol->maxProfit(init)<<endl;
}
