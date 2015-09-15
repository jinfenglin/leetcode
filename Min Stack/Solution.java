class MinStack {
	class ListNode{
		public int val;
		public ListNode next;
		ListNode(int val){
			this.val=val;
			this.next=null;
		}
	}
	public ListNode stk;
	public ListNode min_val;
	MinStack(){
		stk=null;
		min_val=null;
	}
	public void push(int x) {
		if(stk==null)
		{
			stk=new ListNode(x);
			min_val= new ListNode(x);
		}
		else{
			ListNode tmp;
			if(x<min_val.val){
				tmp=new ListNode(x);
				tmp.next=min_val;
				min_val=tmp;
			}else{
				tmp=new ListNode(min_val.val);
				tmp.next=min_val;
				min_val=tmp;
			}
			
			tmp=new ListNode(x);
			tmp.next=stk;
			stk=tmp;

			
		}
	}

	public void pop() {
		stk=stk.next;
		min_val=min_val.next;
	}

	public int top() {
		return stk.val;

	}

	public int getMin() {
		return min_val.val;
	}
}

