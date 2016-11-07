c class MinStack {

    /** initialize your data structure here. */
        List<Integer> stack;
	    int min;
	        public MinStack() {
		        stack = new LinkedList<Integer>();
			        min = Integer.MAX_VALUE;
				    }
				        
					    public void push(int x) {
					            stack.add(0,x);
						            if(x < min)
							                min = x;
									    }
									        
										    public void pop() {
										            int top = top();
											            stack.remove(0);
												            int tmp_min = Integer.MAX_VALUE;
													            if(top==min){
														                for(int i=0;i<stack.size();i++){
																                tmp_min=stack.get(i)<tmp_min?stack.get(i):tmp_min;
																		            }
																			                min = tmp_min;
																					        }
																						            
																							        }
																								    
																								        public int top() {
																									        return stack.get(0);
																										    }
																										        
																											    public int getMin() {
																											            return min;
																												        }
																													}
