class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}
public class Solution2 {
	ListNode findMid(ListNode head){
		if(head==null)
			return null;
		ListNode slow,fast;
		slow=head;
		fast=head.next;
		while(fast!=null){
			fast=fast.next;
			slow=slow.next;
			if(fast==null)
				break;
			fast=fast.next;
		}
		return slow;
	}
	ListNode reverseList(ListNode head){
		if(head==null)
			return null;
		ListNode pre=null,cur=head,next=head.next;
		while(next!=null){
			cur.next=pre;
			pre=cur;
			cur=next;
			next=next.next;
		}
		return cur;
	}
	ListNode interleave(ListNode h1,ListNode h2){
		ListNode res=new ListNode(0),tmp=res;
		while(h2!=null){
			tmp.next=h1;
			tmp=tmp.next;
			h1=h1.next;
			tmp.next=h2;
			tmp=tmp.next;
			h2=h2.next;
		}
		tmp.next=h1;
		return res.next;
	}
	public void reorderList(ListNode head) {
		if(head==null)
			return ;
		ListNode midNode=findMid(head);
		ListNode reversedHalf=reverseList(midNode.next);
		midNode.next=null;
		head=interleave(head,reversedHalf);
	}
	public static void main(String[] args){
		Solution2 sol=new Solution2();
		ListNode head=new ListNode(1);
		head.next=new ListNode(2);
		head.next.next=new ListNode(3);
		sol.reorderList(head);
		while(head!=null)
		{	System.out.println(head.val);
			head=head.next;
		}


	}
}
