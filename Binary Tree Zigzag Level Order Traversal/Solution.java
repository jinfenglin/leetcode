public class Solution {
	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		List<List<Integer>> res=new ArrayList<List<Integer>>();
		if(root==null)
			return res;
		List<TreeNode> queue= new ArrayList<TreeNode>();
		queue.add(root);
		int count=0;
		while(!queue.isEmpty()){
			List<TreeNode> next= new ArrayList<TreeNode>();
			List<Integer> part=new ArrayList<Integer>();
			for(int i=queue.size()-1;i>=0;i--){
				TreeNode curNode=queue.get(i);
				part.add(curNode.val);
				if(count%2==0){
					if(curNode.left!=null)
						next.add(curNode.left);
					if(curNode.right!=null)
						next.add(curNode.right);
				}else{
					if(curNode.right!=null)
						next.add(curNode.right);
					if(curNode.left!=null)
						next.add(curNode.left);
				}
			}
			queue=next;
			res.add(part);
			count++;
		}
		return res;
	}
}
