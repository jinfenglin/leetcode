#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			ListNode* f,s;
			f=head;
			s=head;
			int n=k-1;
			while(k and s){
				n--;
				s=s->next;
			}

			n=k-1;
			while(s){
				ListNode front=f;
				ListNode cur=f->next;
				if(cur)
					next=cur->next;
				if(f==head){
					//ListNode dumyNode(0);	
					f->next=s->next;
				}
					cur->next=f;
					f=cur;
					cur=next;
					next=next->next;
					
			}
		}
};

int main(){
}
