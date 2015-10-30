#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
	public:

		// Encodes a tree to a single string.
		string serialize(TreeNode* root) {
			if(root==NULL)
				return "";
			queue<TreeNode *> qt;
			qt.push(root);
			string res;
			res+=to_string(root->val);
			while(!qt.empty()){
				TreeNode * head= qt.front();
				qt.pop();
				if(head->left){
					qt.push(head->left);
					res+=","+to_string(head->left->val);	
				}
				else
					res+=",NULL";

				if(head->right){
					qt.push(head->right);
					res+=","+to_string(head->right->val);
				}
				else
					res+=",NULL";				
			}
			return res;
		}

		// Decodes your encoded data to tree.
		TreeNode* deserialize(string data) {
			istringstream ss(data);
			string token;
			vector<TreeNode*> vec;			
			while(getline(ss,token,','))
				if(token=="NULL")
					vec.push_back(NULL);
				else{
					TreeNode *new_node=new TreeNode(stoi(token));
					vec.push_back(new_node);
				}
			int parent=0,child=1;
			while(parent<vec.size()){
				if(vec[parent]){
					if(child<vec.size())
						vec[parent]->left=vec[child++];
					if(child<vec.size())
						vec[parent]->right=vec[child++];
				}	
				parent++;
			}
			if (vec.size()==0)
				return NULL;
			else
				return vec[0];
		}
};
int main(){
	Solution *sol=new Code;
	TreeNode *root=sol->deserialize("");
	cout<<"deserialized"<<endl;
	string str=sol->serialize(root);
	cout<<"serialize"<<str<<endl;
	cout<<sol->deserialize(str)<<endl;
	
}
