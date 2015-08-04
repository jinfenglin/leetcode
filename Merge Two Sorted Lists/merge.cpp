#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			ListNode head=ListNode(0);
			ListNode *cur=&head;
			//cur=&head;

			while(l1 and l2){
				if(l1->val<l2->val)
				{
					cur->next=l1;
					l1=l1->next;
				}
				else{
					cur->next=l2;
					l2=l2->next;
				}
				cur=cur->next;
			}
			if(l1)
				cur->next=l1;
			if(l2)
				cur->next=l2;
			return head.next;

		}
};
int main(){
	Solution *sol=new Solution;
	ListNode *l1;
	ListNode *l2;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	ListNode n6(6);
	//n1.val=1;
	//n2.val=2;
	//n3.val=3;
	//n4.val=4;
	//n5.val=5;
	l1=&n1;
	l2=&n2;
	l1->next=&n3;
	l2->next=&n4;
	n3.next=&n5;
	ListNode *head=sol->mergeTwoLists(l1,l2);
	while(head)
	{
		cout<<head->val<<endl;
		head=head->next;
	}
}
