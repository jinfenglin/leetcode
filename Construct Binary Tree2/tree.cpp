#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int BuildTree(unordered_map<int,int> &inorder,int start,int end,vector<int>&postorder,int index,TreeNode * &cur_node ){
		//cout<<"cur_val:"<<postorder[index]<<endl;
		cur_node=new TreeNode(0);
		cur_node->val=postorder[index];
		int mid=inorder[cur_node->val];
		//cout<<"mid:"<<mid<<endl;
		if(mid+1<=end)
			index=BuildTree(inorder,mid+1,end,postorder,--index,cur_node->right);

		if(start<=mid-1)
			index=BuildTree(inorder,start,mid-1,postorder,--index,cur_node->left);
		
		return index;

	}
    	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if(postorder.size()==0)
			return NULL;
		unordered_map<int,int> mp;
		TreeNode *root;
		for(int i=0;i<inorder.size();i++)
			mp[inorder[i]]=i;
		BuildTree(mp,0,inorder.size()-1,postorder,postorder.size()-1,root);
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
	vector<int> post={3,4,1,5,2,0};
	vector<int> in={3,1,4,0,5,2};

	Solution *sol=new Solution;
	TreeNode *root=sol->buildTree(in,post);
	print_tree(root);
	cout<<endl;


}
