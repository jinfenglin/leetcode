public class Solution {
	public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
		if(root==p || root==q)
			return root;
		boolean left=findNode(root.left,p);
		boolean right=findNode(root.right,q);
		if(left && right|| !left && !right)
			return root;
		else if(left){
			return lowestCommonAncestor(root.left,p,q);
		}else if(right){
			return lowestCommonAncestor(root.right,p,q);
		}else
			return null ;
	}
	public boolean findNode(TreeNode cur,TreeNode p){
		if(cur==null)
			return false;
		if(cur==p)
			return true;
		if(findNode(cur.left,p) || findNode(cur.right,p))
			return true;
		return false;
	}
}
