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
			ListNode dum(0);
			dum.next=head;
			head=&dum;
			ListNode *front=head;
			ListNode *cur=head->next;
			ListNode *next=cur->next;
			while(next){
				bool flag=false;
				while(cur->val==next->val){ 
					cur=cur->next;
					next=next->next;
					flag=true;
					if(!next)
						break;					
				}
				if(flag)
					front->next=next;				
				else
					front=front->next;
				cur=next;
				if(next)
					next=next->next;
			}
			return head->next;
		}
};

int main(){
	ListNode n1=ListNode(1);
	ListNode n2=ListNode(1);
	ListNode n3=ListNode(2);
	ListNode n4=ListNode(2);
	ListNode n5=ListNode(3);
	ListNode *head=&n1;
	n1.next=&n2;
	//n2.next=&n3;
	//n3.next=&n4;
	//n4.next=&n5;
	Solution *sol=new Solution;
	head=sol->deleteDuplicates(head);
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}
