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
		int depth(TreeNode *root){
			if(!root)
				return 0;
			return max(depth(root->left),depth(root->right))+1;
		}
		bool isBalanced(TreeNode* root) {
			if(!root)
				return true;
			
			if(isBalanced(root->left) and isBalanced(root->right)){
				return abs(depth(root->left)-depth(root->right))<=1;
			}
			return false;
		}
};
int main(){
	TreeNode *root=NULL;
	Solution *sol=new Solution;

	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	root=&n1;
	n1.right=&n2;
	n2.right=&n3;

	cout<<sol->isBalanced(root)<<endl;
}
