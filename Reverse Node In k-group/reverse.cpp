#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* reverse(ListNode *&in,ListNode* end){
			ListNode *out=end->next;
			ListNode *front=in;
			ListNode *cur=in->next;
			ListNode *next=cur->next;
			while(cur!=out){
				//cout<<cur->val<<endl;
				cur->next=front;
				front=cur;
				cur=next;
				if(cur)
					next=cur->next;

			}
			end=in->next;
			end->next=out;	
			in->next=front;
			return 	end;	
		}

		ListNode* reverseKGroup(ListNode* head, int k) {
			ListNode start(0);
			start.next=head;
			head=&start;
			ListNode *first,*end;
			first=head;
			end=head;
			ListNode *in=head;
			while(first){
				int i=0;
				for(;i<k;i++){					
					if(!end)
						break;
					end=end->next;
				}
				if(!end)
				{
					break;
				}
				else{
					//cout<<"in:"<<in->val<<" end:"<<end->val<<endl;
					ListNode *out=reverse(in,end);
					in=out;
					first=in;
					end=in;
					ListNode *scan;
					/*scan=head;
					while(scan)
					{
						cout<<scan->val<<" ";
						scan=scan->next;
					}
					cout<<endl;*/


				}
			}
			return head->next;
		}
};

int main(){
	ListNode *head;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	ListNode n6(6);
	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	n4.next=&n5;
	n5.next=&n6;
	head=&n1;

	ListNode *front=&n1;
	ListNode *end=&n3;
	Solution *sol=new Solution;
	head=sol->reverseKGroup(head,3);
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;


}
