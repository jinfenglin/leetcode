class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}
public class Solution {
	public ListNode insertionSortList(ListNode head) {
		if(head==null)
			return null;
		ListNode cur=head;
		ListNode bar=head;
		ListNode insert_element=bar.next;
		while(insert_element!=null){
			cur=head;
			if(insert_element.val<cur.val){
				bar.next=insert_element.next;
				insert_element.next=cur;
				if(cur==head)
					head=insert_element;
				insert_element=bar.next;
				continue;
			}
			while(cur!=bar){
				if(insert_element.val<=cur.next.val & insert_element.val>=cur.val){
					bar.next=insert_element.next;
					insert_element.next=cur.next;
					cur.next=insert_element;
					insert_element=bar.next;
					break;
				}
				cur=cur.next;
			}
			if(cur==bar)
			{
				bar=bar.next;
				if(bar!=null)
					insert_element=bar.next;
			}

		}
		return head;
	}
	/*public static void main(String [] args){
		ListNode n1 =new ListNode(7);
		ListNode n2 =new ListNode(4);
		ListNode n3 =new ListNode(2);
		ListNode n4 =new ListNode(6);
		ListNode n5 =new ListNode(1);
		ListNode n6 =new ListNode(1);
		ListNode n7 =new ListNode(1);
		n1.next=n2;
		n2.next=n3;
		n3.next=n4;
		n4.next=n5;
		n5.next=n6;
		n6.next=n7;
		Solution sol=new Solution();
		ListNode head=sol.insertionSortList(n1);
		while(head!=null){
			System.out.println(head.val);
			head=head.next;
		}

	}*/

}
