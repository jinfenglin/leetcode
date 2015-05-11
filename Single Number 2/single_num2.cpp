#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		int singleNumber(vector<int>& nums) {
			int result=0;
			for(int i=0;i<32;i++)
			{
				int count=0;
				for(vector<int>::iterator it=nums.begin();it!=nums.end();it++)
				{
					count+=((*it)>>i)&1;
				}
				//cout<<count<<endl;
				count=count%3;
				result|=(count<<i);
				
			}
			return result;
		}
};
using namespace std;
int main()
{

	int array[]={1,1,1,2,2,2,4,3,3,3};
	vector<int> init(array,array+sizeof(array)/sizeof(int));
	Solution *sol=new Solution();
	cout<<sol->singleNumber(init)<<endl;
	return 0;
}
