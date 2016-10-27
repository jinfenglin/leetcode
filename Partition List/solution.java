public class Solution {
	public ListNode partition(ListNode head, int x) {
		ListNode small,large,sCur,lCur;
		small=new ListNode(0);
		large=new ListNode(0);
		sCur=small;
		lCur=large;
		int count=0;
		while(head!=null){
			if(head.val<x){
				sCur.next=head;
				sCur=sCur.next;
				sCur.next=null;
			}else if(head.val>x){
				lCur.next=head;
				lCur=lCur.next;
				lCur.next=null;
			}else{
				count++;
			}
			head=head.next;
		}
		ListNode equals=new ListNode(0);
		ListNode eCur=head;
		for(int i=0;i<count;i++){
			eCur.next=new ListNode(x);
			eCur=eCur.next;
		}
		sCur.next=equals.next;
		eCur.next=large.next;
		return small.next;
	}
}
