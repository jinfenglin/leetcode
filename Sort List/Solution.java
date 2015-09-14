class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}
public class Solution {
	public ListNode move(ListNode head,int step){
		while(head!=null & step>0){
			head=head.next;
			step--;
		}
		return head;
	}
	public ListNode merge(ListNode h1,ListNode h2,int len){
		ListNode tp=h1;
		ListNode tmp1,tmp2,head,tail;
		tmp1=h1;
		tmp2=h2;
		for(int i=1;i<len;i++){
			tmp1=tmp1.next;
			if(tmp2!=null)
				tmp2=tmp2.next;
		}
		if(tmp2!=null){
			tail=tmp2.next;
			tmp2.next=null;
		}
		else
			tail=null;
		tmp1.next=null;

		if(h1.val<=h2.val){
			head=h1;
			h1=h1.next;
		}else{
			ListNode tmp=new ListNode(h1.val);
			h1.val=h2.val;
			head=h1;
			h1=tmp;
			h1.next=head.next;
			h2=h2.next;
		}
		while(h1!=null & h2!=null){
			if(h1.val<=h2.val){
				head.next=h1;
				h1=h1.next;
			}else{
				head.next=h2;
				h2=h2.next;
			}
			head=head.next;
		}
		if(h1!=null)
			head.next=h1;
		else if(h2!=null)
			head.next=h2;
		while(head.next!=null)
			head=head.next;
		head.next=tail;
		return tail;

	}
	public ListNode sortList(ListNode head) {
		ListNode cur=head;
		int len=0;
		while(cur!=null){
			cur=cur.next;
			len++;
		}
		for(int i=1;i<=len;i*=2){
			ListNode h1,h2;
			h1=head;
			h2=move(head,i);
			while(h1!=null & h2!=null){
				h1=merge(h1,h2,i);
				h2=move(h1,i);
			}	
		}
		return head;
	}
	/*public static void main(String [] args){
		ListNode n1=new ListNode(4);
		ListNode n2=new ListNode(5);
		ListNode n3=new ListNode(1);
		ListNode n4=new ListNode(3);
		ListNode n5=new ListNode(2);
		ListNode n6=new ListNode(9);
		ListNode n7=new ListNode(1);

		n1.next=n2;
		n2.next=n3;
		n3.next=n4;
		n4.next=n5;
		n5.next=n6;
		n6.next=n7;
		Solution sol=new Solution();
		//ListNode head=n1;
		ListNode head=sol.sortList(n1);
		while(head!=null){
			System.out.println(head.val);
			head=head.next;
		}

	}*/
}
