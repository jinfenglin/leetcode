public class Solution {
	public ListNode sortList(ListNode head) {
		if(head==null)
			return null;
		ListNode slow,fast;
		slow=head;
		fast=head;
		while(fast!=null){
			fast=fast.next;
			if(fast==null)
				break;
			slow=slow.next;
			fast=fast.next;
		}
		ListNode second=slow.next;
		slow.next=null;
		ListNode fList=sortList(head);
		ListNode sList=sortList(second);
		return merge(fList,sList);
		 
		
	}
	public ListNode merge(ListNode first,ListNode second){
		if(first==null)
			return second;
		if(second==null)
			return first;
		ListNode head=new ListNode(0);
		ListNode cur=head;
		while(first!=null && second!=null){
			if(first.val>second.val){
				cur.next=first;
				cur=cur.next;
				first=first.next;
			}else{
				cur.next=second;
				cur=cur.next;
				second=second.next;
			}
		}
		if(first==null)
			cur.next=second;
		else
			cur.next=first;
		return head.next;
	}
	
}
