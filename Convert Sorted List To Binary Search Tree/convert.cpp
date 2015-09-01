#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	public:
		TreeNode* Build(ListNode* &list,int start,int end){
			if(start>end)
				return NULL;
			int mid=(start+end)/2;
			TreeNode *left=Build(list,start,mid-1);
			TreeNode *new_node=new TreeNode(list->val);
			list=list->next;
			new_node->left=left;
			new_node->right=Build(list,mid+1,end);

			return new_node;
		}
		TreeNode* sortedListToBST(ListNode* head) {
			ListNode *ptr=head;
			int count=0;
			while(ptr){
				count++;
				ptr=ptr->next;
			}
			return Build(head,0,count-1);

		}
};

int main(){

}
