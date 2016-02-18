public class Codec {

	// Encodes a tree to a single string.
	public String serialize(TreeNode root) {
	    if(root==null)
	        return "";
		LinkedList<TreeNode> bfs=new LinkedList<TreeNode>();
		StringBuilder res=new StringBuilder();
		bfs.add(root);
		res.append(root.val+" ");
		while(!bfs.isEmpty()){
			TreeNode head=bfs.poll();
			//res.append(head.val+" ");
			if(head.left!=null){
				bfs.add(head.left);
			    res.append(head.left.val+" ");
			}
			else
				res.append("null ");
			
			if(head.right!=null){
				bfs.add(head.right);
			    res.append(head.right.val+" ");
			}
			else
				res.append("null ");
		}
		return res.toString().trim();
	}

	// Decodes your encoded data to tree.
	public TreeNode deserialize(String data) {
		LinkedList<TreeNode> bfs=new LinkedList<TreeNode>();
		String[] words=data.split("\\s+");
		//System.out.println(data);
		if(data.length()==0)
			return null;
		TreeNode root=new TreeNode(Integer.parseInt(words[0]));
		bfs.add(root);
		for(int i=1;i<words.length;i+=2){
			String left=words[i],right=words[i+1];
			TreeNode cur=bfs.poll();
			if(left.equals("null"))
				cur.left=null;
			else{
				TreeNode leftNode=new TreeNode(Integer.parseInt(left));
				cur.left=leftNode;
				bfs.add(leftNode);
			}
			if(right.equals("null"))
				cur.right=null;
			else{
				TreeNode rightNode =new TreeNode(Integer.parseInt(right));
				cur.right=rightNode;
				bfs.add(rightNode);
			}
		}
		return root;
	}
}

