public class Solution {
	public ListNode reverseBetween(ListNode head, int m, int n) {
		if(head==null)
			return null;
		ListNode extra=new ListNode(0);
		extra.next=head;
		ListNode headin=extra;
		for(int i=1;i<m;i++)
	    		headin=headin.next;
		ListNode rhead=reverse(headin.next,n-m+1);
		headin.next=rhead;
		return extra.next;		
	}
	public ListNode reverse(ListNode head,int step){
		ListNode pre=null,cur=head,next=cur.next;
		for(int i=0;i<step;i++){
			cur.next=pre;
			if(i==step-1)
			    break;
			pre=cur;
			cur=next;
			
			next=cur.next;
		}
		head.next=next;
		return cur;
	}
}
