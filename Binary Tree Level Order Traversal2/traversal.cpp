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
		vector<vector<int>> levelOrderBottom(TreeNode* root) {
			vector<vector<int>> res;
			if(!root)
				return res;
			stack<vector<TreeNode>> stk;
			vector<TreeNode> cur,next;
			cur.push_back(*root);
			while(!cur.empty() or !next.empty()){
				for(TreeNode node:cur){
					if(node.left)
						next.push_back(*node.left);
					if(node.right)
						next.push_back(*node.right);
				}
				stk.push(cur);
				cur=next;
				next=vector<TreeNode>();
			}

			while(!stk.empty()){
				vector<TreeNode> top=stk.top();
				stk.pop();
				vector<int> tmp;
				for(TreeNode node:top)
					tmp.push_back(node.val);
						res.push_back(tmp);
			}
			return res;
		}
};
int main(){
	TreeNode *root;
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);

	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	TreeNode n7(7);
	TreeNode n8(8);

	n1.left=&n2;
	n1.right=&n3;
	n2.left=&n4;
	n2.right=&n5;
	n3.left=&n6;
	n3.right=&n7;
	root=&n1;


	Solution *sol=new Solution;
	auto res=sol->levelOrderBottom(root);
	for(auto x: res){
		for(int j:x)
			cout<<j<<" ";
		cout<<endl;
	}
}
