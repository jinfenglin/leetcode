#include <iostream>
#include <vector>
using namespace std;
class SegmentTreeNode{
	public:
		int start,end,sum;
		SegmentTreeNode *left,*right;
		bool IsInRange(int loc){
			if(loc<=end and loc>=start)
				return true;
			return false;
		}
		SegmentTreeNode(int start,int end,int sum){
			this->start=start;
			this->end=end;
			this->sum=sum;
			left=NULL;
			right=NULL;
		}
};
class NumArray {
	public:
		SegmentTreeNode *root;
		vector<int> nums;
		SegmentTreeNode *BuildTree(vector<int> &nums,int start,int end){
			int mid=start+(end-start)/2;
			if(start==end){
				int sum=nums[start];
				return new SegmentTreeNode(start,end,sum);
			}
			SegmentTreeNode *left=BuildTree(nums,start,mid);
			SegmentTreeNode *right=BuildTree(nums,mid+1,end);
			SegmentTreeNode *root= new SegmentTreeNode(start,end,left->sum+right->sum);
			root->left=left;
			root->right=right;
			return root;
		}
		NumArray(vector<int> &nums) {
			if(nums.size()>0)
				root= BuildTree(nums,0,nums.size());
			this->nums=nums;
		}
		void UpdateTree(int i,int val,SegmentTreeNode *node){
			int delt=nums[i]-val;
			if(node and node->IsInRange(i)){
				node->sum-=delt;
				UpdateTree(i,val,node->left);
				UpdateTree(i,val,node->right);
			}	
		}
		void update(int i, int val) {
			if(nums.size()==0)
				return ;
			UpdateTree(i,val,root);
			nums[i]=val;
		}
		int QueryTree(int i,int j,SegmentTreeNode *node){
			if(node->start>=i and node->end<=j)
			       return node->sum;
			else if (node->end<i or node->start>j)
				return 0;
			else
				return QueryTree(i,j,node->left)+QueryTree(i,j,node->right);

		}
		int sumRange(int i, int j) {
			if(nums.size()==0)
				return 0;
			return QueryTree(i,j,root);
		}
};
int main(){
	vector<int> nums={7,2,7,2,0};
	NumArray *na=new NumArray(nums);
	na->update(4,6);
	na->update(0,2);
	na->update(0,9);
	cout<<na->sumRange(4,4)<<endl;
	na->update(3,8);
	cout<<na->sumRange(0,4)<<endl;
	na->update(4,1);
	cout<<na->sumRange(0,3)<<endl;
	cout<<na->sumRange(0,4)<<endl;
	na->update(0,4);
	cout<<na->sumRange(0,1)<<endl;
	
}
