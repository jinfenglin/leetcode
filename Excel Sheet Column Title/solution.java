c String convertToTitle(int n) {
        StringBuilder sb = new StringBuilder();
	        while(n>0){
		            int mod = n%26-1;
			                n = n/26;
					            if(mod <0){
						                    mod = 25;
								                    n--;
										                }
												            char cur = (char)( mod +'A');
													                sb.append(cur);
															        }
																        return sb.reverse().toString();
																	    }
																	    }
