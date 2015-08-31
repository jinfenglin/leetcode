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
		void probe(TreeNode *head,int depth,int &max){
			if(!head)
				return;
			if(max<depth)
				max=depth;
			if(head->left)
				probe(head->left,depth+1,max);
			if(head->right)
				probe(head->right,depth+1,max);
		}
		int maxDepth(TreeNode* root) {
			int max=0;
			probe(root,1,max);
			return max;
			
		}
};
int main(){
}
