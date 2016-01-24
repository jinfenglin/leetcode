public class Solution {
	public boolean DFS(TreeNode root,long upper,long lower){
		boolean ans=true;
		if(root.val<upper && root.val>lower){
			if(root.left!=null){
				if(root.left.val<root.val)
					ans&=DFS(root.left,root.val,lower);
				else
					ans=false;
			}
			if(!ans)
				return false;
			if(root.right!=null){
				if(root.right.val>root.val)
					ans&=DFS(root.right,upper,root.val);
				else 
					ans=false;
			}
			return ans;
		}	
		return false;

	}
	
	public boolean isValidBST(TreeNode root) {
		if(root==null)
			return true;
		return DFS(root,Long.MAX_VALUE,Long.MIN_VALUE);
		
	}
}
