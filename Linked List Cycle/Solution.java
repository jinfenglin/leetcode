class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}
public class Solution {
	public ListNode move(ListNode cur,int step){
		while(step>0){
			if(cur==null)
				return null;
			cur=cur.next;
			step--;
		}
		return cur;
	}
	public boolean hasCycle(ListNode head) {
		if(head==null)
			return false;
		ListNode fast,slow;
		fast=head;
		fast=move(fast,2);
		slow=head;
		slow=move(slow,1);
		if(slow==null)
			return false;
		while(fast!=slow){
			if(fast==null)
				return false;
			fast=move(fast,2);
			slow=move(slow,1);

		}
		return true;
		
	}
}
