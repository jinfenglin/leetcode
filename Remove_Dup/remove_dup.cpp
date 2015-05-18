#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	    unordered_set<int> myset;
	    int length=nums.size();
	    for(int i=0;i<length;i++){
		    int x=nums[i];
		    if(myset.find(x)!=myset.end()){
		    	length--;
			i--;
			nums.erase(nums.begin()+i);
		    }else{
			    myset.insert(x);
		    }
	    }
	    return myset.size();
        
    }
};
int main(){
	Solution *sol=new Solution;
	vector<int> init= {1,2,2};
	cout<<sol->removeDuplicates(init)<<endl;
	for(auto x: init){
		cout<<x<<" ";
	}
	cout<<endl;
	
}
