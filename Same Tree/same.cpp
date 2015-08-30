#include <iostream>
using namespace std;
struct TreeNode{
	TreeNode *left,*right;
	int val;
	TreeNode(int x):val(x),left(NULL),right(NULL){
	}
};
class Solution{
	public: 
		bool isSameTree(TreeNode *root1,TreeNode *root2){
			if(root1 and root2){
				bool left_bool,right_bool,val_bool;
				if(root1->val==root2->val)
				{
					left_bool=isSameTree(root1->left,root2->left);
					right_bool=isSameTree(root1->right,root2->right);
					return left_bool and right_bool;
				}else
					return false;
			}
			else if(!root1 and !root2)
				return true;
			else
				return false;
		}
};
int main(){
	TreeNode *root1,*root2;
	TreeNode n1(1),s1(1);
	TreeNode n2(2),s2(2);
	TreeNode n3(3),s3(3);
	TreeNode n4(4),s4(4);
	TreeNode n5(6),s5(6);

	root1=&n1;
	root2=&s1;
	
	n1.left=&n2;
	s1.left=&s2;

	Solution *sol=new Solution;
	cout<<sol->isSameTree(root1,root2)<<endl;

}
