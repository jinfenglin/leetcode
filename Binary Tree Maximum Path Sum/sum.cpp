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
		int GetVal(TreeNode *root,int &max_val){
			if(!root)
				return 0;
			int left=GetVal(root->left,max_val);
			int right=GetVal(root->right,max_val);
			int arch=left+right+root->val;

			int side=max(left+root->val,right+root->val);
			int res=max(root->val,side);
			max_val=max(arch,max(res,max_val));
			return res;
			
		}
		int maxPathSum(TreeNode* root) {
			if(!root)
				return 0;
			int max_val=root->val;
			GetVal(root,max_val);
			return max_val;
		}
};
int main(){
	TreeNode *root;
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	root=&n1;
	n1.left=&n2;
	n2.right=&n3;
	Solution *sol=new Solution;
	cout<<sol->maxPathSum(root)<<endl;
}
