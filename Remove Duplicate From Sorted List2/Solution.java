public class Solution {
	public ListNode deleteDuplicates(ListNode head) {
		ListNode pre=new ListNode(0);
		pre.next=head;
		ListNode cur=head;
		head=pre;
		while(cur!=null){
			if(cur.next!=null && cur.val==cur.next.val){
				while(cur.next!=null && cur.val==cur.next.val){
					cur=cur.next;
				}
				pre.next=cur.next;
				cur=pre.next;
			}else{
				pre=cur;
				cur=cur.next;
			}
		}
		return head.next;

	}
}
