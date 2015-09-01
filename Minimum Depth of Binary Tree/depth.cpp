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
    int minDepth(TreeNode* root) { 
	    queue<TreeNode> cur,next;
	    if(!root)
		    return 0;
	    cur.push(*root);
	    int res=0;
	    while(!cur.empty() or !next.empty()){
		    while(!cur.empty()){
			    TreeNode node=cur.front();
			    if(node.left)
				    next.push(*node.left);
			    if(node.right)
				    next.push(*node.right);
			    if(!node.left and !node.right)
				    return res+1;
			    cur.pop();
		    }
		    cur=next;
		    next=queue<TreeNode>();
		    res++;
	    }
	    return res;
    }
};
int main(){

}
