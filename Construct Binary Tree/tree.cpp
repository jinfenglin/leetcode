#include <iostream>
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
	int BuildTree(vector<int> &preorder,int root_index,vector<int> &inorder,int start,int end,TreeNode* &cur_node){
		cur_node= new TreeNode(0);				
		cur_node->val=preorder[root_index];
		//cout<<"root_index:"<<root_index<<endl;
		//cout<<"cur_val:"<<cur_node->val<<endl;

		vector<int>::iterator it=find(inorder.begin(),inorder.end(),cur_node->val);
		int mid=it-inorder.begin();
		//vector<int> left(partial_inorder.begin(),it);
		//vector<int> right(it+1,partial_inorder.end());
		//cout<<"left size:"<<left.size()<<" right size:"<<right.size()<<endl;
		if(start<=mid-1)
			root_index=BuildTree(preorder,++root_index,inorder,start,mid-1,cur_node->left);
		if(end>=mid+1)
			root_index=BuildTree(preorder,++root_index,inorder,mid+1,end,cur_node->right);
		return root_index;
	}
    	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(preorder.size()==0 or inorder.size()==0)
			return NULL;
		TreeNode *root;
		BuildTree(preorder,0,inorder,0,inorder.size()-1,root);		
		return root;
    	}
};

void print_tree(TreeNode *root){
	if(root!=NULL)
		cout<<root->val<<" ";
	else
		return;
	if(root->left!=NULL)
		print_tree(root->left);
	if(root->right!=NULL)
		print_tree(root->right);
}

int main(){
	TreeNode n0(0);
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(0);
	TreeNode n7(0);
	n0.left=&n1;
	n0.right=&n2;
	n1.left=&n3;
	n1.right=&n4;
	n2.left=&n5;
	//vector<int> pre={0,1,3,4,2,5};
	//vector<int> in={3,1,4,0,5,2};
	vector<int> pre={1,2};
	vector<int> in={2,1};
	Solution *sol=new Solution;
	TreeNode *root=sol->buildTree(pre,in);
	print_tree(root);
	cout<<endl;
}
