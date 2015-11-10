#include <iostream>
#include <unordered_map>
using namespace std;
class LRUCache{
	private:
		struct ListNode{
			int val,key;
			ListNode* next,*front;
			ListNode(int value,int key):key(key), val(value),next(NULL),front(NULL){}
		};
		int cap;
		int len;
		unordered_map<int,ListNode *> mp;
		ListNode* list;
		ListNode* end;
		void move2head(int key ){
			ListNode* node=mp[key];
			node->front->next=node->next;
			node->next->front=node->front;
			node->front=list;
			node->next=list->next;
			list->next->front=node;
			list->next=node;

		}
	public:
		void print(){
			ListNode *head=list;
			while(head){
				cout<<head->val<<" ";
				head=head->next;
			}
			cout<<endl;

		}
		void print(ListNode *head){
			while(head){
				cout<<head->val<<" ";
				head=head->next;
			}
			cout<<endl;

		}

		LRUCache(int capacity) {
			len=0;
			cap=capacity;
			list=new ListNode(0,-1);
			end= new ListNode(0,-2);
			list->next=end;
			end->front=list;
		}

		int get(int key) {
			if(mp.find(key)==mp.end())
				return -1;
			move2head(key);
			return (mp[key])->val;
		}

		void set(int key, int value) {
			ListNode *tmp=new ListNode(value,key);
			if(mp.find(key)!=mp.end()){
				move2head(key);
				mp[key]->val=value;
				return ;
			}else {
				mp[key]=tmp;
				len++;
				tmp->next=list->next;
				list->next->front=tmp;
				tmp->front=list;
				list->next=tmp;
				if(len>cap){
					mp.erase(end->front->key);
					len--;
					ListNode *pre_pre=end->front->front;
					end->front=pre_pre;
					pre_pre->next=end;

				}
				return;
			}
		}
};
int main(){
	LRUCache *sol=new LRUCache(1);
	sol->set(2,1);
	sol->print();
	cout<<sol->get(2)<<endl;
	sol->print();
	sol->set(3,2);
	sol->print();
	cout<<sol->get(2)<<endl;
	cout<<sol->get(3)<<endl;
}
