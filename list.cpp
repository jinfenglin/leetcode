#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			ListNode * cur=head;
			ListNode * ahead=NULL;
			for(int i=0;i<m;i++){
				cur=cur->next;
				if(i==m-2)
					ahead=cur;
			}
			//cout<<cur->val<<endl;
			//cout<<ahead->val<<endl;
			ListNode *partial=cur;
			
			ListNode *next=NULL;
			ListNode *before=NULL;	
			for(int i=m;i<=n;i++){
				
				next=cur->next;
				cur->next=before;
				before=cur;
				cur=next;
			}
			ahead->next=cur;
			partial->next=next;
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
	ListNode *head=&n1;
	Solution *sol=new Solution;
	head=sol->reverseBetween(head,2,4);
	//while(head!=NULL){
	//	cout<<head->val<<" ";
	//}
	cout<<endl;
}
