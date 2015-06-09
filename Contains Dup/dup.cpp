#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
	    unordered_set<int> st; 
	    for(int x:nums){
	    	if(st.find(x)==st.end()){
			st.emplace(x);
		}else
			return true;
	    }
	    return false;
        
    }
};
int main(){
	Solution *sol=new Solution;
	vector<int> init1={0,1,2,3,4,0};
	vector<int> init2={1};
	cout<<sol->containsDuplicate(init1)<<endl;
	cout<<sol->containsDuplicate(init2)<<endl;

}
