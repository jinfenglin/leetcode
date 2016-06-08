c class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
            return treeConstructor(0,postorder.length-1,0,inorder.length-1,inorder,postorder);
	            
		        }
			    private TreeNode treeConstructor(int pstart,int pend, int start,int end,int[] inorder,int[] postorder){
			            if(start>end || pstart>pend)
				                return null;
						        if(pstart==pend)
							            return new TreeNode(postorder[pstart]);
								            int postVal= postorder[pend];
									            int i=start;
										            for(;i<=end;i++){
											                if(inorder[i]==postVal){
													                break;}
															        }
																        TreeNode curNode = new TreeNode(postVal);
																	        curNode.right= treeConstructor(pstart+i-start,pend-1,i+1,end,inorder,postorder);
																		        curNode.left= treeConstructor(pstart,pstart+i-start-1,start,i-1,inorder,postorder);
																			        return curNode;
																				    }
																				    } 
