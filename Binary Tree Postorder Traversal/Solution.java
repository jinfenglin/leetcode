import java.util.*;
class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}
public class Solution {
	public List<Integer> postorderTraversal(TreeNode root) {
		Stack<TreeNode> stk=new Stack<TreeNode>();
		List<Integer> res=new LinkedList<Integer>();
		if(root==null)
			return res;
		stk.push(root);
		while(!stk.empty()){
			TreeNode top= stk.peek();
			if(top.left==null & top.right==null){
				res.add(top.val);
				stk.pop();
			}else {
				if(top.right!=null){
					stk.push(top.right);
					top.right=null;
				}
				if(top.left!=null){
					stk.push(top.left);
					top.left=null;
				}
			}
		}
		return res;

	}
}
