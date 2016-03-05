public class Solution {
	public List<TreeNode> generateTrees(int n) {
		boolean[] nums=new boolean[n+1];
		List<TreeNode>res= new ArrayList<TreeNode>();
		if(n==0)
		    return res;
		res=generate(nums,1,n);
		return res;
		
	}
	public List<TreeNode> generate(boolean[] nums,int start,int end){
		List<TreeNode> res=new ArrayList<TreeNode>();
		if(start>end){
			res.add(null);
			return res;
		}
		for(int i=start;i<=end;i++){
			if(!nums[i]){
				nums[i]=true;
				List<TreeNode> left= generate(nums,start,i-1);
				List<TreeNode> right= generate(nums,i+1,end);
				for(TreeNode leftNode:left){
					for(TreeNode rightNode:right){
						TreeNode newNode=new TreeNode(i);
						newNode.left=leftNode;
						newNode.right=rightNode;
						res.add(newNode);
					}
				}
				nums[i]=false;
			}
		}
		return res;
	}
}

