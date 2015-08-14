#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* deleteDuplicates(ListNode* head) {
			if(!head)
				return head;
			ListNode *cur=head;
			ListNode *next_node=cur->next;
			while(cur and next_node){
				if(cur->val==next_node->val){
					cur->next=next_node->next;
					next_node=next_node->next;
					continue;
				}
				cur=next_node;
			}
			return head;
		}
};

int main(){
	ListNode n1=ListNode(1);
	ListNode n2=ListNode(1);
	ListNode n3=ListNode(1);
	ListNode n4=ListNode(1);
	ListNode n5=ListNode(1);
	ListNode *head=&n1;
	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	n4.next=&n5;
	Solution *sol=new Solution;
	head=sol->deleteDuplicates(head);
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;


}
