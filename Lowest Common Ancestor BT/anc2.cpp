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
		bool find_path(TreeNode *root,TreeNode *target,string &sol){
			if(!root)
				return false;
			if(root==target)
				return true;
			if(find_path(root->left,target,sol+="1"))
				return true;
			sol.erase(sol.end()-1);
			if(find_path(root->right,target,sol+="0"))
				return true;
			sol.erase(sol.end()-1);
			return false;
		}
		TreeNode* find_node(TreeNode* root,const string &path,int loc){
			if(loc==path.size())
				return root;
			if(path[loc]=='1')
				return find_node(root->left,path,loc+1);
			else
				return find_node(root->right,path,loc+1);
			
		}
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			string s1="",s2="";
			find_path(root,p,s1);
			find_path(root,q,s2);
			int len=0;
			for(int i=0;i<min(s1.size(),s2.size());i++){
				if(s1[i]!=s2[i])
					break;
				len++;
			}
			return find_node(root,s1.substr(0,len),0);
		}
};
int main(){
	Solution *sol=new Solution;
	TreeNode n1(-1);
	TreeNode n2(0);
	TreeNode n3(3);
	TreeNode n4(-2);
	TreeNode n5(4);
	TreeNode n6(8);
	n1.left=&n2;
	n1.right=&n3;
	n2.left=&n4;
	n2.right=&n5;
	n4.left=&n6;

	TreeNode *root=&n1;
	TreeNode *p=&n6,*q=&n5;
	cout<<sol->lowestCommonAncestor(root,p,q)->val<<endl;
}
