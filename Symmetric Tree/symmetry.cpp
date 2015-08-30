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
		bool symmetry(TreeNode *node1,TreeNode *node2){
			if(!node1 and !node2)
				return true;
			else if(node1 and node2 and node1->val==node2->val){
				return symmetry(node1->left,node2->right) and symmetry(node1->right,node2->left);
			}
			return false;
		}
		bool isSymmetric(TreeNode* root) {
			if(root)
				return symmetry(root->left,root->right);
			else
				return true;

		}
};
int main(){
}
