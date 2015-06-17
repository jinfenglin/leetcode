#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* rotateRight(ListNode* head, int k) {
			ListNode *tail=head;
			int len;
			if(tail)
				len=1;
			else
				return NULL;
			while(tail->next)
			{
				tail=tail->next;
				len++;
			}			
			tail->next=head;
			for(int i=0;i<len-k%len-1;i++){				
				head=head->next;
			}
			ListNode *tmp=head;
			head=head->next;
			tmp->next=NULL;
			return head;

		}
};

int main(){
	Solution *sol=new Solution;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);

	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	n4.next=&n5;

	ListNode *head=sol->rotateRight(&n1,6);
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}
