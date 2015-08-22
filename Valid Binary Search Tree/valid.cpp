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
		int valid(TreeNode *root,int &max,int &min){
			max=root->val;
			min=root->val;			
			int sub_max,sub_min;
			bool left_bool=false,right_bool=false;
			if(root->left and valid(root->left,sub_max,sub_min)){
				left_bool= root->val>sub_max;
				//cout<<"val:sub_max  "<<root->val<<" "<<sub_max<<endl;

				if(sub_max>max)
					max=sub_max;
				if(sub_min<min)
					min=sub_min;

			}else if(!root->left)
				left_bool=true;

			if(root->right and valid(root->right,sub_max,sub_min)){
				right_bool= root->val< sub_min;
				//cout<<"val:sub_min  "<<root->val<<" "<<sub_min<<endl;
				if(sub_max>max)
					max=sub_max;
				if(sub_min<min)
					min=sub_min;

			}else if(!root->right)
				right_bool=true;
			//cout<<"node:"<<root->val<<endl;
			//cout<<left_bool<<" "<<right_bool<<endl;
			return left_bool and right_bool;
		}
		bool isValidBST(TreeNode* root) {
			int max,min;
			if(!root)
				return true;
			return valid(root,max,min);

		}
};
int main(){
	Solution *sol=new Solution;
	TreeNode *root;
	TreeNode n1(3);
	TreeNode n2(30);
	TreeNode n3(10);
	TreeNode n4(15);
	TreeNode n5(45);
	root=&n1;
	n1.right=&n2;
	n2.left=&n3;
	n3.right=&n4;
	n4.right=&n5;
	cout<<sol->isValidBST(root)<<endl;
}
