#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	public:
		void reverse(ListNode* &head){
			if(!head)
				return ;
			ListNode *pre=NULL,*cur=head;
			while(cur){
				ListNode *tmp=cur->next;
				cur->next=pre;
				pre=cur;
				if(tmp)
					cur=tmp;
				else
					break;
			}
			head=cur;
		}
		bool isPalindrome(ListNode* head) {
			ListNode *fast,*slow;
			fast=slow=head;
			while(fast){
				slow=slow->next;
				fast=fast->next;
				if(fast)
					fast=fast->next;
			}
			reverse(slow);
			while(slow){
				if(head->val!=slow->val)
					return false;
				head=head->next;
				slow=slow->next;
			}
			return true;
		}
};
int main(){
	Solution *sol=new Solution;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(2);
	ListNode n5(1);

	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	n4.next=&n5;
	cout<<sol->isPalindrome(&n1)<<endl;
}
