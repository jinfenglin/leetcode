#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* partition(ListNode* head, int x) {
			ListNode *small,*large;
			ListNode dum_small=ListNode(0);
			ListNode dum_large=ListNode(0);
			small=&dum_small;
			large=&dum_large;
			while(head){
				if(head->val<x){
					small->next=head;
					small=small->next;
				}else{
					large->next=head;
					large=large->next;
				}	
				head=head->next;
			}
			large->next=NULL;
			small->next=dum_large.next;
			return dum_small.next;
		}
};
int main(){
	ListNode n1=ListNode(1);
	ListNode n2=ListNode(4);
	ListNode n3=ListNode(3);
	ListNode n4=ListNode(2);
	ListNode n5=ListNode(5);
	ListNode n6=ListNode(2);
	ListNode *head=&n1;
	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	n4.next=&n5;
	n5.next=&n6;
	Solution *sol=new Solution;
	head=sol->partition(head,3);
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}
