#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int length=nums.size();
		long int digit=100000000;
		int *arr_p= (int *)malloc(digit*sizeof(int));
		memset(arr_p,0,digit*sizeof(int));
		for(vector<int>::iterator it=nums.begin();it !=nums.end();it++)
		{
			int array_location= (*it)/32 ;
			int bit_location=   (*it)%32 ;
			arr_p[array_location]=arr_p[array_location]^(1<<bit_location);
		}
		int target=0;
		int count=0;
		

		for(int i=0;i<digit;i++)
		{
			if (arr_p[i]!=0)
			{
				target=arr_p[i];
				count=i;
			}
		}	
		int bit=0;
		for(int i=0;i<32;i++)
		{
			target>>=1;
			if((target&1) !=0)
				bit=i;
		}
		return 32*count+bit+1;
	}
};

int main()
{
	int array[]={1};
	vector<int> input=vector<int>(array,array+sizeof(array)/sizeof(int));
	Solution *sol=new Solution();
	cout<< sol->singleNumber(input)<<endl;	
	return 0;
}
