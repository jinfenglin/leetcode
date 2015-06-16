#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode *ans=l1;
			int extra=0;
			while(l1 and l2){
				int val=l1->val+l2->val+extra;
				extra=0;
				if(val>=10)
				{
					val-=10;
					extra=1;
				}
				l1->val=val;
				if(l1->next==NULL or l2->next==NULL)
					break;
				l1=l1->next;
				l2=l2->next;
			}
			if(l1->next){
				while(l1->next){
					l1=l1->next;
					int val=l1->val+extra;
					if(val>=10)
					{
						val-=10;
						extra=1;
					}else
						extra=0;
					l1->val=val;
					if(l1->next==NULL and extra==1)
					{
						ListNode *new_node=new ListNode(1);
						l1->next=new_node;	
						break;
					}
					
				}
			}
			else if(l2->next){
				l1->next=l2->next;
				while(l2->next){
					l2=l2->next;
					int val=l2->val+extra;
					if(val>=10){
						val-=10;
						extra=1;
					}else{
						extra=0;
					}
					l2->val=val;
					if(l2->next==NULL and extra==1)
					{
						ListNode *new_node=new ListNode(1);
						l2->next=new_node;
						break;
					}
				}
			}else{
				if(extra==1){
					ListNode *new_node=new ListNode(1);
					l1->next=new_node;	
				}
			}
			return ans;
		}
};
int main(){
	ListNode n1(0);
	ListNode n2(0);
	ListNode n3(9);
	ListNode n31(9);
	ListNode n4(7);
	ListNode n5(3);
	ListNode n6(1);

	//n1.next=&n2;
	//n2.next=&n3;
	//n3.next=&n31;

	n4.next=&n5;
	//n5.next=&n6;

	Solution *sol=new Solution;
	ListNode* head=sol->addTwoNumbers(&n1,&n4);
	while(head)
	{
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}
