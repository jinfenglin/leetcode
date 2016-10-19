c class Solution {
    public void rotate(int[][] matrix) {
            rotate(matrix,0,0,matrix.length-1);
	        }
		    public void rotate(int[][] matrix,int x,int y, int len){
		            if(len <= 0)
			                return ;
					        for(int i=0;i<len;i++){
						            int tmp = matrix[x][y+i];
							                matrix[x][y+i] = matrix[x+len-i][y];
									            matrix[x+len-i][y] = matrix[x+len][y+len-i];
										                matrix[x+len][y+len-i] = matrix[x+i][y+len];
												            matrix[x+i][y+len] = tmp;
													            }
														            rotate(matrix,x+1,y+1,len-2);
															        }
																}
