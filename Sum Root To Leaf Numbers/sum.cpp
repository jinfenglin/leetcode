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
		int sum_val;
		void sum(TreeNode* root, int num){
			int cur_num=num*10+root->val;			
			if(!root->left and !root->right){	
				sum_val+=cur_num;
				return;
			}

			if(root->left)
				sum(root->left,cur_num);
			if(root->right)
				sum(root->right,cur_num);


		}
		int sumNumbers(TreeNode* root) {
			if(!root)
				return 0;
			sum_val=0;
			sum(root,0);
			return sum_val;
			
		}
};
int main(){
	TreeNode *root;
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	root=&n1;
	n1.left=&n2;
	n1.right=&n3;
	Solution *sol=new Solution;
	cout<<sol->sumNumbers(root)<<endl;
}
