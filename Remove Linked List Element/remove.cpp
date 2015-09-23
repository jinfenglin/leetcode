#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	public:
		ListNode* removeElements(ListNode* head, int val) {
			ListNode *pre,*cur;
			pre=NULL;
			cur=head;
			while(cur!=NULL){
				if(cur->val==val){
					if(pre)
						pre->next=cur->next;
					else
						head=cur->next;
					cur=cur->next;
				}			
				else{
					pre=cur;
					cur=cur->next;
				}		

			}
			return head;
		}
};
int main(){
}
