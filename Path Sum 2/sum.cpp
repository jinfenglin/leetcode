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
		vector<vector<int>> pathSum(TreeNode* root, int sum) {
			vector<vector<int>> res;
			if(!root)
				return res;
			if(!root->left and !root->right){
				if(root->val==sum){
					vector<int> tmp={root->val};
					res.push_back(tmp);
				}
				return res;
			}
			if(root->left){
				vector<vector<int>> tmp=pathSum(root->left,sum-root->val);
				for(vector<int> vec:tmp){
					vec.insert(vec.begin(),root->val);
					res.push_back(vec);
				}
			}
			if(root->right){
				vector<vector<int>> tmp=pathSum(root->right,sum-root->val);
				for(vector<int> vec:tmp){
					vec.insert(vec.begin(),root->val);
					res.push_back(vec);
				}
			}
			return res;
		}
};
int main(){
}
