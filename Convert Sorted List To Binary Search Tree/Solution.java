public class Solution {
	static ListNode cur;
    public TreeNode sortedListToBST(ListNode head) {
        ListNode ptr= head;
	int count=0;
	while(ptr!=null){
		ptr=ptr.next;
		count++;
	}
	cur=head;
	return helper(0,count-1);
    }
    public TreeNode helper(int low,int high){
	    if(low>high)
		    return null;
	    int mid=low+(high-low)/2;
	    TreeNode left_head=helper(low,mid-1);
	    TreeNode header= new TreeNode(cur.val);
	    cur=cur.next;
	    TreeNode right_head=helper(mid+1,high);
	    header.left=left_head;
	    header.right=right_head;
	    return header;
    }
}
