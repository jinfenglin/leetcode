
class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}
public class Solution {
	public ListNode move(ListNode cur,int step){
		while(cur!=null & step>0){
			cur=cur.next;
			step--;
		}
		return cur;
	}
	public ListNode reverse(ListNode head){
		if(head==null)
			return null;
		ListNode cur=head.next;
		head.next=null;
		ListNode front=head;
		while(cur!=null){
			ListNode next=cur.next;
			cur.next=front;
			front=cur;
			cur=next;
		}
		return front;
	}
	public void interleave(ListNode h1,ListNode h2){
		ListNode cut=h1;
		while(cut!=null){
			if(cut.next!=null)
				if(cut.next.next==null)
					cut.next=null;
			cut=cut.next;
		}
		while(h1!=null & h2!=null){
			ListNode tmp1=h1;
			ListNode tmp2=h2;
			h1=h1.next;
			h2=h2.next;

			tmp1.next=tmp2;
			tmp2.next=h1;

		}
	}
	public void reorderList(ListNode head) {
		if(head==null)
			return;
		ListNode fast,slow;
		fast=head;
		slow=head;
		ListNode split_head=head;
		while(fast!=null){
			fast=move(fast,2);
			slow=move(slow,1);
			if(fast==null){
				split_head=slow;
				break;
			}
		}
		if(split_head!=head){
			split_head=reverse(split_head);
			interleave(head,split_head);
		}

	}
	/*public static void main(String [] args){
		Solution sol=new Solution();
		ListNode n1=new ListNode(1);
		ListNode n2=new ListNode(2);
		ListNode n3=new ListNode(3);
		ListNode n4=new ListNode(4);
		ListNode n5=new ListNode(5);
		ListNode n6=new ListNode(6);
		ListNode n7=new ListNode(7);
		n1.next=n2;
		n2.next=n3;
		n3.next=n4;
		n4.next=n5;
		n5.next=n6;
		//n6.next=n7;

		//sol.interleave(n1,n4);
		sol.reorderList(n1);
		ListNode head=n1;
		while(head!=null){
			System.out.println(head.val);
			head=head.next;
		}

	}*/
}
