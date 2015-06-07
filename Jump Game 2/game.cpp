#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int jump(vector<int>& nums) {
			int end=nums.size()-1;
			if(nums.size()==1)
				return 0;
			int c=0;
			int last=0;
			for(int i=0;i<=end;c++){
				int next_val=nums[i]+i;
				int next=i+nums[i];
				if(end<=next)
					return c+1;
				for(int j=i+1;j<=i+nums[i];j++){
					//cout<<"nums[j]+j:"<<nums[j]+j<<endl;
					//cout<<"next:"<<next<<endl;
					if(nums[j]+j>=next_val)
					{
						next_val=nums[j]+j;
						next=j;
					}
					
				}
				i=next;
							
			}
		}
};
int main(){
	vector<int> init={2,3,1};
	Solution *sol=new Solution;
	cout<<sol->jump(init)<<endl;
}
