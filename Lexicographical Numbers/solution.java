public class Solution {
    public List<Integer> lexicalOrder(int n) {
            List<Integer> res = new ArrayList<Integer>();
	            dfs(res,n,0);
		            return res;
			        }
				    public void dfs(List<Integer> res, int n, int cur){
				            int start = 0;
					            if(cur == 0)
						                start++;
								        for(;start<10;start++){
									            int num = cur *10 + start;
										                if(num>n)
												                return;
														            res.add(num);
															                dfs(res,n, num);
																	        }
																		    }
																		    }
