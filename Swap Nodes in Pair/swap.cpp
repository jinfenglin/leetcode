#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
	public:
		ListNode* swapPairs(ListNode* head) {
			if(head==NULL or head->next==NULL)
				return head;
			ListNode *f;
			ListNode *s;
			ListNode *in;
			f=head;
			s=f->next;
			head=s;
			f->next=s->next;
			s->next=f;
			in=f;
			f=f->next;
			if(f)
				s=f->next;
			while(f and s){
				in->next=s;
				f->next=s->next;
				s->next=f;
				in=f;
				f=f->next;
				if(f)
					s=f->next;
				else
					break;

			}
			return head;
		}
};
int main(){
	ListNode *head;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	//ListNode n6(6);

	n1.next=&n2;
	//n2.next=&n3;
	//n3.next=&n4;
	//n4.next=&n5;
	//n5.next=&n6;
	head=&n1;

	Solution *sol=new Solution;
	head=sol->swapPairs(head);
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;

}
