c class Solution {
    public boolean isPalindrome(String s) {
            int start = 0, end =s.length()-1;
	            while(start<end){
		                while(start<end && !Character.isLetter(s.charAt(start)) && !Character.isDigit(s.charAt(start)))
				                start++;
						            while(start<end && !Character.isLetter(s.charAt(end)) && !Character.isDigit(s.charAt(end)))
							                    end--;
									                if(start<end)
											                if(Character.toLowerCase(s.charAt(start)) != Character.toLowerCase(s.charAt(end)))
													                    return false;
															                start++;
																	            end--;
																		            }
																			            return true;
																				        }
																					}
