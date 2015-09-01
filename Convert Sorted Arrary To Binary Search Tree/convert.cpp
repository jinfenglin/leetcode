#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	public:
		void showTree(TreeNode *root);
		TreeNode* BuildTree(int start,int end,vector<int> &nums){
			int mid=(start+end)/2;
			TreeNode *new_node=new TreeNode(nums[mid]);

			if(start<mid)
				new_node->left=BuildTree(start,mid-1,nums);
			if(end>mid)
				new_node->right=BuildTree(mid+1,end,nums);
			return new_node;
		}
		TreeNode* sortedArrayToBST(vector<int>& nums) {
			if(nums.empty())
				return NULL;
			else
				return BuildTree(0,nums.size()-1,nums);
		}
};
void Solution::showTree(TreeNode *root){
	if(root){
		cout<<root->val<<endl;
		showTree(root->left);
		showTree(root->right);
	}
	

}
int main(){
	vector<int> init={1,2,3,4,5,6,7};
	Solution *sol=new Solution;
	//TreeNode *root=sol->sortedArrayToBST(init);
	//cout<<root->val<<endl;
	sol->showTree(sol->sortedArrayToBST(init));
}
