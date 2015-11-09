#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	public:
		bool static compare(ListNode *n1,ListNode *n2){
			return n1->val>n2->val;
		}
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			ListNode *res,*cur;
			priority_queue<ListNode *,vector<ListNode *>,function<bool(ListNode*,ListNode *)> > heap(compare);

			for(int i=0;i<lists.size();i++){
				ListNode *cur_node=lists[i];
				if(cur_node){
					heap.push(cur_node);
				}
			}
			if(!heap.size())
				return NULL;
			ListNode *top=heap.top();
			heap.pop();
			cur=res=top;
			if(cur->next)
				heap.push(cur->next);
			while(heap.size()){
				top=heap.top();
				heap.pop();
				if(top->next)
					heap.push(top->next);	
				cur->next=top;
				cur=cur->next;
						
			}
			return res;
		}
};
int main(){
	
	ListNode *head;
	ListNode n1(2),n2(5),n3(6);
	ListNode n4(1),n5(4),n6(7);
	head=&n1;
	n1.next=&n2;
	n2.next=&n3;

	n4.next=&n5;
	n5.next=&n6;
	vector<ListNode *> vec={head,&n4};
	Solution *sol=new Solution;
	head=sol->mergeKLists(vec);
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;

}

