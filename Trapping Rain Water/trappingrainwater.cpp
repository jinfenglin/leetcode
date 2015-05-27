#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
	public:
		int cal_water(stack<int> small_hill){
			if(small_hill.empty())
				return 0;
			int water=0;
			int start=small_hill.top();
			while(!small_hill.empty()){
				if(start>small_hill.top())
					water+=start-small_hill.top();
				small_hill.pop();
			}
			//cout<<water<<endl;
			return water;
		};
		int trap(vector<int>& height) {
			if(height.size()<3)
				return 0;
			stack<int> hill;
			int water=0;
			int bottom=0;
			for(int i=0;i<height.size();i++){
				if(hill.empty() and height[i]==0)
					continue;
				else if(hill.empty()){
					bottom=height[i];
					hill.push(height[i]);
					continue;
				}
				stack<int> small_hill;
				if(height[i]>=bottom){
					while(!hill.empty()){
						small_hill.push(hill.top());
						hill.pop();
					}
					water+=cal_water(small_hill);
					bottom=height[i];
				}

				hill.push(height[i]);
			}
			vector<int> new_iter;
			while(!hill.empty())
			{
				new_iter.push_back(hill.top());
				hill.pop();
			}
			water+=trap(new_iter);
			return water;
		}
};
int main(){
	Solution *sol= new Solution;
	//vector<int> init={0,1,0,2,1,0,1,3,2,1,2,1};
	//vector<int> init={0,1,0,2,1,0,1,3};
	vector<int> init={2,0,2};
	cout<<sol->trap(init)<<endl;
}
