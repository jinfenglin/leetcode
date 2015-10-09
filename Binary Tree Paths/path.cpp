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
		string make_string(vector<string> &sol){
			string res="";
			if(sol.size()){
				for(string s:sol)
					res+=s+"->";
				res.erase(res.end()-2,res.end());
			}
			return res;

		}
		void DFS(vector<string> &sol,vector<string> &res,TreeNode* root){

			sol.push_back(to_string(root->val));
			if(!root->left and !root->right)
				res.push_back(make_string(sol));
			if(root->left)
				DFS(sol,res,root->left);
			if(root->right)
				DFS(sol,res,root->right);
			sol.erase(sol.end()-1,sol.end());
		}
		vector<string> binaryTreePaths(TreeNode* root) {
			vector<string> sol,res;
			if(root)
				DFS(sol,res,root);
			return res;

		}
};
int main(){
	Solution *sol=new Solution;
	sol->binaryTreePaths(NULL);
}
