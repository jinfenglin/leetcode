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
		vector<TreeNode *> recursive(int begin,int end){
			//cout<<begin<<" "<<end<<endl;
			vector<TreeNode*> res;
			if(begin>end){
				res.push_back(NULL);
				return res;
			}
			else if(begin==end){
				TreeNode *node=new TreeNode(begin);
				res.push_back(node);
				return res;
			}
			for(int i=begin;i<=end;i++){
				vector<TreeNode*> left=recursive(begin,i-1);
				vector<TreeNode*> right=recursive(i+1,end);

				//cout<<"left:"<<left.size()<<endl;
				//cout<<"right:"<<right.size()<<endl;
				for(TreeNode* l:left)
					for(TreeNode* r:right)
					{
						TreeNode* root=new TreeNode(i);
						root->left=l;
						root->right=r;
						res.push_back(root);
					}
				//cout<<"res_size:"<<res.size()<<endl;
			}
			return res;
		}
		vector<TreeNode*> generateTrees(int n) {
			return recursive(1,n);
		}
};
int main(){
	Solution *sol=new Solution;
	auto res=sol->generateTrees(0);
	cout<<res.size()<<endl;
	//for(TreeNode * root:res)
	//	cout<<root->val<<endl;
}
