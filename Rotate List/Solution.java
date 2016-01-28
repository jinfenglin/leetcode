public class Solution {
	public ListNode rotateRight(ListNode head, int k) {
		ListNode cursor=head;
		int len=0;
		if(head==null)
			return head;
		while(cursor.next!=null){
			len++;
			cursor=cursor.next;
		}
		len++;
		k=k%len;
		cursor.next=head;
		for(int i=0;i<len-k;i++){
		    cursor=cursor.next;
			head=head.next;
		}
		cursor.next=null;
		return head;
	}

}
