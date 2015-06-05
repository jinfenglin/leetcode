#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int findKth(vector<int> &nums1,int s1,int e1,vector<int>& nums2,int s2,int e2,int k){
			int l1=e1-s1+1;
			int l2=e2-s2+1;
			//cout<<"s1:e1 "<<s1<<" "<<e1<<endl;
			//cout<<"s2:e2 "<<s2<<" "<<e2<<endl;

			if(l1==0 and l2==0)
				return -1;
			else if(l1==0)
			{
				cout<<"return"<<nums2[s2+k-1]<<endl;
				return nums2[s2+k-1];
			}
			else if(l2==0)
			{
				cout<<"return"<<nums1[s1+k-1]<<endl;
				return nums1[s1+k-1];
			}
			if(k==1)
				return min(nums1[s1],nums2[s2]);
			int i=min(l1,k/2);
			int j=min(l2,k-i);
			//cout<<"i:j "<<i<<" "<<j<<endl;	
			//cout<<"k:"<<k<<endl;
			if(nums1[s1+i-1]>nums2[s2+j-1]){
				e1=s1+i-1;
				s2=s2+j;
				return findKth(nums1,s1,e1,nums2,s2,e2,k-j);
			}		
			else{
				s1=s1+i;
				e2=s2+j-1;
				return findKth(nums1,s1,e1,nums2,s2,e2,k-i);
			}
		}
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int m=nums1.size();
			int n=nums2.size();
			int k=m+n;
			if(k%2)
				return findKth(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,k/2+1);
			else
				//cout<< findKth(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,k/2)<<endl;
			 	//cout<< findKth(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,5)<<endl;
				return ((double) findKth(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,k/2)+ findKth(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,k/2+1))/2;

		}
};
int main(){
	vector<int> a = {1,2,5,6,7,8};
        vector<int> b = {3,4};
	Solution *sol=new Solution;
	//cout<<sol->findKth(a,0,a.size()-1,b,0,b.size()-1,4)<<endl;
	cout<<sol->findMedianSortedArrays(a,b)<<endl;
}
