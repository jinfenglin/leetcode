public class Solution {
	public int countNodes(TreeNode root) {
		if(root == null) 
			return 0;
		int l = getHeight(root.left);
		int r = getHeight(root.right);
		return l == r ? countNodes(root.right) + (1 << l + 1) : countNodes(root.left) + (1 << r + 1);
	}

	public int getHeight(TreeNode node){
		return node == null ? -1 : 1 + getHeight(node.left);
	}
}
