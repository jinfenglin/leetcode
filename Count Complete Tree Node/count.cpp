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
		int countNodes(TreeNode* root) {
			if(!root)
				return 0;
			int left=0,right=0;
			TreeNode *cur=root;
			while(cur->left){
				cur=cur->left;
				left++;
			}
			cur=root;
			while(cur->right){
				cur=cur->right;
				right++;
			}
			if(left==right)
				return pow(2,left);
			else
				return countNodes(root->left)+countNodes(root->right);
		}
};
int main(){
}
