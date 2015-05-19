#define NULL 0
#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
	    if(head==NULL)
		    return head;
	    ListNode *ptr=head->next;
	    head->next=NULL;
	    ListNode *back;
	    if(ptr)
		    back=ptr->next;
	    else
		    return head;
	   
	    while(back){
		    ptr->next=head;
		    head=ptr;
		    ptr=back;
		    back=back->next;   
	    }
	    ptr->next=head;
	    return ptr;
    }
};
int main(){
	Solution *sol=new Solution;
	ListNode *head=new ListNode(1);
	ListNode second(2);
	ListNode third(3);
	ListNode four(4);
	head->next=&second;
	second.next=&third;
	third.next=&four;
	head=sol->reverseList(NULL);
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;


}

