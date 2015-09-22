#include <iostream>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
	public:
		void linkCase(TreeLinkNode *p,TreeLinkNode *next){
			if(!next){
				p->next=NULL;
				return;
			}
			if(next->left)
				p->next=next->left;
			else if(next->right)
				p->next=next->right;
			else{
				linkCase(p,next->next);
			}
		}
		void connect(TreeLinkNode *root) {
			if(!root)
				return ;
			//cout<<root->val<<endl;
			if(root->left and root->right){
				root->left->next=root->right;
				linkCase(root->right,root->next);
			}else if(root->left and !root->right){
				linkCase(root->left,root->next);
			}else if(!root->left and root->right){
				linkCase(root->right,root->next);
			}
				
			connect(root->right);
			connect(root->left);
			
		}
};
int main(){
	Solution *sol=new Solution;
	TreeLinkNode *root;
	TreeLinkNode n1(1);
	TreeLinkNode n2(2);
	TreeLinkNode n3(3);
	TreeLinkNode n4(4);
	TreeLinkNode n5(5);
	n1.left=&n2;
	n1.right=&n3;
	n2.left=&n4;
	n2.right=&n5;
	root=&n1;
	sol->connect(root);
}
