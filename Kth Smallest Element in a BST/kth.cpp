#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		int BST(TreeNode *root,int k,int &ans){
			if(!root)
				return 0;
			int left_num=BST(root->left,k,ans);
			if(left_num==k-1)
				ans=root->val;
			int right_num=BST(root->right,k-left_num-1,ans);
			return left_num+right_num+1;

		}
		int kthSmallest(TreeNode* root, int k) {
			int ans=0;
			BST(root,k,ans);
			return ans;
		}
};
int main(){
}
