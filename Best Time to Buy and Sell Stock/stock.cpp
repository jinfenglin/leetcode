#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
	    if(prices.size()==0)
		    return 0;
	    int min_val=prices[0];
	    int result=0;
	    for(int i=0;i<prices.size();i++)
	    {
		    min_val=min(min_val,prices[i]);
		    result=max(prices[i]-min_val,result);		    
	    }
	    return result;
        
    }
};

int main(){
	vector<int> init={2,1};
	Solution *sol=new Solution;
	cout<<sol->maxProfit(init)<<endl;
	
}
