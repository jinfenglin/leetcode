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
		bool hasPathSum(TreeNode* root, int sum) {
			if(!root)
				return false;

			if(root->left and hasPathSum(root->left,sum-root->val))
				return true;
			if(root->right and hasPathSum(root->right,sum-root->val))
				return true;
			if(!root->left and !root->right)
				return sum==root->val;
			return false;
		}
};
int main(){
}
