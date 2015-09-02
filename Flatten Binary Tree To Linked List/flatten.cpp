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
		TreeNode *flat(TreeNode* root){
			if(!root)
				return NULL;
			if(!root->left and !root->right)
				return root;
			TreeNode *left_tail=flat(root->left);
			if(left_tail){
				left_tail->right=root->right;
				root->right=root->left;
				root->left=NULL;
			}
			TreeNode *right_tail=flat(root->right);
			return right_tail;
			
		}
		void flatten(TreeNode* root) {
			flat(root);
		}
};
int main(){
	TreeNode *root;
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);

	root=&n1;
	n1.left=&n2;
	n2.left=&n3;
	Solution *sol=new Solution;
	sol->flatten(root);
	while(root){
		cout<<root->val<<endl;
		root=root->right;
	}
}
