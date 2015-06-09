#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int search(vector<int> height,int start,int end){
			//cout<<start<<" "<<end<<endl;
			if(start>=end)
				return 0;
			
			if(height[start]<height[end])
				return max(height[start]*(end-start),search(height,start+1,end));
			else
				return max(height[end]*(end-start),search(height,start,end-1));

		}
		int maxArea(vector<int>& height) {
			return search(height,0,height.size()-1);
		}
};
int main(){
	vector<int> init={1,2,1};
	Solution *sol=new Solution;
	cout<<sol->maxArea(init)<<endl;
}
