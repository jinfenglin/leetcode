public class Solution {
    public int countBattleships(char[][] board) {
            Set<Pair> visited = new HashSet<Pair>();
	            if(board.length ==0)
		                return 0;
				        int cnt=0;
					        for(int i=0;i<board.length;i++)
						            for(int j=0;j<board[0].length;j++){
							                    cnt +=DFS(board,i,j,visited);
									                }
											        return cnt;
												    }
												        public int DFS(char[][] board,int x,int y, Set<Pair> visited){
													        int x_limit=board.length;
														        int y_limit=board[0].length;
															        if(x<0 || x>=x_limit || y<0 || y>=y_limit)
																            return 0;
																	            Pair cur = new Pair(x,y);
																		            if(visited.contains(cur) || board[x][y]=='.')
																			                return 0;
																					        visited.add(cur);
																						        DFS(board,x+1,y,visited);
																							        DFS(board,x,y+1,visited);
																								        return 1;
																									    }
																									        class Pair {
																										        int x,y;
																											        public Pair(int x,int y){
																												            this.x=x;
																													                this.y=y;
																															        }
																																        
																																	        @Override
																																		        public boolean equals(Object p){
																																			            Pair op = (Pair)p;
																																				                return op.x == x && op.y == y;
																																						        }
																																							        @Override
																																								        public int hashCode() {
																																									            return x*1000 + y;
																																										            }
																																											        }
																																												}
