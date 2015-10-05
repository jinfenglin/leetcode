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
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if(!root)
				return NULL;
			if((p->val>=root->val and q->val<=root->val) or (p->val<=root->val and q->val>=root->val))
				return root;
			else if(p->val<root->val and q->val<root->val)
				return lowestCommonAncestor(root->left,p,q);
			else
				return lowestCommonAncestor(roo->right,p,q);
		}
};
int main(){
}
