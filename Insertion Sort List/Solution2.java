public class Solution {
	public ListNode insertionSortList(ListNode head) {
		ListNode res= new ListNode(0);
		ListNode cur=head;
		while(cur!=null){
		    ListNode pre=cur;
		    cur=cur.next;
			insert(res,pre);
		}
		return res.next;
		
	}
	public void insert(ListNode head,ListNode target){
		ListNode cur=head;
		while(cur.next!=null && cur.next.val<=target.val){
			cur=cur.next;
		}
		target.next=cur.next;
		cur.next=target;
	}
}
