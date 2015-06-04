#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
			int i=0;
			int j=0;
			if(m==0)
			{
				nums1=nums2;
				return;
			}
			while(j<n and i<m){
				if(nums1[i]<nums2[j] )
					i++;
				else
				{
					nums1.insert(nums1.begin()+i,nums2[j]);
					i++;
					m++;
					j++;
				}
			}
			if(i>=m and j<n)
			{
				nums1.insert(nums1.begin()+m,nums2.begin()+j,nums2.end());
				m+=n-j;
			}
			cout<<m<<" "<<endl;
			nums1=vector<int>(nums1.begin(),nums1.begin()+m);
		}
};
int main(){
	vector<int> nums1={1,0};
	vector<int> nums2={2,3,4,5};
	Solution *sol=new Solution;
	sol->merge(nums1,1,nums2,4);
	for(int i=0;i<nums1.size();i++)
		cout<<nums1[i]<<" ";
	cout<<endl;
}
