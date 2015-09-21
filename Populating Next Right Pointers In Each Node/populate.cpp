#include <iostream>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
	public:
		void connect(TreeLinkNode *root) {
			if(!root)
				return ;
			if(root->left){
				root->left->next=root->right;
				connect(root->left);
			}
			if(root->next and root->right){
				root->right->next=root->next->left;
			}
			if(root->right)
				connect(root->right);
		}
};
int main(){
}
