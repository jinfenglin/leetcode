#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int minSubArrayLen(int s, vector<int>& nums) {
			int n=nums.size()-1;
			int count=0;
			//int **array=(int **)malloc(sizeof(int *) * n);
			int *array[n];
			for(int i=0;i<=n;i++){
				array[i]=(int *)malloc(sizeof(int)*n);
			}		
			for(int i=0;i<=n;i++)
			{
				array[i][0]=nums[i];
			}
	
			for(int i=n;i>=0;i--)
			{
				for(int j=1;j<=n-i;j++){
					array[i][j]=array[i][j-1]+array[i+j][0];
					if(array[i][j]>=s)
						if(count==0 or j<count)
							count=j;
				}
			}
			return count+1;
		}
};
int main(){
	vector<int> init={10,5,13,4,8,4,5,11,14,9,16,10,20,8};
	Solution *sol=new Solution;
	cout<<sol->minSubArrayLen(80,init)<<endl;
	//cout<<sol->minSubArrayLen(7,init)<<endl;
}
