public class Solution {
	public List<List<Integer>> pathSum(TreeNode root, int sum) {
		List<List<Integer>> res=new List<List<Integer>>();
		if(root==null)
			return res;
		List<Integer> sol=new List<Integer>();
		DFS(root,0,sum,sol,res);
		return res;

	}
	public void DFS(TreeNode root,int cur,int sum,List<Integer> sol,List<List<Integer>> res){
		cur+=root.val;
		if(cur>=sum){
			if(cur=sum)
				sol.add(root.val);
			return ;
		}
		if(root.left!=null){
			DFS(root.left,cur,sum,sol,res);
		}
		if(root.right!=null){
			DFS(root.left,cur,sum,sol,res);
		}
		sol.remove(sol.size()-1);
	}
}
