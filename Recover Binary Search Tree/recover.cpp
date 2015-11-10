class Solution {
	public:
		void Inorder(TreeNode *root,vector<TreeNode*> &vec){
			if(!root)
				return ;
			Inorder(root->left,vec);
			vec.push_back(root);
			Inorder(root->right,vec);
		}
		void recoverTree(TreeNode* root) {
			vector<TreeNode*> vec;
			Inorder(root,vec);
			if(vec.size()==2){
			    int tmp=vec[0]->val;
			    vec[0]->val=vec[1]->val;
			    vec[1]->val=tmp;
			    return;
			}
			TreeNode *t1,*t2;
			if(vec[0]>vec[1])
			    t1=vec[0];
			for(int i=1;i<vec.size();i++)
			    if(vec[i]->val>vec[i-1]->val)
			        continue;
			    else
			        t1=vec[i];
			 if(vec[vec.size()-1]->val<vec[vec.size()-2]->val)
			    t2=vec[vec.size()-1];
			 for(int i=vec.size()-2;i>=0;i--)
			    if(vec[i]->val<vec[i+1]->val)
			        continue;
			    else
			        t2=vec[i];
			 int tmp=t1->val;
			 t1->val=t2->val;
			 t2->val=tmp;
			
		}
};

