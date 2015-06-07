#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
	    stack<int> stk;
	    int max_val=0;
	    height.push_back(0);
	    for(int i=0;i<height.size();i++){
	    	if(stk.empty())
			stk.push(i);
		else{
			if(height[stk.top()]<=height[i]){
				stk.push(i);
			}else{
				while(!stk.empty() and height[stk.top()]>height[i]){
					int h=height[stk.top()];
					stk.pop();
					int start=0;
					if(!stk.empty())
						start=stk.top()+1;

					int end=i;
					int len=end-start;
					int area=len*h;
					//cout<<"h:"<<h<<endl;
					//cout<<start<<" "<<end<<" "<<area<<endl;
					max_val=max(max_val,area);
				}
				stk.push(i);
			}
		}
	    }
	    return max_val;
    }
};
int main(){
	vector<int> init={2,1,5,6,2,3};
	Solution *sol=new Solution;
	cout<<sol->largestRectangleArea(init)<<endl;

}
