#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:

		vector<vector<int>> levelOrder(TreeNode* root) {
			queue<TreeNode> cur_level,next_level;
			vector<vector<int>> res;
			if(!root)
				return res;
			cur_level.push(*root);
			while(!cur_level.empty() or !next_level.empty()){
				vector<int> tmp_res;
				while(!cur_level.empty()){
					TreeNode queue_head=cur_level.front();
					tmp_res.push_back(queue_head.val);
					if(queue_head.left)
						next_level.push(*queue_head.left);
					if(queue_head.right)
						next_level.push(*queue_head.right);

					cur_level.pop();
				}
				res.push_back(tmp_res);
				cur_level=next_level;
				next_level=queue<TreeNode>();
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
	auto res=sol->levelOrder(root);
	cout<<"finish"<<endl;
	for(auto x: res){
		for(int j:x)
			cout<<j<<" ";
		cout<<endl;
	}
}
