/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		int acc=0;
		ListNode res=null,head=null;
		while(l1!=null && l2!=null){
			int tmp=l1.val+l2.val+acc;
			acc=tmp/10;
			int val=tmp%10;
			l1=l1.next;
			l2=l2.next;

			if(res==null){
				res=new ListNode(val);
				head=res;
			}
			else{
				res.next=new ListNode(val);
				res=res.next;
			}
		}
		ListNode unprocessed;
		if(l1!=null){
			unprocessed=l1;
		}else{
			unprocessed=l2;
		}
		res.next=unprocessed;

		while(acc!=0){
			if(unprocessed==null){
				res.next=new ListNode(1);
				acc=0;
			}else{
				int tmp=unprocessed.val+acc;
				acc=tmp/10;
				tmp=tmp%10;
				unprocessed.val=tmp;
				unprocessed=unprocessed.next;
				res=res.next;
			}
		}
		return head;
	}

}
