c class Solution {
    public int myAtoi(String str) {
            int num = 0;
	            boolean isNegative = false;
		            int i=0;
			            while(i< str.length() && str.charAt(i)==' ')
				                i++;
						        if(i==str.length())
							            return 0;
								            if(str.charAt(i) == '-'){
									                isNegative = true;
											            i++;
												            }else if(str.charAt(i)== '+')
													                i++;
															            
																            for(;i<str.length();i++){
																	                char cur = str.charAt(i);
																			            if(Character.isDigit(cur)){
																				                    if(isNegative){
																						                        if(cur=='0' && num>(Integer.MAX_VALUE-cur+'0')/10)
																									                        return Integer.MIN_VALUE;
																												                    else if(cur>'0' && num>(Integer.MAX_VALUE-cur+'0'+1)/10)
																														                            return Integer.MIN_VALUE;
																																	                        num = num*10+cur-'0';
																																				                }
																																						                else if(!isNegative && num>(Integer.MAX_VALUE-cur+'0')/10)
																																								                    return Integer.MAX_VALUE;
																																										                    else
																																												                        num = num*10+cur-'0';
																																															            }else{
																																																                    break;
																																																		                }
																																																				        }
																																																					        return isNegative? -num:num;
																																																						    }
																																																						    }
