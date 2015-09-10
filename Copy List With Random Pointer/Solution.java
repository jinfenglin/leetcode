class RandomListNode {
	int label;
	RandomListNode next, random;
	RandomListNode(int x) { this.label = x; }
};
public class Solution {
	public void insert(RandomListNode node){
		RandomListNode new_node=new RandomListNode(node.label);
		new_node.next=node.next;
		node.next=new_node;
	}
	public RandomListNode copyRandomList(RandomListNode head) {
		if(head==null)
			return null;
		RandomListNode cur=head;
		while(cur!=null){
			insert(cur);
			cur=cur.next;
			cur=cur.next;
		}
		RandomListNode res=head.next;
		cur=head;
		RandomListNode next=cur.next;
		while(next!=null){
			if(cur.random!=null)
				next.random=cur.random.next;
			else
				next.random=null;
			cur=next.next;
			if(cur==null)
				break;
			next=cur.next;
		}

		cur=head;
		next=cur.next;
		while(next!=null){
			cur.next=next.next;
			cur=next;
			if(cur==null)
				break;
			next=cur.next;
		}
		return res;
	}
	/*public static void main(String[] args){
		RandomListNode n1= new RandomListNode(1);
		RandomListNode n2= new RandomListNode(2);
		n1.next=n2;
		Solution sol=new Solution();
		RandomListNode head=sol.copyRandomList(n1);
		while(head!=null){
			System.out.println(head.label);
			head=head.next;
		}
		while(n1!=null){
			System.out.println(n1.label);
			n1=n1.next;
		}
	}*/
}
