#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	public:
		void mypop(deque<TreeNode> &queue,bool direction){
			if(direction)
				queue.pop_front();
			else
				queue.pop_back();
		}
		TreeNode access(deque<TreeNode> queue,bool direction){
			if(direction)
				return queue.front();
			else
				return queue.back();
		}
		vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
			deque<TreeNode> cur,next;
			vector<vector<int>> res;
			if(!root)
				return res;
			cur.push_back(*root);
			bool direction=true;
			while(!cur.empty() or !next.empty()){
				vector<int> tmp;
				next=deque<TreeNode>();
				for(TreeNode node:cur){
					if(node.left)
						next.push_back(*node.left);
					if(node.right)
						next.push_back(*node.right);
				}
				while(!cur.empty()){
					TreeNode head= access(cur,direction);
					tmp.push_back(head.val);
					mypop(cur,direction);
				}
				direction=!direction;
				cur=next;
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
	auto res=sol->zigzagLevelOrder(root);
	cout<<"finish"<<endl;
	for(auto x: res){
		for(int j:x)
			cout<<j<<" ";
		cout<<endl;
	}}
