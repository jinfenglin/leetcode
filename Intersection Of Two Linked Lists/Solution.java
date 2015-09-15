class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}
public class Solution {
	public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
		ListNode t1,t2;
		t1=headA;
		t2=headB;
		int t1_len=0;
		int t2_len=0;
		while(t1!=null){
			t1=t1.next;
			t1_len++;
		}
		while(t2!=null){
			t2=t2.next;
			t2_len++;
		}
		int move=Math.abs(t1_len-t2_len);
		if(t1_len>t2_len){
			while(move>0){
				headA=headA.next;
				move--;
			}
			
		}else{
			while(move>0){
				headB=headB.next;
				move--;
			}
		}
		while(headA!=null & headB!=null){
			if(headA==headB){
				return headA;
			}
			headA=headA.next;
			headB=headB.next;
		}
		return null;
	}
}
