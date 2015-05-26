#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int trap(vector<int>& height) {
			int max=0;
			int water=0;
			for(int x:height)
				if(x>max)
					max=x;
			for(int i=0;i<max;i++){
				int start=0;
				for(int j=0;j<height.size();j++){
					if(height[j]==0)
					{
						if(j>0 and height[j-1]>0)
							start=j-1;
						if(j+1<height.size() and height[j+1]>0)
						{
							water+=j-start;
						}
					}		
				}
			}
			return water;
		}
};
int main(){
	Solution *sol= new Solution;
	//vector<int> init={0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> init={};
	cout<<sol->trap(init)<<endl;
}
