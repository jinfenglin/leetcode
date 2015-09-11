import java.util.*;
class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }
public class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
	    List<Integer> res=new LinkedList<Integer>();
	    if(root==null)
		    return res;
	    res.add(root.val);
	    res.addAll(preorderTraversal(root.left));
	    res.addAll(preorderTraversal(root.right));
	    return res;
    }
}
