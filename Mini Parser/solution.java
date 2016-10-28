c interface NestedInteger {
 *     // Constructor initializes an empty nested list.
  *     public NestedInteger();
   *
    *     // Constructor initializes a single integer.
     *     public NestedInteger(int value);
      *
       *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
        *     public boolean isInteger();
	 *
	  *     // @return the single integer that this NestedInteger holds, if it holds a single integer
	   *     // Return null if this NestedInteger holds a nested list
	    *     public Integer getInteger();
	     *
	      *     // Set this NestedInteger to hold a single integer.
	       *     public void setInteger(int value);
	        *
		 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
		  *     public void add(NestedInteger ni);
		   *
		    *     // @return the nested list that this NestedInteger holds, if it holds a nested list
		     *     // Return null if this NestedInteger holds a single integer
		      *     public List<NestedInteger> getList();
		       * }
		        */
			public class Solution {
			    public NestedInteger deserialize(String s) {
			            Stack<Object> stk = new Stack<Object>();
				            int num =0;
					            boolean onConstruct = false;
						            boolean isNegative = false;
							            if(s == null || s.length()==0)
								                return null;
										        if(!s.contains("["))
											            return new NestedInteger(Integer.valueOf(s));
												            for(int i=0;i<s.length();i++){
													                char curChar = s.charAt(i);
															            if(Character.isDigit(curChar)){
																                    num = num*10+curChar-'0';
																		                    onConstruct = true;
																				                }else if(curChar == '['){
																						                stk.push("[");
																								            }else if(curChar==']'){
																									                    if(isNegative)
																											                        num*=-1;
																														                if(onConstruct)
																																                    stk.push(new NestedInteger(num));
																																		                    num=0;
																																				                    onConstruct =false;
																																						                    isNegative = false;
																																								                    List<NestedInteger> tmp = new ArrayList<>();
																																										                    while(!(stk.peek() instanceof String)){
																																												                        tmp.add((NestedInteger)stk.pop());
																																															                }
																																																	                stk.pop();
																																																			                NestedInteger merge = new NestedInteger();
																																																					                for(int j=tmp.size()-1;j>=0;j--){
																																																							                    merge.add(tmp.get(j));
																																																									                    }
																																																											                    stk.push(merge);
																																																													                }else if(curChar=='-'){
																																																															                isNegative = true;
																																																																	            }else if(curChar ==','){
																																																																		                    if(isNegative)
																																																																				                        num*=-1;
																																																																							                if(onConstruct)
																																																																									                    stk.push(new NestedInteger(num));
																																																																											                    num=0;
																																																																													                    isNegative = false;
																																																																															                    onConstruct=false;
																																																																																	                }
																																																																																			        }
																																																																																				        return (NestedInteger)stk.pop();
																																																																																					    }
																																																																																					    }
