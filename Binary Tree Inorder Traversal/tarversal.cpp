#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	public:
		vector<int> inorderTraversal(TreeNode* root) {
			vector<int> res;
			if(!root)
				return res;
			stack<TreeNode> tree_stk;
			tree_stk.push(*root);
			while(!tree_stk.empty()){
				TreeNode  &top=tree_stk.top();
				cout<<"top:"<<top.val<<endl;
				if(top.left==NULL){
					res.push_back(top.val);
					tree_stk.pop();
					if(top.right)
						tree_stk.push(*top.right);
				}
				else{
					tree_stk.push(*top.left);
					top.left=NULL;
				}
			}
			return res;

		}
};
int main(){
	TreeNode root(1);
	TreeNode l1(2);
	TreeNode r2(3);
	root.right=&l1;
	l1.left=&r2;
	Solution *sol=new Solution;
	auto res=sol-> inorderTraversal(NULL);
	for(int i:res)
		cout<<i<<" ";
	cout<<endl;
}
