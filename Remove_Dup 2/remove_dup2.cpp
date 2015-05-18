#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	    if (nums.size()<=2)
		    return nums.size();
	    int counter=0;
	    int cur_ptr=1;
	    for(int i=1;i<nums.size();i++){
		  		    
		    if(nums[i]==nums[i-1])
		    {
			    counter++;
			    if(counter<2){
				nums[cur_ptr]=nums[i];
			    	cur_ptr++;
			    }
		    }
		    else{
			    
			    nums[cur_ptr]=nums[i];
			    cur_ptr++;			    
			    counter=0;
		    }
		    
	    }
	    return cur_ptr;
        
    }
};

int main(){
	Solution *sol= new Solution;
	vector<int> init={1,1,1,2,2,3};
	int result=sol->removeDuplicates(init);
	for(int i=0;i<result;i++){
		cout<<init[i]<<" ";
	}
	cout<<endl;

}
