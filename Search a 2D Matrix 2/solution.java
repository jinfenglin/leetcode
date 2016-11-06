c class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
            int m = matrix.length;
	            if(m==0)
		                return false;
				        int n = matrix[0].length;
					        int i=0;
						        int j=n-1;
							        while(i<m && j>=0){
								            if(target>matrix[i][j])
									                    i++;
											                else if(target<matrix[i][j])
													                j--;
															            else
																                    return true;
																		            }
																			            return false;
																				        }
																					}
