public class Solution {
    public int[][] generateMatrix(int n) {
            int[][] res = new int[n][n];
	            int i=0;
		            int num=1;
			            int len=n-1;
				            while(len>=0){
					                num=fillCircle(res,i,i,len,num);
							            i++;
								                len-=2;
										        }
											        return res;
												    }
												        public int fillCircle(int[][] matrix, int x, int y, int len, int num){
													        if(len==0){
														            matrix[x][y]=num++;
															                return num;
																	        }
																		        for(int i=0;i<len;i++){
																			            matrix[x][y+i] = num++;
																				            }
																					            for(int i=0;i<len;i++){
																						                matrix[x+i][y+len] = num++;
																								        }
																									        for(int i=0;i<len;i++){
																										            matrix[x+len][y+len-i] = num++;
																											            }
																												            for(int i=0;i<len;i++){
																													                matrix[x+len-i][y] = num++;
																															        }
																																        return num;
																																	    }
																																	    }
