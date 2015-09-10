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
		while(step>0 & cur!=null){
			cur=cur.next;
			step--;
		}
		return cur;
	}
	public ListNode detectCycle(ListNode head) {
		ListNode fast,slow;
		fast=head;
		slow=head;
		slow=move(slow,1);
		fast=move(fast,2);
		if(slow==null || fast==null)
			return null;
		while(slow!=fast){
			if(fast==null)
				return null;
			slow=move(slow,1);
			fast=move(fast,2);
		}
		System.out.println(fast.val);
		while(head!=fast){
			head=move(head,1);
			fast=move(fast,1);
		}
		return head;
	}
	
}
