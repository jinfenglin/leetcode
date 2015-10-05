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
		bool find(TreeNode *root,TreeNode *target){
			if(!root)
				return false;
			if(root==target)
				return true;
			return find(root->left,target) or find(root->right,target);
		}
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			bool p_left,p_right,q_left,q_right;
			p_left=find(root->left,p) or p==root;
			p_right=find(root->right,p) or p==root;

			q_left=find(root->left,q) or q==root;
			q_right=find(root->right,q) or q==root;


			if((p_left and q_right) or (p_right and q_left))
				return root;
			else if(p_left and q_left)
				return lowestCommonAncestor(root->left,p,q);
			else
				return lowestCommonAncestor(root->right,p,q);

		}
};
int main(){

}
