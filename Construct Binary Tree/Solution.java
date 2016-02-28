public class Solution {
	public TreeNode buildTree(int[] preorder, int[] inorder) {
		if(preorder.length==0)
			return null;
		return construct(preorder,0,inorder,0,inorder.length-1);
	
	}
	public TreeNode construct(int[] preorder,int midIndex, int[] inorder,int start,int end){
		if(start>end || midIndex>=preorder.length)
			return null;
		TreeNode newNode=new TreeNode(preorder[midIndex]);
		for(int i=start;i<=end;i++){
			if(inorder[i]==preorder[midIndex]){
			    //System.out.println(i);
				int leftLen=i-start;				
				newNode.left=construct(preorder,midIndex+1,inorder,start,i-1);
				newNode.right=construct(preorder,midIndex+leftLen+1,inorder,i+1,end);
				break;
			}
		}
		return newNode;
	}
}
