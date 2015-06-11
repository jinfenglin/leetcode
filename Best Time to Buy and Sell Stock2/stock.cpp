#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    int maxProfit(vector<int>& prices) {
	    int result=0;
	    if(prices.size()==0)
		    return 0;
	    int min_val=prices[0];
	    for(int i=0;i<prices.size();i++){
	    	min_val=min(min_val,prices[i]);
		if(i+1==prices.size() or prices[i+1]<prices[i]){
			//cout<<prices[i]<<" "<<min_val<<endl;
			result+=prices[i]-min_val;
			min_val=prices[i];
		}
	    }
	    return result;
    }
};
int main(){
	vector<int> init={5,4,3,4,2,6,1,5};
	Solution *sol=new Solution;
	cout<<sol->maxProfit(init)<<endl;
}
