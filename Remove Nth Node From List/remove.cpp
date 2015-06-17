#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode *fast=head;
			ListNode *cur=head;
			while(fast and n)
			{
				fast=fast->next;
				n--;
			}
			if(fast)
			{
				while(fast->next){
					cur=cur->next;
					fast=fast->next;
				}
				cur->next=(cur->next)->next;
			}else{
				head=head->next;
			}
			return head;
		}
};
int main(){
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);

	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	n4.next=&n5;

	Solution *sol=new Solution;
	ListNode *head=sol->removeNthFromEnd(&n1,1);
	while(head){
		cout<<head->val<<" ";
	     	head=head->next;	
	}
	cout<<endl;
}
