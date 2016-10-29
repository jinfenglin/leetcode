c class Solution {
    public int compareVersion(String version1, String version2) {
            String[] v1 = version1.split("\\.");
	            String[] v2 = version2.split("\\.");
		            for(int i=0;i<Math.max(v1.length,v2.length);i++){
			                int i1, i2;
					            if(i<v1.length)
						                    i1=Integer.valueOf(v1[i]);
								                else 
										                i1=0;
												            if(i<v2.length)
													                    i2=Integer.valueOf(v2[i]);
															                else
																	                i2=0;
																			            if(i1>i2)
																				                    return 1;
																						                else if(i1<i2)
																								                return -1;
																										        }
																											        return 0;
																												    }
																												    }
