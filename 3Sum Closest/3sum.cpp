#include <iostream>
#include <vector>
#include <stdlib.h>
//#include <climits>
#define MAX 99999
using namespace std;
class Solution {
public:
	int twoSum(vector<int> &nums,int target,int start){
		int close=MAX;
		int result=MAX;
		int l=start;
		int r=nums.size()-1;
		while(l<r){
			int sum=nums[l]+nums[r];
			if(abs(target-sum)<close)
			{
				close=abs(target-sum);
				result=sum;
			}
			if(sum==target)
				return target;
			else if(sum>target)
				r--;
			else
				l++;
		}
		return result;
	}
    	int threeSumClosest(vector<int>& nums, int target) {
        	int res=MAX;
		sort(nums.begin(),nums.end());
		for(int i=0;i<nums.size();i++){
			int tmp=twoSum(nums,target-nums[i],i+1);
			if(tmp==MAX)
				continue;
			cout<<tmp<<endl;
			tmp+=nums[i];
			cout<<"abs"<<endl;
			cout<<abs(target-res)<<" "<<abs(target-tmp)<<endl;
			if(abs(target-res)>abs(target-tmp))
				res=tmp;
		}
		return res;
    	}
};
int main(){
	vector<int> init={1,1,-1,-1,3};
	Solution *sol=new Solution;
	cout<<sol->threeSumClosest(init,-1)<<endl;
}
